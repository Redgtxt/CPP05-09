#include "Base.hpp"
#include "Class.hpp"


Base::~Base()
{
}


Base *generate(void)
{
    int i = rand() % 3;

    
    switch (i)
    {
    case 1:
        new A();
        break;
    case 2:
        new B();
        break;
    case 3:
        new C();
        break;
    default:
        break;
    }
}