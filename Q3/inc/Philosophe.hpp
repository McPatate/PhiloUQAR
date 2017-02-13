/*
 * Copyright (C) 2017  Bastien Penavayre
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#include <unistd.h>

class Philosopher
{
    enum e_states {
        thinking,
        hungry,
        eating
    };

    static e_states states[constants::n];
    static Semaphore s[constants::n];
    static std::mutex critical;
    
    int _id;

    inline char stateChar(int index) const
    {
        switch(states[index])
        {
        case thinking:
            return 'R';
        case hungry:
            return 'A';
        case eating:
            return 'M';
        }
    }

    inline void pushUpdate() const
    {
        std::string tmp(9, '-');

        for (int i = 0; i < constants::n; i++)
            tmp[i * 2] = stateChar(i);
        SafeQueue::push(tmp);
    }

public:
    inline Philosopher(int id) : _id(id) {}
    
    inline void operator()() const
    {
        for (int i = 0; i < 10; i++)
        {
            think();
            takeForks();
            eat();
            putForks();
        }
    }

    inline void takeForks() const
    {
        {
            std::unique_lock<std::mutex> lock(critical);
            states[_id] = hungry;
            pushUpdate();
            test();
        }
        s[_id].wait();
    }

    inline void think() const { sleep(1); }
    inline void eat() const { sleep(1); }

    inline void putForks() const
    {
        std::unique_lock<std::mutex> lock(critical);
        states[_id] = thinking;
        pushUpdate();
        test(constants::left(_id));
        test(constants::right(_id));
    }

    inline void test() const { test(_id); }

    inline void test(int id) const
    {
        if (states[id] == hungry && states[constants::left(id)] != eating &&
            states[constants::right(id)] != eating) {
            states[id] = eating;
            pushUpdate();
            s[id].post();
        }
    }
};
