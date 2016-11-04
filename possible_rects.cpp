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
#include <initializer_list>

using namespace std;
 
// Rows and columns in input matrix
#define R 4
#define C 4
 

 
// Returns area of the largest rectangle with all 1s in A[][]
int max_No_Rectangle(deque < deque<int> > abc)
{
        int rect = 0;
        int n = 0;
        for (int i = 0; i < R; i++){
            for (int k = i+1; k < R; k++){
                int el = 0;
                for (int col = 0; col < C; col++){
                    if (abc[i][col] == abc[k][col] && abc[k][col] == 0){
                        cout << " i " << i << " k " << k << " COL " << col << endl;
                        ++el;
                    }
                }
             cout << " the add n " << (n*(n-1))/2 << endl;
              n += (el*(el-1))/2;  
              cout << " n " << n << endl;
            }
        }
        return n;
}
 
// Driver code
int main()
{
    deque < deque<int> > abc = { 
                   {0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0},
                 };
 
  cout <<  max_No_Rectangle(abc) << endl;
 
    return 0;
}