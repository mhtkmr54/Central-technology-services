#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;



int main(){
	string str = "azzz";
    int f = next_permutation(str.begin(),str.end());
    cout<< str << endl;
     
        while (f != 0){
        	cout<< str << endl;
        	 f = next_permutation(str.begin(),str.end());
        }
        cout << 1%2 ; 
	return 0;
}