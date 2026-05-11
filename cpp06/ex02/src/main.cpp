#include "Base.hpp"
#include "Class.hpp"

int main()
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;

        // random Base pointer (points to A, B, or C)
        Base* randomBase = generate();

        // Identify the type using the pointer function
        std::cout << "Identifying via pointer (*p):   ";
        identify(randomBase);

        //Identify the type using the reference function
        std::cout << "Identifying via reference (&p): ";
        identify(*randomBase);

        delete randomBase;
    }
}