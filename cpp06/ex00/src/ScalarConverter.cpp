#include "ScalarConverter.hpp"

//Void 
ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default Constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    
    std::cout << "Copy assignment ScalarConverter operator called" << std::endl;

    if(this != &other)
        (void)other;
    
    return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    std::cout << "ScalarConverter Copy constructor called" << std::endl;
    *this = obj;
}

/*
Dar handle a estes data types

    [] char
    [] int
    [] float
    [] double

    //Tirando chars devo usar decimal notation

    //Nao devo contar com Inputs que sejam non-dysplayable characters


    FLOAT
    "You have to handle these pseudo-literals as well (you know, for science): -inff, +inff,
and nanf."

    DOUBLE
    "Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and
nan."
*/


//Indentificador 
/*
    Primeiro vou verificar por um float

    //Sinal tem de estar na posiçao 0
*/

int ScalarConverter::CountSign(char sign,const std::string &str)
{
    int contador = 0;
    size_t pos = 0;

    //Vou procurar pela quantidade de sinais que tenho da minha str
    while ((pos = str.find(sign,pos)) != std::string::npos)
    {
        contador++;
        pos++;
    }

    //So posso ter um sinal
    if(contador > 1)
    {
        return -1;
    }

    return contador;
}
int ScalarConverter::CheckPositionofSign(int sign,char symbol,const std::string &str)
{
    if(sign)
    {
        if(str.find(symbol) == 0)
        {
            std::cout << "O sinal de " << symbol << "esta na primeira posicao yupiii" << std::endl;
            return 0;
        }else{
            return -1;
        }
    }
    return 0;
}

int ScalarConverter::IndentifyType(const std::string &str)
{

    int plusSignAmount = CountSign('+',str);
    int subSignAmount = CountSign('-',str);

    if(plusSignAmount == -1 || subSignAmount == -1)
    {
        std::cout << "Tenho mais do que um sinal" << std::endl;
        return -1;
    }

    //Verifico se o sinal esta na primeira posiçao
    if(CheckPositionofSign(plusSignAmount,'+',str) || CheckPositionofSign(subSignAmount,'-',str) )
    {
        return -1;
    }

    //Agora que os sinais ja estao tratados, so falta ver o tipo
    
    return 0;
}

 void ScalarConverter::converter(const std::string& input)
{
    std::cout << input << std::endl;

    //Input nao esta vazio FIXE
    if(!input.empty())
    {
        int ret = IndentifyType(input);
        std::cout << "Value of ret: " << ret << std::endl; 
        if(ret == -1)
        {
            std::cout << "Saindo do programa por ERRO" << std::endl;
            return ;
        }
    }
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Bum destructor called" << std::endl;
}

