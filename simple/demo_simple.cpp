#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "help.h"

typedef struct Person
{
    char name[20];
    int age;
    char city[50];
} Person;

int main()
{
    SetConsoleOutputUtf8();

    printf("sizeof(char): %ld\n", sizeof(char));

    Person p;
    memcpy(p.name, "zzp", 4);
    strcpy(p.city, "襄樊");
    p.age = 18;
    printf("name: %s, age: %d, city: %s\n", p.name, p.age, p.city);

    Person *ps = (Person *)malloc(sizeof(Person) * 5);
    for (size_t i = 0; i < 5; i++)
    {
        ps[i] = p;
        ps[i].age = i + 1;
    }

    for (size_t i = 0; i < 5; i++)
    {
        Person p = ps[i];
        printf("%ld: sizeof(p)=%ld, age=%d\n", i, sizeof(p), p.age);
    }

    return 0;
}