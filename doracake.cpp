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
typedef long long int lli;

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
		string s;
		cin >> s;
		map<char,int> mine;
		for(int k = 0; k < s.length(); k++){
			if(mine.find(s[k]) != mine.end()){
				mine[s[k]]++;
			}else{
				mine[s[k]] = 1;
			}
		}
		deque<int> ans;
		int flag = 0;
		int gen = 0;
		map<char,int>::iterator it;
		for(it = mine.begin(); it != mine.end(); ++it){
			//cout << "checking " << " " << it->first << " " << it->second << endl;
			if (it->first == 'd'){
				ans.push_back(it->second);
				++gen;
			}
		    if (it->first == 'o'){
				ans.push_back(it->second);
				++gen;
			}
		    if (it->first == 'r'){
				ans.push_back(it->second);
				++gen;
			}
		    if (it->first == 'c'){
				ans.push_back(it->second);
				++gen;
			}
			if (it->first == 'a'){
				flag = it->second;
				++gen;
			}
			if (it->first == 'k'){
				ans.push_back(it->second);
				++gen;
			}
			if (it->first == 'e'){
				ans.push_back(it->second);
				++gen;
			}
		}
		int mi = *min_element(ans.begin(), ans.end());
		int as = min(mi,flag/2);
		if(gen == 7){
			cout << as << endl;
		}else{
			cout << 0 << endl;
		}
		
	}
	double ka = 5.489;
	ka*= 100;
	cout << ka << endl;
	return 0;
}