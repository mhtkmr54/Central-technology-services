#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>

//g++ -std=c++0x
using namespace std;

deque <string> answers;

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T;
    cin >> T;
    while (T-- > 0){
    	string s1;
    	string s2;
    	cin >> s1;
    	cin >> s2;
    	map<char,int> str1;
    	map<char,int> str2;
    	for (int i=0; i < s1.length(); i++){
           if(str1.find(s1[i]) == str1.end()){
           	str1[s1[i]] = 1;
           }
           else{
           	str1[s1[i]] += 1;
           }
    	}

    	for (int i=0; i < s2.length(); i++){
           if(str2.find(s2[i]) == str2.end()){
           	str2[s2[i]] = 1;
           }
           else{
           	str2[s2[i]] += 1;
           }
    	}
    	if (str1 == str2){
    		answers.push_back("yes");
    	}else{
    		answers.push_back("no");
    	}
    }
     for (int j=0; j<answers.size();j++){
          cout << answers[j] << endl;
     }
    return 0;
}
