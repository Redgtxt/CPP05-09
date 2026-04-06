#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

#define CHAR_TYPE 1
#define INT_TYPE 2
#define FLOAT_TYPE 3
#define DOUBLE_TYPE 4

class ScalarConverter {
private:
    
    ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();


    static int CountSign(char sign, const std::string &str);
    static int CheckPositionofSign(int sign, char symbol, const std::string &str);
    static void CleanNumber(const std::string &str);
    static bool OnlyDigits(const std::string& str);
    static bool MyFind(char value, const std::string &str);
    static int IndentifyType(const std::string &str);

    static void printValues(char c, int i, float f, double d, bool isImpossible, bool isCharImpossible);

public:
    class ScalarError : public std::exception {
    public:
        enum Type { EmptyInput, TooManySigns, InvalidSignPosition, InvalidLiteral, TooManyDots };
        ScalarError(Type type);
        virtual const char* what() const throw();
    private:
        Type _type;
    };


    static void convert(const std::string& input);
};

#endif