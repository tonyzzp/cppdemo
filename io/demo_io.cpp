#include "help.h"
#include <iostream>
#include <fstream>

const char *LINE = "----------------------------------------------------------------";

int main()
{
    SetConsoleOutputDefault();
    std::cout << "hello std::cout" << std::endl;
    std::cout << "sizeof(wchar_t)=" << sizeof(wchar_t) << std::endl;

    std::cout << "请输入姓名" << std::endl;
    char name[50];
    std::cin >> name;

    std::cout << "请输入年龄" << std::endl;
    int age = 0;
    std::cin >> age;

    std::cout << "你的姓名:" << name << std::endl;
    std::cout << "你的年龄:" << age << std::endl;

    std::cout << LINE << std::endl;
    std::cout << "test read file" << std::endl;
    std::ifstream fin;
    fin.open("test.txt", std::ios::in);
    if (fin.fail())
    {
        std::cout << "open file failed" << std::endl;
    }
    else
    {
        char line[1000];
        while (true)
        {
            fin.getline(line, 1000);
            if (fin.fail())
            {
                std::cout << "read complete" << std::endl;
                break;
            }
            std::cout << line << std::endl;
        }
        fin.close();
    }

    std::cout << LINE << std::endl;
    std::cout << "test wirte file" << std::endl;
    std::ofstream fout;
    fout.open("test.txt", std::ios::out | std::ios::trunc);
    if (fout.fail())
    {
        std::cout << "create file failed" << std::endl;
    }
    else
    {
        fout << "line1: 你好啊\n";
        fout << "line2: hello";
        fout.close();
        if (fout.fail())
        {
            std::cout << "write file failed";
        }
        else
        {
            std::cout << "write file success";
        }
    }

    return 0;
}