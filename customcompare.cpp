#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;


map <int, pair<int,int> > Valuedensity;
deque<int> vec;
int item;
int weight;
int value;

bool myfn(int i, pair<int,int>& rhs) { 
  i = i * -1;
  j = j * -1;
  return i<j; }




int main(){
	int T = 6;
    vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(11);
	vec.push_back(4);
	sort(vec.begin(), vec.end());
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
    for (auto el : vec){
	cout << el << endl;
    }
    cout << "-----------" << endl;
    while(T-- > 0){
    	cin >> item >> weight >> value;
    	Valuedensity[item] = make_pair(item,weight); 
    }
    for (auto el : Valuedensity){
	cout << el.first << " : " << el.second.first << "  " << el.second.second << endl;
    }
    cout << endl;
    sort(Valuedensity.begin(),Valuedensity.end(),myfn(int, pair<int,int>))
	return 0;
}