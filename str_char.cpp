#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

char findlargerInRight(char* str, int low, int high)
{
    int countRight = 0, i;
    char min;
    for (i = low+1; i < high; i++){
        //cout << "low " << low << " " <<str[low] << " " << str[i] << " "<< endl;
        if (str[low] < str[i]){
            if (countRight == 0)
                {
                 min = str[i];
                 //cout << "min" << min << endl;
                }
            countRight++;
            if (str[i] < min)
            {
               min = str[i];
               //cout << "min" << min << endl;
            }
        }
        }
    if (countRight == 0)
    {
     min = str[low];
     return str[low];
    }
    return min;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<string> datarr;
    int t;
    cin >> t;
    while(t--)
    {
      string test;
      cin >> test;
      datarr.push_back(test);
    }
    for (int k=0 ; k<datarr.size() ; k++ )
    {
      cout << "datarr.size()  " << datarr.size() << endl;
      string s = datarr.at(k);
      cout << "the s  "<< s << " " << s.length()<< endl;

      char str[s.length()];
      strcpy(str, s.c_str());
      int low;
      int high = strlen(str);
      for (low = strlen(str)-2; low >= 0 ;low--)
          {
          char larger = findlargerInRight(str, low , high ) ;
          cout << "larger-->  " << larger << "  str[low]------->" << str[low] << " S strng   " << s <<endl;
          if (larger !=str[low])
          {
              int index = s.find(larger);
              char z = str[index];
              str[index] = str[low];
              str[low] = z;
              cout << str <<endl; //print char array
              break;

          }
          else{
              cout << s <<endl; //print  string
          }

      }


    }

    return 0;
}


