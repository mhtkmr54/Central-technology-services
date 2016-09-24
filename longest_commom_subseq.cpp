/* A Naive recursive implementation of LCS problem */
#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int max(int a, int b);

map <string,int> memo;
 // http://ideone.com/uTX7nD
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
  string res = to_string(m) + to_string(n);
   if (memo.find(res) != memo.end()){
      return memo[res];
   }
   else{
          if (m == 0 || n == 0){
            return 0;
         }  
         if (X[m-1] == Y[n-1]){
           return memo[res] = 1 + lcs(X, Y, m-1, n-1);
         }
         else{
           return memo[res] = max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
         }
   }
   
}
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
 
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  for(auto el : memo ){
    cout << el.first << " : " << el.second << endl;
  }
 
  return 0;
}

