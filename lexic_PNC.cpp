#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        //std::sort(str.begin(),str.end());
        int f = next_permutation(str.begin(),str.end());
        if(f==0)
        {
            cout<<"no answer"<<endl;
        }
        else
        {
            cout<<str<<endl;
        }
    }
    return 0;
}
