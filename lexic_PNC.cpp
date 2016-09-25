#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        string ini = str;
        cin>>str;
        //std::sort(str.begin(),str.end());
        int f = next_permutation(str.begin(),str.end());
        string str1 = str;
        f = next_permutation(str.begin(),str.end());
         string str2 = str;
        if(f==0)
        {
            cout<<"no answer"<<endl;
        }
        else
        {
            //stoi(str1) - stoi(ini) << stoi(str2) - stoi(ini)
            cout<< ini << " " << str1 << " " << str2 <<  " " << endl;
        }
    }
    return 0;
}
