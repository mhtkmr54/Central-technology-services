#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    int k;
    deque <int> arr;
    cin >> n >> k;
    string number;
    cin >> number;
    int r = number.length()-1;
    int l = 0;
    int count = 0;
    while (l <= r)
    {
       if (number[l] == number[r])
        {
          l++;
          r--;
        }
       else
        {
          count++ ;
          arr.push_back(l);
          l++;
          r--;
        }
    }

    while (k > count)
    {
     int i = 0;
     while (!arr.empty() && k > count )
     {
        int j = arr.front();
        arr.pop_front();
        if (number[j] != 9 && number[number.length()- 1 - j] != 9){
            number[j] = '9';
            number[number.length()- 1 - j] = '9';
        }
        if (number[j] == 9 && number[number.length()- 1 - j] != 9){
            number[number.length()- 1 - j] = '9';
        }
        if (number[j] != 9 && number[number.length()- 1 - j] == 9){
            number[j] = '9';
        }
        k = k-2;
        count--;
        if (k == 0 || k < 0)
        {
           break;
        }
    }
    }
    if ( k == count && k != 0)
        {
         for (int i=0;i<arr.size();i++)
         {
            if (number[arr[i]]  <  number[number.length()- 1 - arr[i]])
            {
                number[arr[i]] = number[number.length()- 1 - arr[i]];
            }
             else
             {
                number[number.length()- 1 - arr[i]] = number[arr[i]];
             }
          cout << number << endl;
         }
        }
    else
    {
      cout << "-1" << endl;
    }
    return 0;
}
