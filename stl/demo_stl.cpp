#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

int main()
{
    {
        std::cout << "---vector\n";
        std::vector<std::string> v;

        auto printInfo = [&v]() -> void
        {
            std::cout << "cap:" << v.capacity() << "\n";
            std::cout << "size:" << v.size() << "\n";
            std::cout << "max_size:" << v.max_size() << "\n";
            std::cout << "begin:" << v.begin().base() << "\n";
            std::cout << "end:" << v.end().base() << "\n";
        };

        printInfo();

        std::cout << "--insert content\n";
        v.push_back("hello");
        v.push_back("word");
        v.push_back("ruok");
        printInfo();

        std::cout << "--foreach\n";
        for (auto it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << "\n";
        }

        std::cout << "--for iv\n";
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << "\n";
        }

        std::cout << "--data\n";
        auto data = v.data();
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << data[i] << "\n";
        }
    }

    {

        std::cout << "map\n";
        std::map<std::string, int> m;
        m["b"] = 2;
        m["a"] = 1;
        m["z"] = 10;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            std::cout << it->first << " , " << it->second << "\n";
        }

        std::cout << "unordered_map\n";
        std::unordered_map<std::string, int> m2(m.begin(), m.end());
        m2["c"] = 3;
        for (auto it = m2.begin(); it != m2.end(); it++)
        {
            std::cout << it->first << " , " << it->second << "\n";
        }
    }

    return 0;
}