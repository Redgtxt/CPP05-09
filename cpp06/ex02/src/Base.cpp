#include "Base.hpp"
#include "Class.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    int i = rand() % 3;

    Base *base = NULL;
    switch (i)
    {
    case 0:
        base = new A();
        break;
    case 1:
        base = new B();
        break;
    case 2:
        base = new C();
        break;
    default:
    std::cout << "Something went wrong generating class" << std::endl;
    break;
    }

    return base;
}

void identify(Base* p)
{

    if(dynamic_cast<A *>(p))
        std::cout << "Objec type A"<< std::endl;
    else if( dynamic_cast<B *>(p))
        std::cout << "Objec type B"<< std::endl;
    else if(dynamic_cast<C *>(p))
        std::cout << "Objec type C"<< std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "The class is 'A'" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "The class is 'B'" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "The class is 'C'" << std::endl;
    }
    catch (std::exception &e)
    {
    }
}
