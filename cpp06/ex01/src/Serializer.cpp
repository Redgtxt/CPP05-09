#include "Serializer.hpp"


Serializer::Serializer()
{
}


uintptr_t   Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*    Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}


Serializer::Serializer(const Serializer &obj)
{
    std::cout << "Serializer Copy constructor called" << std::endl;
    *this = obj;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    std::cout << "Copy assignment Serializer operator called" << std::endl;

    if(this != &other)
    {
        (void)other;
    }
    return *this;
}

Serializer::~Serializer()
{
}