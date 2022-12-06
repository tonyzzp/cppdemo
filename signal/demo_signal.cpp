#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <thread>

int main()
{

    auto onsig = [](int sig) -> void
    {
        printf("onsig: %d\n", sig);
        exit(0);
    };

    signal(SIGABRT, onsig);
    signal(SIGFPE, onsig);
    signal(SIGILL, onsig);
    signal(SIGINT, onsig);
    signal(SIGSEGV, onsig);
    signal(SIGTERM, onsig);

    printf("press ctrl+c to interrupt\n");

    int i = 0;
    while (true)
    {
        printf("%d\n", ++i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (i == 3)
        {
            raise(SIGTERM);
        }
    }

    return 0;
}