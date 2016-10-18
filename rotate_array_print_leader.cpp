do, where 1 < k <= n:
  reverse (s, 1, k);
  reverse (s, k + 1, n);
  reverse (s, 1, n);

  left rotates array s by k units;

  do, where 1 < k <= n:
  reverse (s, 1, n);
  reverse (s, 1, k);
  reverse (s, k + 1, n);
  
right rotates array s by k units;

void printLeaders(int arr[], int size)
{
    int max_from_right =  arr[size-1];
 
    /* Rightmost element is always leader */
    cout << max_from_right << " ";
     
    for (int i = size-2; i >= 0; i--)
    {
        if (max_from_right < arr[i])
        {           
            max_from_right = arr[i];
            cout << max_from_right << " ";
        }
    }    
}





#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int size;
    int k;
    int el;
    deque<int> myvector;
    cin >> size >> k ;
    int n = size;
    for (int s = 0; s < size ; s++){
        cin >> el;
        myvector.push_back(el);
    }
    for (int j = 0 ; j < k ; j++){
        int fr = myvector.front();
        myvector.pop_front();
        myvector.push_back(fr);
    }
    for (auto el : myvector){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}
