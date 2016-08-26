#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <iterator>
using namespace std;

string BFS_shortest(vector<vector<int> > arr, int start, int nodes)
{
  map <int,int> level;
  map <int, int> parent;
  deque <int> frontier;
  for (int k = 0; k < nodes; k++)
   {
       level.insert(pair<int,int>(k,-99));
   }
   level[start] = 0;
  parent.insert(pair<int,int>(start, -99));
  frontier.push_back(start);
  int i =1;
  while(!frontier.empty()){
      deque <int> next;
      for (int k = 0; k < frontier.size(); k++)
      {
      int u = frontier[k];
      for (int k = 0; k < nodes; k++) ///for adjacents of u
        {
          if (arr[u][k] != -99 && level[k] ==  -99)
          {

              level[k] = i;
              parent.insert(pair<int,int>(k, u));
              next.push_back(k);
          }
        }
      }
      frontier = next;
      i++;
  }
  vector <int> reach;
  for (int z = 0; z < nodes; z++)
  {
    if ( z != start && parent.find(z) != parent.end())
    {
      int i =0;
      int checker = 0;
      int temp;
      temp = z;
      while(parent[temp] != -99)
      {
        i++;
        checker = 1;
        temp = parent[temp];
      }
      int el = 6 * i ;
      if (checker == 0)
      {
        el = -1;
      }
      reach.push_back(el);
    }
    if (parent.find(z) == parent.end())
    {
      reach.push_back(-1);
    }
  }
  for(auto elem : reach)
      {
         cout << elem << " ";
      }
      cout << endl;

  return "voila";
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int queries;
    cin >> queries;

    for (int j =0 ; j < queries; j++)
    {
      int nodes;
      int edges;
      vector < vector<int> > rolex;
      cin >> nodes >> edges;
      rolex.resize(nodes,vector<int>(nodes, -99));
      for (int k =0; k < edges; k++)
      {
        int f,s;
        cin >> f >> s;
        rolex[f-1][s-1] = 6;
        rolex[s-1][f-1] = 6;
      }
      int start;
      cin >> start;
      start = start -1;
      string s = BFS_shortest(rolex,start,nodes);
    }
    return 0;
}
