#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { *this = obj; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if(this != &other)
    {
        (void)other;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarError::ScalarError(Type type) : _type(type) {}

const char* ScalarConverter::ScalarError::what() const throw()
{
    switch (_type) {
        case EmptyInput:          return "Error: input empty.";
        case TooManySigns:        return "Error: more than one sign (+/-).";
        case InvalidSignPosition: return "Error: sign can only be in a first position";
        case InvalidLiteral:      return "Error: literal invalid.";
        case TooManyDots:         return "Error: more than one coma (.).";
        default:                  return "Error Unknowned.";
    }
}

int ScalarConverter::CountSign(char sign, const std::string &str)
{
    int contador = 0;
    size_t pos = 0;
    while ((pos = str.find(sign,pos)) != std::string::npos) {
        contador++;
        pos++;
    }
    if(contador > 1) 
        return -1;
    return contador;
}

int ScalarConverter::CheckPositionofSign(int sign, char symbol, const std::string &str)
{
    if(sign) {
        if(str.find(symbol) == 0)
            return 0;
        else 
            return -1;
    }
    return 0;
}

void ScalarConverter::CleanNumber(const std::string &str)
{
    int plusSignAmount = CountSign('+', str);
    int subSignAmount = CountSign('-', str);
    int dotAmount = CountSign('.',str);

    if (plusSignAmount == -1 || subSignAmount == -1)
        throw ScalarError(ScalarError::TooManySigns);
    if(dotAmount == -1)
        throw ScalarError(ScalarError::TooManyDots);
    if (CheckPositionofSign(plusSignAmount, '+', str) || CheckPositionofSign(subSignAmount, '-', str))
        throw ScalarError(ScalarError::InvalidSignPosition);
}

bool ScalarConverter::OnlyDigits(const std::string& str)
{
    if (str.empty()) return false;
    for (std::string::size_type i = 0; i < str.length(); ++i) {
        if (!isdigit(static_cast<unsigned char>(str[i]))) return false;
    }
    return true;
}

bool ScalarConverter::MyFind(char value, const std::string &str)
{
    return str.find(value) != std::string::npos;
}

int ScalarConverter::IndentifyType(const std::string &str)
{
    CleanNumber(str);
    
    if (str == "nanf" || str == "+inff" || str == "-inff") return FLOAT_TYPE;
    if (str == "nan" || str == "+inf" || str == "-inf") return DOUBLE_TYPE;

    char *end = NULL;
    double value = std::strtod(str.c_str(), &end);
    (void)value; 

    if (end == str.c_str())
    {
        if (str.size() == 1) 
            return CHAR_TYPE;
        return -1;
    }
    if (*end == 'f' && *(end + 1) == '\0' && MyFind('.',str))
    {
        return FLOAT_TYPE;
    }
    if (*end == '\0')
    {
        if (MyFind('.', str)) return DOUBLE_TYPE;
        else return INT_TYPE;
    }
    return -1;
}

void ScalarConverter::printValues(char c, int i, float f, double d, bool isImpossible, bool isCharImpossible)
{
    // 1. Imprimir char
    std::cout << "char: ";
    if (isImpossible || isCharImpossible) std::cout << "impossible" << std::endl;
    else if (!std::isprint(c)) std::cout << "Non displayable" << std::endl;
    else std::cout << "'" << c << "'" << std::endl;

    // 2. Imprimir int 
    std::cout << "int: ";
    if (isImpossible) std::cout << "impossible" << std::endl;
    else std::cout << i << std::endl;

    // 3. Imprimir float
    std::cout << "float: ";
    if (f - static_cast<int>(f) == 0 && !isImpossible && f < 1000000 && f > -1000000)
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;

    // 4. Imprimir double
    std::cout << "double: ";
    if (d - static_cast<int>(d) == 0 && !isImpossible && d < 1000000 && d > -1000000)
        std::cout << d << ".0" << std::endl;
    else
        std::cout << d << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    if (input.empty())
        throw ScalarError(ScalarError::EmptyInput);

    int ret = IndentifyType(input);
    if(ret == -1) {
        std::cout << "Literal not found." << std::endl;
        return ;
    }

    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    
    bool isImpossible = false;
    bool isCharImpossible = false;

    // Tratamento de pseudo-literais que afetam int e char
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff") {
        isImpossible = true;
    }

    switch (ret)
    {
        case CHAR_TYPE:
        {
            c = input[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        }
        case INT_TYPE:
        {
            long l = std::strtol(input.c_str(), NULL, 10);
            if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
                isImpossible = true;
            } else {
                i = static_cast<int>(l);
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) isCharImpossible = true;
            }
            break;
        }
        case FLOAT_TYPE:
        {
            f = std::strtof(input.c_str(), NULL);
            d = static_cast<double>(f);
            if (!isImpossible) {
                if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min()) isImpossible = true;
                else {
                    i = static_cast<int>(f);
                    c = static_cast<char>(i);
                    if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max()) isCharImpossible = true;
                }
            }
            break;
        }
        case DOUBLE_TYPE:
        {
            d = std::strtod(input.c_str(), NULL);
            f = static_cast<float>(d);
            if (!isImpossible) {
                if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) isImpossible = true;
                else {
                    i = static_cast<int>(d);
                    c = static_cast<char>(i);
                    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) isCharImpossible = true;
                }
            }
            break;
        }
    }

    printValues(c, i, f, d, isImpossible, isCharImpossible);
}
