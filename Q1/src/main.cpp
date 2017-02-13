#include <common.hpp>
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

public:
    Philosopher(int id) : _id(id) {}
    
    void operator()() const
    {
        for (int i = 0; i < 10; i++)
        {
            think();
            takeForks();
            eat();
            putForks();
        }
    }

    void takeForks() const
    {
        {
            std::unique_lock<std::mutex> lock(critical);
            states[_id] = hungry;
            test();
        }
        s[_id].wait();
    }

    void think() const
    {
        sleep(1);
    }

    void eat() const
    {
        sleep(1);
    }

    void putForks() const
    {
        std::unique_lock<std::mutex> lock(critical);
        states[_id] = thinking;
        test(constants::left(_id));
        test(constants::right(_id));
    }

    void test() const { test(_id); }

    void test(int id) const
    {
        if (states[id] == hungry && states[constants::left(id)] != eating &&
            states[constants::right(id)] != eating) {
            states[id] = eating;
            s[id].post();
        }
    }
};

Philosopher::e_states Philosopher::states[constants::n];
Semaphore Philosopher::s[constants::n];
std::mutex Philosopher::critical;

int main()
{
    std::thread tmp[5];
    
    for (int i = 0; i < 5; i++)
        tmp[i] = std::thread(Philosopher(i));
    for (int i = 0; i < 5; i++)
        tmp[i].join();
    return 0;
}
