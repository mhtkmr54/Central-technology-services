#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>


using namespace std;

deque<int> mydeq;
deque<int>::iterator it;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int toys;
    cin >> toys;
    int f;
    for (int i = 0; i < toys; i++){
    	cin >> f;
    	mydeq.push_back(f);
    }
    sort(mydeq.begin(),mydeq.end());
    int cost = 0;
    while(!mydeq.empty()){
    	cout << "in w" << endl;
    	for (it = mydeq.begin(); it != mydeq.end(); ++it){
          cout << *it << " what " << endl; 
    	 }
    	cost++;
    	int cand = mydeq.front();
    	mydeq.pop_front();
    	int j = 0;
    	for (it = mydeq.begin(); it != mydeq.end(); ++it){
    	 if (cand + 4 >= *it){
    	 	j++;  
    	 }
    	 else{
    	 	break;
    	 }
    	}
    	if ( j!= 0){
    		cout << "j  " << j << endl;
    		mydeq.erase(mydeq.begin(),mydeq.begin()+j);
    	}
    }
    cout << cost;

    return 0;
}
