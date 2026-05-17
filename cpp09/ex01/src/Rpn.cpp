#include "Rpn.hpp"
#include <iostream>
#include <cctype>
#include <climits>


// ── RPN::RpnError ─────────────────────────────────────────────────────────────

Rpn::RpnError::RpnError(Type type) : _type(type) {}

const char *Rpn::RpnError::what() const throw()
{
    switch (_type)
    {
        case EmptyExpression:   return "Error: empty expression provided.";
        case NotEnoughOperands: return "Error: not enough operands for operator.";
        case DivisionByZero:    return "Error: division by zero.";
        case Overflow:          return "Error: integer overflow/underflow.";
        case MultiDigitNumber:  return "Error: only single digits (0-9) are supported.";
        case InvalidCharacter:  return "Error: invalid character. Only digits (0-9) and operators (+ - * /) are accepted.";
        case LeftoverOperands:  return "Error: too many operands or too few operators.";
        default:                return "Error: unknown.";
    }
}


// ── Rpn ───────────────────────────────────────────────────────────────────────

Rpn::Rpn() {}
Rpn::Rpn(const Rpn& other) { *this = other; }
Rpn& Rpn::operator=(const Rpn& other) { (void)other; return *this; }
Rpn::~Rpn() {}

void Rpn::calculate(const std::string& expression) const
{
    if (expression.empty())
        throw RpnError(RpnError::EmptyExpression);

    std::stack<int> rpnStack;

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (rpnStack.size() < 2)
                throw RpnError(RpnError::NotEnoughOperands);

            int val2 = rpnStack.top();
            rpnStack.pop();
            int val1 = rpnStack.top();
            rpnStack.pop();

            long result = 0;

            if (c == '+')
                result = static_cast<long>(val1) + val2;
            else if (c == '-')
                result = static_cast<long>(val1) - val2;
            else if (c == '*')
                result = static_cast<long>(val1) * val2;
            else if (c == '/')
            {
                if (val2 == 0)
                    throw RpnError(RpnError::DivisionByZero);
                result = static_cast<long>(val1) / val2;
            }

            if (result > INT_MAX || result < INT_MIN)
                throw RpnError(RpnError::Overflow);

            rpnStack.push(static_cast<int>(result));
        }
        else if (std::isdigit(c)) {
            char next = expression[i + 1];
            if (next != ' ' && next != '\0')
                throw RpnError(RpnError::MultiDigitNumber);
            rpnStack.push(c - '0');
        }
        else {
            throw RpnError(RpnError::InvalidCharacter);
        }
    }

    if (rpnStack.size() != 1)
        throw RpnError(RpnError::LeftoverOperands);

    std::cout << rpnStack.top() << std::endl;
}
