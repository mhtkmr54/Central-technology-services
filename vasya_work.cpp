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

map <char,deque<int>> my_map_t;
map <char,deque<int>> my_map_s;


/*
long int fact(int x)          //defining the function or function definition
{
	int i, f=1;
	for(i=2; i<=x; i++)
	{
		f=f*i;
	}
	return f;
}


*/

//char tab2[1024];
//strcpy(tab2, tmp.c_str());
int main(){
	int size;
	cin >> size;
	string t;
	string s;
	cin >> t;
	cin >> s;
	char taste[size];
	strcpy(taste, t.c_str());
	char sleep[size];
	strcpy(sleep, s.c_str());
	for (int i = 0; i < size ; i++){
	   int k = i + 1;
       my_map_t[taste[i]].push_back(k);
       my_map_s[sleep[i]].push_back(k);
	}
	for (auto elem : my_map_t){
		cout << elem.first << " : ";
		for (auto el : elem.second){
          cout << el << " ";
		}
		cout << endl;
	}

	for (auto elem : my_map_s){
		cout << elem.first << " : ";
		for (auto el : elem.second){
          cout << el << " ";
		}
		cout << endl;
	}
	return 0;
}