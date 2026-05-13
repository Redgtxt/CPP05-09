#include "MutantStack.hpp"
#include "list"

int main()
{
    // -------------------------------------------------------------------------
    // MANDATORY SUBJECT TEST
    // -------------------------------------------------------------------------
    std::cout << "--- 1. Testing with MutantStack ---" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        std::cout << "Iterating through MutantStack contents:" << std::endl;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl;

    // -------------------------------------------------------------------------
    // COMPARISON TEST WITH STD::LIST
    // -------------------------------------------------------------------------

    std::cout << "--- 2. Testing with std::list (Comparison) ---" << std::endl;
    {
        std::list<int> lstack;

        lstack.push_back(5);  
        lstack.push_back(17);

        std::cout << "Top: " << lstack.back() << std::endl;

        lstack.pop_back();

        std::cout << "Size after pop: " << lstack.size() << std::endl;

        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);

        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();

        ++it;
        --it;

        std::cout << "Iterating through std::list contents:" << std::endl;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    return 0;
}