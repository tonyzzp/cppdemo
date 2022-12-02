#include <iostream>
#include <thread>

int main()
{
    auto fun1 = [](int v) -> void
    {
        std::cout << "fun1.run" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << i << std::endl;
            _sleep(500);
        }
        std::cout << "fun1.end" << std::endl;
    };
    std::thread t1(fun1, 123);
    t1.join();

    return 0;
}