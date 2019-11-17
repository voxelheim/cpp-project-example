#include "example.hpp"

#include <iostream>

int main()
{
    std::cout << "Test result: ";

    if (Example().getTrue())
    {
        std::cout << "SUCCESS" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
}