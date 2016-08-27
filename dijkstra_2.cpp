#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>
using namespace std;

int Dijkstra(vector<vector<int> > arr, int start, int end){
 vector<int>::iterator it;
 int pathlen = 0;
 map <int,int> vis;
 for (int k = 0; k < end+1; k++)
 {
     vis.insert(pair<int,int>(k,0));
 }
 int len  = arr[0].size();
 deque<pair<int,int> >mydeque;
 mydeque.push_back(make_pair(pathlen,start));
 while(!mydeque.empty()){
    int path = mydeque.front().first;
    int curr  = mydeque.front().second;
    mydeque.pop_front();
    if (vis[curr] == 0){
      vis[curr] = 1;
      if (curr == end){
        return path;
      }
      for (int k = 0; k < len; k++)
      {
        if (arr[curr][k] != -99 && vis[k] == 0){
            int edgelen = arr[curr][k];
           mydeque.push_back(make_pair(edgelen+path ,k));
        }
      }
      sort(mydeque.begin(),mydeque.end());
    }
 }
return -1;
}

int main(){
  int tests;
  cin >> tests;
  for (int a =0; a < tests; a++)
  {
    int nodes;
  int edges;
  cin >> nodes;
  cin >> edges;
  vector < vector <int> > arr;
  arr.resize(nodes,vector<int>(nodes, -99));
  for (int j = 0 ; j < edges; j++)
  {
    int f,s,dist;
    cin >> f >> s >> dist;
    arr[f-1][s-1] = dist;
    arr[s-1][f-1] = dist;
  }
  int start;
  cin >> start;
  start = start - 1;
  vector<int> distarr;
  for (int l =0; l < nodes; l++)
  {
      if (l != start)
      {
        int ans = Dijkstra(arr, start, l);
        distarr.push_back(ans);
      }
  }
  for(int j=0;j < nodes-1 ;j++)
      {
         cout << distarr[j] << " ";
      }
  cout << endl;
  return 0;
}
}

/*
20 54
1 7 45
2 14 15
3 7 29
4 1 48
5 1 66
6 7 17
7 14 15
8 14 43
9 1 27
10 1 33
11 14 64
12 14 27
13 7 66
14 7 54
15 14 56
16 7 21
17 1 20
18 1 34
19 7 52
20 14 14
9 14 9
15 1 39
12 1 24
9 1 16
1 2 33
18 1 46
9 1 28
15 14 3
12 1 27
1 2 5
15 1 34
1 2 28
9 7 16
3 7 23
9 7 21
9 14 19
3 1 20
3 1 5
12 14 19
3 14 2
12 1 46
3 14 5
9 14 44
6 14 26
9 14 16
9 14 34
6 7 42
3 14 27
1 7 9
1 7 41
15 14 19
12 7 13
3 7 10
1 7 2
17
*/
