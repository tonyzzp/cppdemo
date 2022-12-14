#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

int main()
{
    std::cout << "pwd:" << fs::current_path() << "\n";
    auto root = fs::current_path().append("test_dir");
    std::cout << "test_dir:" << root << "\n";
    root = fs::absolute(root);
    std::cout << "absolute:" << root << "\n";

    std::error_code code;
    if (fs::exists(root, code))
    {
        std::cout << "目录已存在\n";
    }
    else
    {
        std::cout << "目录不存在:" << code.message() << "\n";
        if (fs::create_directories(root, code))
        {
            std::cout << "创建目录成功\n";
        }
        else
        {
            std::cout << "创建目录失败:" << code.message() << "\n";
        }
    }

    std::cout << "filename:" << root.filename() << "\n";
    std::cout << "parent:" << root.parent_path() << "\n";
    std::cout << "extension:" << root.extension() << "\n";
    std::cout << "relative:" << root.relative_path() << "\n";
    std::cout << "rootName:" << root.root_name() << "\n";
    std::cout << "rootPath:" << root.root_path() << "\n";
    std::cout << "rootDirectory:" << root.root_directory() << "\n";
    std::cout << "isEmpty:" << root.empty() << "\n";
    std::cout << "is_relative:" << root.is_relative() << "\n";
    std::cout << "is_absolute:" << root.is_absolute() << "\n";
    std::cout << "isDirectory:" << fs::is_directory(root) << "\n";

    {
        auto dir = root.parent_path();
        std::cout << "----------遍历build:" << dir << "\n";
        for (auto it = fs::directory_iterator(dir); it != fs::end(it); it++)
        {
            auto entry = *it;
            std::cout << entry.path() << "\n";
        }
    }

    {
        auto dir = root.parent_path();
        std::cout << "----------resursive遍历build:" << dir << "\n";
        for (auto it = fs::recursive_directory_iterator(dir); it != fs::end(it); it++)
        {
            std::cout << (*it).path() << "\n";
        }
    }

    return 0;
}