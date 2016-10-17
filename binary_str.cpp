#include <iostream>
#include <string>


using namespace std;

int main(){

    string str;
    cin >> str;
    int i = 0;
    int count = 0;
    for (int i=0; i<str.length(); ++i)
    {
    std::cout << str[i];
    }
    while (i < str.length() - 2){
        if (str[i] == '0' && str[i+1] == '1' && str[i+2] == '0'){
            //cout << str[i] - '0' + 99 << endl;  
            i = i + 3;
            count++;
        }
        else{
            i++;
        }
    }
    cout << count << endl;
    return 0;
}
