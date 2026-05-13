#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "--- Testing std::vector ---" << std::endl;
    try {
        
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Success: Found value " << *it << " in vector." << std::endl;

        
        it = easyfind(vec, 99); 
        std::cout << "Success: Found value " << *it << " in vector." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << "--- Testing std::list ---" << std::endl;
    try {
        
        std::list<int>::iterator it = easyfind(lst, 1);
        std::cout << "Success: Found value " << *it << " in list." << std::endl;

        
        it = easyfind(lst, -5); 
        std::cout << "Success: Found value " << *it << " in list." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}