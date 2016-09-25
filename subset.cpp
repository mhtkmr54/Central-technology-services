#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;
 
// Returns the maximum value that can be put in a knapsack of capacity W
int weight = 0;





int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
              //val[i-1 ] is value of curr i
                 K[i][w] = max(wt[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
            // wt of individual is > limit 
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
 



// Driver program to test above function
int main()
{
    int val[] = {10, 20, 30};
    int wt[] = {10, 20, 30};
    int  W = 45;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    cout << endl;
    return 0;
}


