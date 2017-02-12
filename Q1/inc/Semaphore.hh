#pragma once

#include <semaphore.h>
#include <errno.h>

class Semaphore
{
    sem_t _handle;

public:
    Semaphore(unsigned number = 0);
    void wait();
    bool trywait();
    int operator*();
    void post();
};
