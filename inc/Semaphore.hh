#pragma once

#include <semaphore.h>
#include <errno.h>

class Semaphore
{
    sem_t _handle;

public:
    Semaphore(unsigned number);
    void wait();
    bool trywait();
    int operator*() const;
    void post();
};
