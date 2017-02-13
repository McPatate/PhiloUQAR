#include <common.hpp>

void thread_popup()
{
    std::string res = SafeQueue::pop();
    std::cout << res << std::endl;
}

int main()
{
    std::thread tmp[5];
    
    for (int i = 0; i < 5; i++)
        tmp[i] = std::thread(Philosopher(i));
    while (true)
        std::thread(thread_popup).join();
    return 0;
}

Philosopher::e_states Philosopher::states[constants::n];
Semaphore Philosopher::s[constants::n];
std::mutex Philosopher::critical;
SafeQueue SafeQueue::instance;
