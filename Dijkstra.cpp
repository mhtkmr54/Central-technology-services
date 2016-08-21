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

string Dijkstra (vector<vector<int> arr, int start, int end)
{
 string path;
 int pathlen = 0;
 map <int,int> vis;
 int len  = arr[0].size()
 deque<pair<int,int> >mydeque;
 mydeque.push_back(make_pair(pathlen,start);
 int pathlen =0;
 int min_compare = 9999999;
 while(!mydeque.empty())
 {
    for( auto elem : mydeque )
    {
      cout << "( "<<elem.first << " " << elem.second << " " << " )" << endl;
    }
    int path = mydeque.pop_front().first;
    int curr  = mydeque.pop_front().second;
    if (vis[curr] == 0)
    {
      vis.insert(pair(curr,pathlen));
      for (int k = 0; k < len; k++)
      {
        if (arr[curr][k] != -99 )
        {
            edgelen = arr[curr][k];
            if (vis[k] == 0){
              mydeque.push_back(make_pair(edgelen+path ,k));
            }
        }
      }
      sort(mydeque.begin(),mydeque.end());
    }



 }

}

int main(){
  int nodes;
  int edges;
  cin >> nodes;
  cin >> edges;
  cout << "edges" << edges << endl;
  cout << "nodes" << nodes << endl;
  //vector < vector<pair<int,int> > > myvecofvec(n);
  vector < vector <int> > arr;
  arr.resize(nodes,vector<int>(nodes, -99));

  cout << "b4" << endl;

  for (int i =0; i < nodes ; i++)
  {
     for (int j =0; j < nodes; j++)
     {
        cout << arr[i][j] << " ";
     }
     cout << endl;
  }
  cout << endl;


  for (int j = 0 ; j < edges; j++)
  {
    int f,s,dist;
    cin >> f >> s >> dist;
    arr[f-1][s-1] = dist;
    arr[s-1][f-1] = dist;
  }

  for (int i =0; i < nodes ; i++)
  {
     for (int j =0; j < nodes; j++)
     {
        cout << arr[i][j] << " ";
     }
     cout << endl;
  }
  cout << endl;
  Dijkstra (arr,0,nodes-1);


  return 0;
}

