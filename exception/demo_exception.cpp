#include <exception>
#include <iostream>
#include <random>
#include <stdexcept>
#include <time.h>

const int C = floor(RAND_MAX * 0.9);

static int number()
{
    auto r = rand();
    if (r > C)
    {
        throw std::out_of_range("outofrange");
    }
    return r;
}

int main()
{
    srand(time(0));
    while (true)
    {
        try
        {
            auto r = number();
            std::cout << r << std::endl;
        }
        catch (std::out_of_range e)
        {
            std::cout << e.what() << std::endl;
            break;
        }
    }
    return 0;
}