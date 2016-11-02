#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
#include <initializer_list>

using namespace std;
typedef pair<int,char> pic;

bool myfn(pic a, pic b){
	if (a.first != b.first){
        return a.first < b.first;
	}else {
		return (int)a.second < (int)b.second;
	}
	
}

string solve(string str){
	deque<pic> deq;
	map <char,int> mine;
	for (int i =0; i < str.length(); i++){
		if(mine.find(str[i]) != mine.end()){
           mine[str[i]] += 1;
		}else{
           mine[str[i]] = 1;
		}
	}
	for (auto el : mine){
		pic foo = make_pair(el.second,el.first);
		deq.push_back(foo);
	}
	cout << "---B$ " << endl;
    for (auto elems : deq){
		cout << elems.first << " : " << elems.second << endl;
	}
	sort(deq.begin(), deq.end(),myfn);
	cout << "---AFTER $ " << endl;
    for (auto el : deq){
		cout << el.first << " : " << el.second << endl;
	}
	string ans = "";
	for (auto elem : deq){
	 for(int k = 0; k < mine[elem.second]; k++){
	 	ans += elem.second;
	 }
	}
    return ans;
}

int main(){
	int T;
	cin >> T;
	deque<string> my_deq;
	while (T-- > 0){
		string str;
		cin >> str;
		my_deq.push_back(solve(str));
	}
	for (auto e : my_deq){
		cout << e  << endl;
	}
	cout << endl;
	return 0;
}