#include <stdio.h>
#include <stdlib.h>

class Box
{
private:
    char *arr;

public:
    Box()
    {
        arr = (char *)malloc(1024 * 1024);
        printf("Box()\n");
    }

    ~Box()
    {
        free(arr);
        printf("~Box()\n");
    }
};

int main()
{
    {
        printf("-------single\n");
        Box *box = new Box;
        delete box;
    }

    {
        printf("-------array\n");
        Box *boxes = new Box[5];
        delete[] boxes;
    }

    {
        printf("-------**\n");
        auto boxes = new Box *[5];
        for (int i = 0; i < 5; i++)
        {
            boxes[i] = new Box;
        }

        for (int i = 0; i < 5; i++)
        {
            delete boxes[i];
        }
    }

    return 0;
}