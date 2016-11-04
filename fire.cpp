#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
//#include <conio.h>
#include <math.h>
using namespace std;
typedef long long int lli;








"""
get min  T  = max({T[i]}) + 1;
asat

"""








int getmint(deque<int>& my_deq){
	int curr_pos = 0;
	int t = 0;
	while(curr_pos <= my_deq.size()-1){
		//cout << " curr_pos " << curr_pos  << endl;
		if (my_deq[curr_pos+1] > 0){ //wait ans sim
		  t += my_deq[curr_pos+1];
		  int wait  = my_deq[curr_pos+1];
		  for (int k = curr_pos + 1; k < my_deq.size(); k++){
		  	//cout << "red" << endl;
		  	//cout << my_deq[k] << " " << my_deq[curr_pos+1] << endl;
			my_deq[k] =  my_deq[k] - wait;
		   }
/*		   cout << endl;
		   cout << curr_pos << endl;
		   	for(auto el : my_deq){
		     cout << el << " ";
	       }
	       cout << endl;*/
		}
		//walk
		//cout << "after wait and curr_pos " << curr_pos << endl;
		if (curr_pos < my_deq.size()-1){
		 while(curr_pos < my_deq.size() && my_deq[curr_pos] <= 0){
			++curr_pos; 
			//cout << "walking " << curr_pos << endl;
			//cout << " walk " << endl;
		 }
		 ++t;	
		}

	}
	return t;
}

int main(){
	int T;
	deque<int> ans;
	cin >> T;
	while (T-- > 0){
		int N;
		cin >> N;
		deque<int> my_deq;
		while(N-- > 0){
           int el;
           cin >> el;
           my_deq.push_back(el);
		}
		int a = getmint(my_deq);
        ans.push_back(a);
	}
	for(auto el : ans){
		cout << el << endl;
	}

	return 0;
}
