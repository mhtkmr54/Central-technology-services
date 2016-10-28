#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
using namespace std;

int size;
int m;
deque<int> my_deq;

void get_min_stops(){
  
}

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
      cin >>  size;
       for (int j =0;j< size; j++){
       	   int el;
       	   cin >> el;
       	   my_deq.push_back(el);
       }

       cin >> m;
       get_min_stops();
	}


}