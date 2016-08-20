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

vector<int> Dijkstra(vector<vector<int> > arr, int start, int end, vector<int> distarr){
 vector<int>::iterator it;
 string path;
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
      distarr[curr] = path;
      vis[curr] = 1;
      if (curr == end){
        string ans  = to_string(path);
              for(auto elem : distarr)
              {
                 if (elem == -1)
                 {
                   it=find(distarr.begin(),distarr.end(),-1);
                   auto pos = it - distarr.begin();
                   distarr = Dijkstra (arr,start,pos,distarr);
                 }
              }
        return distarr;
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
return distarr;
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
  vector <int> distarr;
  distarr.resize(nodes,-1);
  distarr = Dijkstra (arr,start,nodes-1,distarr);
  int l =0;
  for(auto elem : distarr)
      {
         if (l != start)
         {
           cout << elem << " ";
         }
        l++;
      }
  }
  return 0;
}

