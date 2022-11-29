#include "creature.h"
#include <iostream>

int main()
{

    {
        printf("----------------\n");
        auto c = new Creature("newcreature");
        c->setChars("zzp");
        c->hello();
        c->speek("...");
        std::cout << c->age() << std::endl;
        Creature::printCount();
        delete c;
        Creature::printCount();
    }

    printf("----------------\n");
    auto c = Creature("default_type");
    c.setChars("abc");
    c.hello();
    c.speek("ruok");
    std::cout << "type:" << c.getType() << std::endl;
    std::cout << "age:" << c.age() << std::endl;
    Creature::printCount();

    printf("----------------\n");
    auto cp1 = Creature(c);
    cp1.hello();
    Creature::printCount();

    printf("----------------\n");
    auto cp2 = c;
    cp2.hello();
    Creature::printCount();

    printf("-------------end\n");
    return 0;
}