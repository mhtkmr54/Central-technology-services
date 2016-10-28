#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
deque<deque <int> > vis;

int short_path(deque < deque <int> >& arr, int R, int C, int p, int q){
   pii start;
   pii position;
   start = make_pair(0,0);
   position = make_pair(p,q);
   int pathlen = 0;
   deque< pair<int,pii> >mydeque;
   mydeque.push_back(make_pair(pathlen,start));

   while(!mydeque.empty()){
    int path = mydeque.front().first;
    pii curr  = mydeque.front().second;
    int i = curr.first;
    int j = curr.second;
    mydeque.pop_front();
    if (vis[i][j] == 0){
      vis[i][j] = 1;
      if (i == p && j == q){
        return path;
      }
      deque< pair<int, int> > dirs;
      dirs.push_back(pair<int,int>(curr.first-1,curr.second));
      dirs.push_back(pair<int,int>(curr.first,curr.second-1));
      dirs.push_back(pair<int,int>(curr.first,curr.second+1));
      dirs.push_back(pair<int,int>(curr.first+1,curr.second));
      for (int d =0; d < dirs.size(); d++){
       int l = dirs[d].first;
       int m = dirs[d].second;
       if (l >= 0 && m >= 0 && m < C && l < R){
            if (vis[l][m] == 0){
             int edgelen = arr[l][m];
             pii next;
             next = make_pair(l,m);
             mydeque.push_back(make_pair(edgelen+path ,next));
            }
       }  
      }
      sort(mydeque.begin(),mydeque.end());
    }
 }
 return 0;
}
     
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
      int T;
     cin >> T;
     while(T-- > 0){
          int R, C;
          int p,q;
          cin >> R >> C;
          cin >> p >> q;
          deque < deque <int> > arr;
          arr.resize(R,deque<int>(C, 0));
          vis.resize(R,deque<int>(C, 0));
          for (int i =0; i < R ; i++)
           { 
           for (int j =0; j < C; j++)
           {
              cin >> arr[i][j];
           }
           }
          cout << short_path(arr,R,C,p,q) << endl;
          vis.resize(R,deque<int>(C, 0));

          
     }
    return 0;
}
