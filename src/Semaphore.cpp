#include <Semaphore.hh>

Semaphore::Semaphore(unsigned number) { sem_init(&_handle, number); }

void Semaphore::wait() { sem_wait(&_handle); }

bool Semaphore::trywait() { return (sem_wait(&_handle) != EAGAIN); }

void Semaphore::post() { sem_post(&_handle); }

int Semaphore::operator*() const {
    int res;
    sem_getvalue(&_handle, &res);
    return res;
}
