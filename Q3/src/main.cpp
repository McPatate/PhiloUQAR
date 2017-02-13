#include <common.hpp>
#include <sys/types.h>
#include <sys/wait.h>

int main(int, char **, char *const env[])
{
    std::thread tmp[5];
    
    for (int i = 0; i < 5; i++)
        tmp[i] = std::thread(Philosopher(i));
    while (true)
    {
        std::string tmp = SafeQueue::pop();
        const char * str = tmp.c_str();
        pid_t pid;
        int status;
        
        if((pid = fork()) == 0) {
            char * const args[3] = {(char *)"./impression", const_cast<char * const>(str), NULL};
            execve("./impression", args, env);
            exit(42);
        }
        else
            waitpid(pid, &status, 0);
    }
}

Philosopher::e_states Philosopher::states[constants::n];
Semaphore Philosopher::s[constants::n];
std::mutex Philosopher::critical;
SafeQueue SafeQueue::instance;
