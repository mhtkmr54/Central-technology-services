#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <string>


using namespace std;

map<string,string> memo;
deque<int> mydeq;
int XOR = 0;

int findSanXOR(int set){
    for (int L = 2; L<=set; L++){
    	for (int i = 0; i <= mydeq.size()-L; i++){
    		cout << "goi "<< endl;
    		string mems = memo[to_string(i) + ":" + to_string(L-1)];
    		if( L == 2 && i == 0){
    			cout << (int)mems << endl;
    		}
    		
    		//XOR += mydeq[i] + (int)mems;
    		//cout << "mydeq[i]   " << mydeq[i] << "  findSanXOR[L-1]  " << findSanXOR[L-1] << endl;
    	}
     cout << "Changing length -------------------------------------------" << endl;
    }
    return 0;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int nodes;
    cin >>  nodes;  
    for (int i = 0; i < nodes ; i++){
      int f;
      cin >> f;
      mydeq.push_back(f);
    }
    for (int z = 0; z < mydeq.size(); z++){
      	
      	memo[to_string(z)+ ":" + to_string(1)] = to_string(mydeq[z]);
      }

    for (auto el : memo){
    	cout << el.first << " "<< el.second << endl;
    }
    int ans = findSanXOR(mydeq.size());
;    return 0;
}
