#include <common.hpp>

int main(int, char **, char * const env[])
{
    for (int i = 0; i < 101; i++)
        SafeQueue::push("Une chaine de charactère quelconque");
    for (int i = 0; i < 100; i++)
    {
        std::string tmp = SafeQueue::pop();
        const char *str = tmp.c_str();
        pid_t pid;
        int status;

        if ((pid = fork()) == 0) {
            char * const args[3] = {(char *)"./impression", const_cast<char * const>(str), NULL};
            execve("./impression", args, env);            
        }
        else
            waitpid(pid, &status, 0);
    }
    return 0;
}
