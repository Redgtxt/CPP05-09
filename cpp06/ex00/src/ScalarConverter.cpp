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
/*
    Vou averiguar es tenhos os sinais todos bonitinhos
*/
int ScalarConverter::CleanNumber(const std::string &str)
{
    int plusSignAmount = CountSign('+', str);
    int subSignAmount = CountSign('-', str);
    int dotAmount = CountSign('.',str);

    if (plusSignAmount == -1 || subSignAmount == -1)
        throw ScalarError(ScalarError::TooManySigns);

    if (CheckPositionofSign(plusSignAmount, '+', str) ||
        CheckPositionofSign(subSignAmount, '-', str))
        throw ScalarError(ScalarError::InvalidSignPosition);

    return 0;
}

bool OnlyDigits(const std::string& str) {

    if (str.empty()) {
        return false;
    }

    for (std::string::size_type i = 0; i < str.length(); ++i) {
        if (!isdigit(static_cast<unsigned char>(str[i]))) {
            return false; // Encontrou algo que não e digito
        }
    }
    return true; // Percorreu tudo e so achou digitos
}

int ScalarConverter::IndentifyType(const std::string &str)
{

    if(CleanNumber(str))
        return -1;
    
    //Agora que os sinais ja estao tratados, so falta ver o tipo
    if(OnlyDigits(str))
    {
        //Sou inteiro
        

        //Double
        /*
        
        Um numero com . nao pode ter a sua virgula na primeira posicao ou na ultima
        */
        if(str.find('.') == 0 || str.find('.') == str.size())
            return -1;

        //Sou double
        if(str.find('.'))
        {
            
        }
    }
    return 0;
}

 void ScalarConverter::converter(const std::string& input)
{
    if (input.empty())
        throw ScalarError(ScalarError::EmptyInput);

    CleanNumber(input);
    // ...restante validação/conversão...
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Bum destructor called" << std::endl;
}

ScalarConverter::ScalarError::ScalarError(Type type) : _type(type) {}

const char* ScalarConverter::ScalarError::what() const throw()
{
    switch (_type)
    {
        case EmptyInput:          return "Erro: input vazio.";
        case TooManySigns:        return "Erro: mais de um sinal (+/-).";
        case InvalidSignPosition: return "Erro: sinal só pode estar na primeira posição.";
        case InvalidLiteral:      return "Erro: literal inválido.";
        default:                  return "Erro desconhecido.";
    }
}

