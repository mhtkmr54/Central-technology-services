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
int n,W;




int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1]; 
   int picks[n+1][W+1] = {0};
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w){
              //val[i-1 ] is value of curr i
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                 if (val[i-1]+K[i-1][w-wt[i-1]] > K[i-1][w]){
                    picks[i][w]=1;
                 }
                else
                    picks[i][w]=-1;
           }
           else{
            // wt of individual is > limit 
                 picks[i][w] = -1; 
                 K[i][w] = K[i-1][w];
        }
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
  cout << endl;
   
/*   int item = n;
   int size = W;
   while (item>0){
        if (picks[item][size]==1){
            printf("%d ",item-1);
            item--;
            size -= wt[item -1];
        }
        else{
            item--;
        }
    }

    printf("n");*/
  
   w = W;
   i = n;
   while (w > 0 && i > 0 ){
   // cout << "EXPLORING   IF " <<  K[i][w] << " - " <<  K[i-1][w-wt[i-1]] << " with wt " << wt[i-1] << "  and i " << i <<endl;
    if (K[i][w] != K[i-1][w] ){
    //if ( ((K[i][w] - K[i-1][w]) ==  val[i-1])){
        cout << "FOUND " << val[i-1] << "  and i-1 " << i-1 <<endl;
/*        if (weight + wt[i-1] > W){
          break;
        }*/
        weight += wt[i-1];
        i = i - 1;
        w = w - wt[i] ;
        cout << "Went to " << i << " " << w << " -- > " << K[i][w] << endl;
    }

    else{
      i = i - 1;
    }

   }
  cout << endl;
    return K[n][W];
}


 



// Driver program to test above function
int main()
{
    int val[] = {10,40,30,50};
    int wt[] = {5,4,6,3};
     W = 10;
    n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    cout << endl;
    cout << weight << endl;
  
    return 0;
}


