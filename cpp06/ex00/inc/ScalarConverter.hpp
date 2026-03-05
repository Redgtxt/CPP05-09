#include <iostream>
#include <string>
class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter& operator=(const ScalarConverter& other);
    static int IndentifyType(const std::string &str);
    static int CheckPositionofSign(int sign,char symbol,const std::string &str);
    static int CountSign(char Sign,const std::string &str);

    ~ScalarConverter();
public:
    static void converter(const std::string& input);

};


