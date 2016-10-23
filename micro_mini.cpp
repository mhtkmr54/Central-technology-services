#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <locale>

using namespace std;

map<string,int> my_map;
deque <string> my_deq;

void rotate(string& abc){
	char str1 = abc.back();
	string str2(1,str1);
	abc.pop_back();
	abc.insert(0,str2);
    my_map[abc] = 1;
}


int main(){
    int tests;
    cin >> tests;
    while(tests-- > 0){
     string abc;
     cin >> abc;
     for(int j = 0; j < abc.length(); j++){
     	rotate(abc);
     }
     cout << my_map.size() << endl;
     my_map.clear();
    }
	return 0;
}