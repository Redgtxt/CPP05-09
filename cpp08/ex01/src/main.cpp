#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(160);
    v1.push_back(15540);
    v1.push_back(104);
    v1.push_back(1044343421);


    try
    {
        ::easyfind(v1,12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}