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
 
// Prototype of a utility function that returns minimum of two integers
int min(int a, int b);
 
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}

map <string,int> memo;

int binomialCoeffmemo(int n, int k)
{
  string res = to_string(n) + to_string(k);
   if (memo.find(res) != memo.end()){
      return memo[res];
   }
  // Base Cases
  if (k==0 || k==n)
    return 1;
 
  // Recur
  return memo[res] = binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}

// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}
 
/* Drier program to test above function*/
int main()
{
    int n = 5, k = 2;
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeffmemo(n, k) );
    cout << endl;
    return 0;
}