#include <vector>
#include <exception>
#include <iostream>

template <class T>
class Queue
{
private:
    std::vector<T> v;

public:
    void push(T t)
    {
        v.push_back(t);
    }

    T pop()
    {
        if (v.empty())
        {
            throw std::out_of_range("stack is empty");
        }
        auto rtn = v[0];
        v.erase(v.begin());
        return rtn;
    }

    void clear()
    {
        v.clear();
    }
};

int main()
{
    Queue<const char *> q;
    q.push("aaa");
    q.push("bbb");
    std::cout << "pop:" << q.pop() << std::endl;
    q.push("ccc");
    std::cout << "pop:" << q.pop() << std::endl;
    std::cout << "pop:" << q.pop() << std::endl;
    try
    {

        std::cout << "pop:" << q.pop() << std::endl;
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}