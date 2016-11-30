#include <iostream>
#include <iomanip>

int main()
{
    double d  = (float)3 / (float)8;
       std::cout << d ;
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << d;
}