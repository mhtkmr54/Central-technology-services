/* A Naive recursive implementation of LCS problem */
#include <bits/stdc++.h>
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





//https://www.youtube.com/watch?v=NnD96abizww&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=2
//bottom top

  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs1( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   // Following code is used to print LCS
   int index = L[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character

    i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }

    for(auto el : lcs ){
    cout << el << " " ;
  }
  cout << endl;
 
   return L[m][n];
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
 
  printf("Length of LCS is %d\n", lcs1( X, Y, m, n ) );

 
 
  return 0;
}

