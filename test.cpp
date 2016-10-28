#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
//#include <conio.h>
#include <math.h>
using namespace std;



int main(){
	string str = "azzz";
    int f = next_permutation(str.begin(),str.end());
    cout<< str << endl;
     
        while (f != 0){
        	cout<< str << endl;
        	 f = next_permutation(str.begin(),str.end());
        }
        cout << 1%2 << endl; 
     //cout << factorial(5) << endl;
        string sample = "12345678";
        string sam = sample.substr (3,5);
        cout<< sam << endl;
	return 0;
}

