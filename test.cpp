#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
//#include <conio.h>
#include <math.h>
#include <map>
using namespace std;
typedef long long int lli;

const int MOD = 1e9 + 7;
int main(){
	string str = "azzz";
    int f = next_permutation(str.begin(),str.end());
    cout<< str << endl;
     
        while (f != 0){
        	cout<< str << endl;
        	 f = next_permutation(str.begin(),str.end());
        }
   /*     cout << 1%2 << endl; 
        cout << "df" <<factorial(5) << endl;*/
        map <int,int> mine;
        cout << "dfalt "<< mine[12] << endl;
/*        string sample = "12345678";
        string sam = sample.substr (3,5);
        cout<< sam << endl;
        cout << endl;
        lli abc = 6564120420;
        cout << fmod(abc,pow(10,9)+7) << "   ";
        int ran = 6564120420;
        cout << abc % MOD << endl;  
        cout << endl;
        float a = 1;
        int rel = (int)a;
        if (rel == a){
            cout << "ohh" << endl; 
        }
        cout << a << endl;      
        double x = 1.7;
        cout << (int)x << endl;	
        cout << 10 / 3* 3  % 5 << endl;
        char *b[2] = {"hello", "hi"};
        cout << "ans  " << sizeof(b) << endl;
        cout << 1 + 2 + "3" << endl;*/
return 0;
}

