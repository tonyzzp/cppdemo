#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Creature
{
private:
    const char *type;
    char *chars;

public:
    static int count;
    static void printCount()
    {
        printf("Creature.count: %d\n", count);
    }

public:
    Creature(const char *type) : type(type)
    {
        Creature::count++;
        chars = (char *)malloc(10);
    }

    Creature(const Creature &other)
    {
        Creature::count++;
        printf("copy constructor\n");
        chars = (char *)malloc(10);
        setChars(other.chars);
    }

    ~Creature()
    {
        Creature::count--;
        printf("~Creature\n");
    }

    const char *getType()
    {
        return this->type;
    }

    void hello();
    void speek(const char *msg);
    int age();
    void setChars(const char *content);
};

void Creature::hello()
{
    printf("Creature.hello(), chars:%p\n", chars);
    if (chars)
    {
        printf("%s\n", chars);
    }
};

void Creature::speek(const char *msg)
{
    printf("Creature.speek:%s\n", msg);
};

int Creature::age()
{
    return 0;
}

void Creature::setChars(const char *content)
{
    strncpy(chars, content, 10);
}

int Creature::count = 0;
