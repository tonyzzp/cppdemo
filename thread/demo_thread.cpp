#include <iostream>
#include <thread>
#include <stdlib.h>
#include <memory>
#include <memory.h>

int main()
{
    auto fun1 = [](int v) -> void
    {
        std::cout << "fun1.run" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << "fun1:" << i << std::endl;
            _sleep(500);
        }
        std::cout << "fun1.end" << std::endl;
    };
    std::thread t1(fun1, 123);

    pthread_t t2 = 0;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    auto fun2 = [](void *p) -> void *
    {
        std::cout << "fun2.run" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << "fun2:" << i << std::endl;
            _sleep(500);
        }
        std::cout << "fun2.end" << std::endl;
        return NULL;
    };
    pthread_create(&t2, &attr, fun2, NULL);

    t1.join();
    pthread_join(t2, NULL);

    return 0;
}