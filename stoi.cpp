#include <iostream>

using namespace std;
#include <string>
#include<sstream>


int main()
{
    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = "31337 with words";


    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);


    std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
}