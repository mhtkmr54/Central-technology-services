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
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
            // wt of individual is > limit 
                 K[i][w] = K[i-1][w];
       }
   }

   /*
   Below we iterate throught the loop with upward dirnlef  on same w if we do not find sth
   --------------------------------------w
   |
   |
   |
   |
   i

   */

    for (int i =0; i < n+1 ; i++)
  {
     for (int j =0; j < W+1; j++)
     {
        cout << K[i][j] << " ";
     }
     cout << endl;
  }

   w = W;
   i = n;
   while (w > 0 && i > 0 ){
    cout << "EXPLORING   IF " <<  K[i][w] << "  " <<  K[i-1][w-wt[i-1]] << " with wt " << val[i-1] << "  and i " << i <<endl;
    if ((K[i][w] - K[i-1][w-wt[i-1]]) == val[i-1]){
    //if ( ((K[i][w] - K[i-1][w]) ==  val[i-1])){
        cout << "FOUND " << wt[i-1] <<endl;
        if (weight + wt[i-1] > W){
          break;
        }
        weight += wt[i-1];
        i = i - 1;
        w = w - wt[i-1];
    }
    else{
      cout << "NOT FounD" << endl;
      i = i - 1;
    }

   }
 
   return K[n][W];
}
 



// Driver program to test above function
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    cout << endl;
    cout << weight << endl;
    return 0;
}


