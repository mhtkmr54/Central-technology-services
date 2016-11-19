#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <string>
#include <cstring>
#include <iterator>

using namespace std;

int canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int k = A.size()-1;
    int eln =  k;
    cout <<  " k  " << k << endl;
    cout << " eln " << eln << " ";
    for (k = A.size()-1; k >= 1; k--){
        if (A[k] + k >= eln){
            eln = k;
            cout << " | CH elen -> at " << A.size()-k << " eln " << k << " "; 
        }
    }
    k++;
    cout <<  " k  " << k << endl;
    if (k == 1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
   int T;
   cin >> T;
   vector<int> vec;
   while (T-- > 0){
     int el;
     cin >> el;
     vec.push_back(el);
   }
   vec.insert(vec.begin(),0);
   cout << " ANS "<< canJump(vec) << endl;
  return 0;
}