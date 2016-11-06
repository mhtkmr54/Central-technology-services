#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef pair<int,int> pii;


bool compare(pii a, pii b) { 
  if (a.first == b.first){
  	return a.second < b.second; 
  }else{
    return a.first < b.first;
  }
}

int find_b(deque<pii>& freq, int elem){
	int flag = 0;
	for(int i = 0; i < freq.size(); i++){
        if(freq[i].second == elem){
        	freq[i].first +=1 ;
        	cout << "exis " << freq[i].first << endl;
        	flag =1;
        }
	}
	return flag;
}

void do_the_sort(deque<int> a){
  pii foo;
  deque<pii> freq;
  for(int i = 0; i < a.size(); i++){
       if(find_b(freq, a[i])){
           continue;
       }else{
       	foo = make_pair(1,a[i]);
        freq.push_back(foo);
       }
  }
  sort(freq.begin(), freq.end());
  sort(freq.begin(), freq.end(), compare);
  for (auto kel : freq){
  	  cout << kel.first << " " << kel.second << endl;
  }
}

int main(){
	deque<int> a;
	a = {6,3,1,4,5,5,6,6};
    do_the_sort(a);
	return 0;
}