#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>

struct Data
{
    int num;
};

/*
uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.
*/

/*
    static_cast:
    usado para fazer conversoes seguras entre data types ou classes

    dynamic_cast:
    usado em conversao entre ponteiros/referencias ou quando se esta a usar classes bases para classes derivadas (polimorfismo)
    Corre em runtime.

    const_cast:
    Usado para adicionar/retirar const de uma variavel

    reinterpret_cast:
    Vai fazer a Reinterpretação bruta dos bits.Pode ser perigoso se for mal feito
*/

class Serializer
{
private:   
    Serializer();
    Serializer& operator=(const Serializer& other);
    Serializer(const Serializer &obj);
    ~Serializer();

public:
    uintptr_t serialize(Data* ptr);

    //It takes an unsigned integer parameter and converts it to a pointer to Data.
    Data* deserialize(uintptr_t raw);
};





#endif