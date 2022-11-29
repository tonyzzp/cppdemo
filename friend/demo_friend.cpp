#include <stdlib.h>
#include <iostream>
#include <stdio.h>

// class People;

class Box
{
private:
    int size;

public:
    Box(int size);
    friend void showBox(Box &box);
    friend class People;
};

Box::Box(int size)
{
    this->size = size;
}

void showBox(Box &box)
{
    printf("showBox:%d\n", box.size);
}

class People
{
public:
    void show(Box &box)
    {
        printf("People.show:%d\n", box.size);
    }
};

int main()
{
    Box box(30);
    
    showBox(box);

    People p;
    p.show(box);
    return 0;
}