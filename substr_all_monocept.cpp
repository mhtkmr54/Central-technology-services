#include <bits/stdc++.h>
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

using namespace std;

int check(string sub, deque<string> lists){

   int flag =0;
   for(int k = 0; k < lists.size(); k++){
      std::size_t found = lists[k].find(sub);
      if (found!=std::string::npos){
        ++flag;
      }
   }
   if (flag == lists.size()){
    cout << sub << endl;
      return 1;
   }else{
     return 0;
   }

}

int all_subs(deque<string> lists, int _min, int mindx){
    int all = 0;
    for(int len = 1; len <= _min; len++){
       for (int k = 0; k < _min-len+1; k++){
        string sub = lists[mindx].substr(k,len);
        cout << "the b4 sub chk " << sub << endl;
        if (check(sub, lists)){
            ++all;
        }
       }
    }
    return all;

}


int main()
{   deque<int> answer;
    deque<string> lists;
    int T;
    cin >> T;
    int _min = 999999999;
    int idx = 0;
    int mindx;
    while (T-- > 0){
        string a;
        cin >> a;
        if(a.length() < _min){
            mindx = idx;
            _min = a.length();
        }
        lists.push_back(a);
        ++idx;
    }
    cout << all_subs(lists,_min, mindx);
    
return 0;
}