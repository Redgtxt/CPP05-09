#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/*
Templates nao sao codigo real!!
Sao instruçoes para o amigo compilador, quando o compilador ve uma template a ser usada ele perceber o que a funçao faz e vai gerar uma versao real da funcao que use o data type que se quer.
*/

template <typename T>
void swap(T &val1,T &val2)
{
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template <typename T>
T min(T val1,T val2)
{
    if(val1 == val2)
        return val2;
    else if(val1 > val2)
        return val2;
    else
        return val1;
}
template <typename T>
T max(T val1,T val2)
{
    if(val1 == val2)
        return val2;
    else if(val1 > val2)
        return val1;
    else
        return val2;
}



#endif