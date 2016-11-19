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

map<string,int> memo;
int short_path(deque < deque <int> >& arr, int R, int C, int i, int j){
    cout << "currently " << i << " " << j << endl;
    string res = to_string(i) + to_string(j);
       if (memo.find(res) != memo.end()){
          return memo[res];
       }else{
           if (i==0 && j==0){
               return  arr[i][j];
           }

           if (i == 0){
              return memo[res]  = arr[i][j] + short_path(arr,R,C,i,j-1);
           }
           if( j == 0){
              return memo[res]  = arr[i][j] + short_path(arr,R,C,i-1,j);
           }
            int el = arr[i][j];
           if (i-1 >= 0){
             el = arr[i][j] + short_path(arr, R,C,i-1,j);
            if(j-1 >=0){
              cout << "FOR " << i << " " << j << " " << min(el, arr[i][j] + short_path(arr, R,C,i,j-1)) << endl;
              return memo[res] = min(el, arr[i][j] + short_path(arr, R,C,i,j-1));
            }
           }
           
       }
}


int minPathSum(deque<deque<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int r = A.size();
    int c = A[0].size();
    if (r == 1 && c == 1){
        return 0;
    }
    /*map <string,int> memo;*/
    //cout << "ANSSS" << short_path(A,r,c,r-1,c-1) << endl;
    return short_path(A,r,c,r-1,c-1);
}

int main(){
   int R, C;
          cin >> R >> C;
          deque < deque <int> > arr;
          arr.resize(R,deque<int>(C, 0));
          //vis.resize(R,deque<int>(C, 0));
          for (int i =0; i < R ; i++)
           { 
           for (int j =0; j < C; j++)
           {
              cin >> arr[i][j];
           }
           }
          cout << minPathSum(arr) << endl;
  return 0;
}