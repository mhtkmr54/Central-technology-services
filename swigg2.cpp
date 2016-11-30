#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>


using namespace std;

int main(){
	string str;
	cin >> str;
	map<char,int> m;
	for(int i = 0; i < str.length();  i++){
		m[str[i]] += 1;
	}
	int a  = m.begin()->second;
	map<char,int>::iterator it;
	int flag = 0;
	for(it = m.begin(); it != m.end(); ++it){
		if(it->second != a){
			flag = 1;
			break;
		}
	}
	if (flag == 1){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
	
}
