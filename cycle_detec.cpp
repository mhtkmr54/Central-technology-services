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

vector< vector<int> > graph;
int nodes;
map <int,int> visited;
map <int,int> parent;


void DFS_visit(int j, int temp){
   for (int d =0; d < nodes; d++){
     if (graph[j][d] != -99)
     {
        if (j==temp){
          cout << "cycle detected" << endl; //if two time pinted then ob cycle coz first time it will ob prnt
        }
        if (parent[d] == -99){
          parent[d] = j;
          visited[d] = 1;
          DFS_visit(d,temp);
        }
     }
    }
    return;
}


void DFS(){
  for (int j =0; j < nodes; j++){
     if (visited[j] == -99)
     {
      visited[j] == 1;
      int temp = j;
      DFS_visit(j,temp);
     }

  }
  return;
}

/*<!--------------------------------------------------------graph[f-1][s-1]--SEG------------------>*/
int main(){
  int tests;
  cin >> tests;
  int edges;
  for (int k =0; k<tests; k++)
  {
    cin >> nodes >> edges;
    graph.resize(nodes,vector<int>(nodes, -99));

    for (int i =0; i<edges; i++)
    {
      int f,s;
      cin >> f >> s;
      graph[f-1][s-1] = 1;
      graph[s-1][f-1] = 1;
    }
    for (int j =0; j < nodes; j++){
    visited.insert(pair<int,int>(0,-99));
    }
    for (int j =0; j < nodes; j++){
      parent.insert(pair<int,int>(0,-99));
      }
    DFS();

  }

  }
