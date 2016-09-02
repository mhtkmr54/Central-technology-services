#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <iterator>
#include <deque>

using namespace std;

map <int,pair<int,int> > querylists;
//map <int,int> procquerylist;
deque <pair<int,int> > procquerylist;
deque <pair<int,int> >::iterator it;


void bringthequeue(){
    for (int i = 0; i < querylists.size(); i++){
      
      cout << i << ": " << querylists[i].first << " " << querylists[i].second << "  "<< endl;
      int sum = querylists[i].first + querylists[i].second;
      procquerylist.push_back(make_pair(sum ,i));
	}

	cout << "query prior";
	sort(procquerylist.begin(),procquerylist.end());
	for (it = procquerylist.begin() ; it !=procquerylist.end(); ++it){
      
      cout << it->first << ": " << it->second << endl;
	}

	return;
}


int main (){
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++){
		int t,d;
		cin >> t >> d;
		querylists[i] = pair<int,int>(t,d);
	}
    bringthequeue();
	return 0;
}