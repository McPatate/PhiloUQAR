#include <common.hpp>

void thread_popup()
{
    std::string res = SafeQueue::pop();
    std::cout << res << std::endl;
}

int main()
{
    for (int i = 0; i < 101; i++)
        SafeQueue::push("Une chaine de charactère quelconque");
    for (int i = 0; i < 100; i++)
        std::thread(thread_popup).join();
    return 0;
}
