#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <locale>



using namespace std;

#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};
int picks[100][100] = {0};

int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++){
        for (j=0;j<=size;j++){
            if (weights[i-1]<=j){
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                    picks[i][j]=1;
                else
                    picks[i][j]=-1;
            }
            else{
                picks[i][j] = -1;
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }
    cout << matrix[nItems][size] << endl;

    for (int i =0; i < n+1 ; i++)
  {
     for (int j =0; j < W+1; j++)
     {
        cout << K[i][j] << " ";
     }
     cout << endl;
  }

    return matrix[nItems][size];

}

void printPicks(int item, int size, int weights[]){

    while (item>0){
        if (picks[item][size]==1){
            printf("%d ",item-1);
            item--;
            size -= weights[item];
        }
        else{
            item--;
        }
    }

    printf("n");

return;
}

int main(){
    int nItems = 4;
    int knapsackSize = 10;
    int weights[4] = {5,4,6,3};
    int values[4] = {10,40,30,50};

    printf("Max value = %dn",knapsack(nItems,knapsackSize,weights,values));
    cout << endl;
    printf("Picks were: ");
    
    printPicks(nItems,knapsackSize, weights);
    cout << endl;
    return 0;
}