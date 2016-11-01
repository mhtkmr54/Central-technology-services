/*
 * Complete the function below.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
//#include <conio.h>
#include <math.h>
using namespace std;


int check(string str, int i, int m){
    int len = m ;
    int num1 = 0;
    int num0 = 0;
    int end = 0 ;
    for(int k = i; k < len+i; k++){
      if (str[k] == '0'){
          ++num0;
      }
      if (str[k] == '1'){
          ++num1;
      }
    }
    if (num1 == num0){
        end = 1;
      }
    return end;
}
//0index args
string swap(string& str, int e1, int e2, int s1, int s2){
      int lene1 = e2-e1+1;
      int lens2 = s2-s1+1;
      string sa1 = str.substr(e1, lene1);
      string sa2 = str.substr(s1, lens2);
      cout << "2nd one" << sa1 << "with " << e1 << " " << e2 << endl;
      cout << "1st one" << sa2 << "with " << s1 << " " << s2 << endl;
      string sa3 = sa1 + sa2;
      str.replace(str.begin()+s1,str.begin()+e2, sa3);
      return str;
}

    
string largestMagical(string str) {
    int num1 = 0;
    int num0 = 0;
    int flag = 0;
    int endx = -1;
    int lastsize = 0;
    for(int i =0; i < str.length(); i++){
       if (str[i] == '1'){
        for (int m = 2; m< str.length(); m++){
           if (check(str, i, m)){
            cout << "checking " << i << " " << m << endl; 
            if (endx != -1 && i == endx+1){
              cout << str << endl;
              cout << "found 2nd one  " << endx << " last sie " << lastsize << " " << i <<  "now sie " << m << endl;
              string ans = swap(str,i,i+m-1, endx - lastsize +1,endx);
              cout << ans << endl;
            }else{
              endx = i + m - 1;
              lastsize = m;
              ++flag;
            }
            break;
           }
        }
       }
    }
}

int main()
{
  /* code */
  string s  = "1001011001";
  string ans = largestMagical(s);
  return 0;
}