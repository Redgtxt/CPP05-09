#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <stdlib.h>


enum    DataType
{
    FLOAT_TYPE,
    DOUBLE_TYPE,
    INT_TYPE,
    CHAR_TYPE
};

class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter& operator=(const ScalarConverter& other);
    static int IndentifyType(const std::string &str);
    static int CheckPositionofSign(int sign,char symbol,const std::string &str);
    static int CountSign(char Sign,const std::string &str);
    static void CleanNumber(const std::string &str);
    static bool OnlyDigits(const std::string& str);
    static bool MyFind(char value, const std::string &str);

    ~ScalarConverter();

    class ScalarError : public std::exception
    {
    public:
        enum Type {
            EmptyInput,
            TooManySigns,
            InvalidSignPosition,
            InvalidLiteral,
            TooManyDots
        };

        explicit ScalarError(Type type);
        const char* what() const throw();

    private:
        Type _type;
    };

public:
    static void converter(const std::string& input);

};


