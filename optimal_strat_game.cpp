/*F(i, j)  represents the maximum value the user can collect from 
         i'th coin to j'th coin.

    F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
                   Vj + min(F(i+1, j-1), F(i, j-2) )) 
Base Cases
    F(i, j)  = Vi           If j == i
    F(i, j)  = max(Vi, Vj)  If j == i+1*/

#include <stdio.h>
#include <limits.h>
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

/*
pairs

std::pair <int,int> foo;
  std::pair <int,int> bar;

  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); 
    OR
  pair<int, int> my_pair(i, j);

*/

using namespace std;

map<pair<int,int>, int> memo;

int optimalStrategyOfGame(int* arr, int i, int j)
{
   pair<int, int> my_pair(i, j);
   if (memo.find(my_pair) != memo.end()){
   	 return memo[my_pair];
   }
   else{
   	     if (i == j){
   	     	memo[my_pair] = arr[i];
            return arr[i];
         }  
         if (j == i+1){
            memo[my_pair] = max(arr[i],arr[j]);
            return max(arr[i],arr[j]);
         }
         else{
         return memo[my_pair] =  max(arr[i] + min(optimalStrategyOfGame(arr , i+2, j), optimalStrategyOfGame(arr, i+1, j-1) ), 
                   arr[j]+ min(optimalStrategyOfGame(arr, i+1, j-1), optimalStrategyOfGame(arr, i, j-2) )) ;         
          }
   	
   }
   

}

int main()
{
/*	    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));
 
    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2)/sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2, n));*/

 
    int arr[] = {20, 30, 2, 2, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", optimalStrategyOfGame(arr,0,n-1));
 
    return 0;
}