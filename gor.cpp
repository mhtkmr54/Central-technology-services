#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
deque<int> ans;

int minPathSum(deque<deque<int> > &A) {
 
    int r = A.size();
    int c = A[0].size();
    if (r == 1 && c == 1){
        ans.push_back(A[0][0]);
    }
   
    int minPath[r][c];
    for (int i=0; i<r; i++){
        for(int j=0; j<c; j++){
          if (i==0 && j== 0){
              minPath[i][j] = A[i][j];
              //ans.push_back(A[0][0]);
              
          }
          else if (i == 0 && j != 0){
              minPath[i][j] = A[i][j] + minPath[i][j-1];
           }
           else if( j == 0 && i != 0){
               minPath[i][j]  = A[i][j] + minPath[i-1][j];
           }
           else {
             //int el = arr[i][j] + minPath[i-1,j];;
            //if(j-1 >=0){
            //  cout << "FOR " << i << " " << j << " " << min(el, arr[i][j] + short_path(arr, R,C,i,j-1)) << endl;
               minPath[i][j] = A[i][j] + min(minPath[i-1][j] , minPath[i][j-1]);
            //}
        }
    }
    }
    int We =  minPath[r-1][c-1];
    
    
    for (int i =r; i > 0 ; )
      { 
           for (int j = c; j > 0; )
           {
             if (i==0 && j== 0){
              minPath[i][j] = A[i][j];
              ans.push_front(A[i][j]); 
               }
               
             if (i-1 > 0 && j-1 > 0){
                 if (minPath[i][j] - minPath[i-1][j] == A[i][j]){
                    ans.push_front(A[i][j]); 
                    i--;
                 }
                 else if (minPath[i][j] - minPath[i][j-1] == A[i][j]){
                     ans.push_front(A[i][j]); 
                     j--;
                 }
                 else{
                     //
                 }
           
             }
             if ( i = 0 && j > 0 ){
                 if (minPath[i][j] - minPath[i-1][j] == A[i][j]){
                    ans.push_front(A[i][j]); 
                    i--;
               }
             }
              if ( j = 0 && i > 0 ){
                  if (minPath[i][j] - minPath[i][j-1] == A[i][j]){
                     ans.push_front(A[i][j]); 
                     j--;
                 }
             }
           }
         cout << endl;
      }
    cout << endl;
    
      
   
   int w = r;
   int i = c;

    
    return minPath[r-1][c-1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int R;
    int C;
    cin >> R >> C;
    deque < deque <int> > arr;
          arr.resize(R,deque<int>(C, 0));
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




















            if (i==0 && j== 0){
              minPath[i][j] = A[i][j];
              ans.push_front(A[i][j]); 
               }
               
             if (i-1 > 0 && j-1 > 0){
                 if (minPath[i][j] - minPath[i-1][j] == A[i][j]){
                    ans.push_front(A[i][j]); 
                    i--;
                 }
                 else if (minPath[i][j] - minPath[i][j-1] == A[i][j]){
                     ans.push_front(A[i][j]); 
                     j--;
                 }
                 else{
                     //
                 }
           
             }
             if ( i = 0 && j > 0 ){
                 if (minPath[i][j] - minPath[i-1][j] == A[i][j]){
                    ans.push_front(A[i][j]); 
                    i--;
               }
             }
              if ( j = 0 && i > 0 ){
                  if (minPath[i][j] - minPath[i][j-1] == A[i][j]){
                     ans.push_front(A[i][j]); 
                     j--;
                 }
             }









                 for (int i = 0; i < r ;i++ )
      { 
           for (int j = 0; j < c; j++)
           {
              // cout << minPath[i][j] << " ";
           }
         cout << endl;
      }
    cout << endl;