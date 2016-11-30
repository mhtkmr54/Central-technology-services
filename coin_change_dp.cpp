#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>


using namespace std;

#define MAX 999001

deque <int> coins;
//get min no. of coins

void printCombinations( deque<int> R){
  if (R[R.size() - 1] == -1){
  cout << "nein Solutions" << endl;
  }
  int start = R.size() - 1;
  while (start != 0){
  int el = R[start];
  cout << coins[el] << " ";
  start = start - coins[el];
 }
 cout << endl;
}

int min_bottom_up(int total){
  deque <int> T;
  T.resize(total+1,MAX);
  deque <int> R;
  R.resize(total+1,-1);
  T[0] = 0;
  R[0] = 0;
  for (int k = 0; k < coins.size(); k++){
   for (int m = 1; m < T.size(); m++){
     if(m >= coins[k]){
      if (1+T[m-coins[k]] < T[m]){
      T[m] = 1 +  T[m-coins[k]];
      R[m] = k;
     }
    }
   }
  }
  printCombinations(R);
  return T[total];
}








int main(){ 
   coins = {100,50,20,10};
   cout << min_bottom_up(200) << endl;

	return 0;
}
