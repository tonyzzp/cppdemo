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
    Creature(const char *type) : type(type)
    {
        chars = (char *)malloc(10);
    }

    Creature(const Creature &other)
    {
        printf("copy constructor\n");
        chars = (char *)malloc(10);
        setChars(other.chars);
    }

    ~Creature()
    {
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