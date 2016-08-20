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

using namespace std;

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



  return 0;
}

