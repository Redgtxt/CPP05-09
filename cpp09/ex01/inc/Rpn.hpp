#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class Rpn {
public:

    Rpn();
    Rpn(const Rpn& other);
    Rpn& operator=(const Rpn& other);
    ~Rpn();

    void calculate(const std::string& expression) const;

    class RpnError : public std::exception {
    public:
        enum Type {
            EmptyExpression,
            NotEnoughOperands,
            DivisionByZero,
            Overflow,
            MultiDigitNumber,
            InvalidCharacter,
            LeftoverOperands
        };

        explicit RpnError(Type type);
        virtual const char *what() const throw();

    private:
        Type _type;
    };
};

#endif