#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
using namespace std;

deque<int>::iterator it;

int min_moves(deque<int>& my_deq, int curr){
    
    sort(my_deq.begin(), my_deq.end());
    it=find(my_deq.begin(),my_deq.end(),curr);
    auto pos = it - my_deq.begin();
    int sum = 0;
    for (int j = 0 ; j <= pos; j++){
    	sum += my_deq[j];
    }
    for (int j = 0 ; j < pos; j++){
    	my_deq.pop_front();
    }
    my_deq.front() = sum;
    curr = sum;
   
    while(my_deq[0] > my_deq[1] && my_deq.size() > 2){
           my_deq[1] = my_deq[1] + my_deq[0];
           my_deq.pop_front();
    }
    if (my_deq.size() == 2 && curr < *max_element(my_deq.begin(),my_deq.end()) ){
    	return 1;
    }
    else if (my_deq.size() == 2 && my_deq[0] == my_deq[1]){
    	return 1;
    }else if (my_deq.size() == 2 && curr == *max_element(my_deq.begin(),my_deq.end()) ){
    	return 0;
    }
    sum = my_deq.front();
    curr = sum;

    deque<int> deq1 = my_deq;
    deq1.push_back(curr-1);
    deque<int> deq2 = my_deq;
    deq2.pop_back();

    return 1 + min(min_moves(deq1,curr), min_moves(deq2,curr));
}
 

int main(){
	int T;
	cin >> T;
	deque<int> my_deq;
	while (T-- > 0){
      int curr;
      int els;
      cin >> curr >> els;
      for(int j = 0; j < els; j++){
         int k;
         cin >> k;
         my_deq.push_back(k);
      }
      my_deq.push_back(curr);
      int a = min_moves(my_deq,curr);
      cout << a << endl;
	}


}

"""
 init fish = f
 public static int findCount(int[] arr, int i, int f){
          if (i == arr.length) return 0;
          if (f  > arr[i]) return findCount(arr, i+1, f+arr[i]);
          return Math.min(1 + findCount(arr, i, 2*f-1), arr.length - i);
          //return Math.min(1 + findCount(arr, i, 2*f-1), 1 + findCount(arr, i+1, f));
     }
"""