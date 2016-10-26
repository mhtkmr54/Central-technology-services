#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;

// Function to return gcd of a and b
//Euclidean
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
	string names
;
	int T = 2;
	vector<string> result;
	while(T >= 0)
    {
        cin >> names;
        
        istringstream iss(names);
        for(string s;iss >> names;){
        	result.push_back(names);
        }
        --T;
    }
    for (auto elem : result){
    	cout << stoi(elem) << endl;
    }
	return 0;
}
