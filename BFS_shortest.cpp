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

/*2
4 2
1 2
1 3
1
3 1
2 3
2*/
string BFS_shortest(vector<vector<int> > arr, int start, int nodes)
{
  cout << "BFS";
  map <int,int> level;
  map <int, int> parent;
  deque <int> frontier;
  level.insert(pair<int,int>(start,0));
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
          if (arr[u][k] != -99 && level[k] == 0)
          {

              level.insert(pair<int,int>(k, i));
              parent.insert(pair<int,int>(k, u));
              next.push_back(k);
          }
        }
      }
      frontier = next;
      i++;
  }
  for(auto elem : parent)
      {
         std::cout << elem.first << " " << elem.second << " " << "\n";
      }
  return "voila";
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int queries;
    cin >> queries;

    for (int j =0 ; j < queries; j++)
    {
      cout << "Another Query ?? " <<endl;
      int nodes;
      int edges;
      vector < vector<int> > rolex;
      cin >> nodes >> edges;
      rolex.resize(nodes,vector<int>(nodes, -99));
      for (int k =0; k < edges; k++)
      {
        cout << "in For loop for edge           " <<endl;
        int f,s;
        cin >> f >> s;
        rolex[f-1][s-1] = 6;
        rolex[s-1][f-1] = 6;
      }
      int start;
      cin >> start;
      cout << "Out of getting edge and got Start--->  " << start << endl;
      start = start -1;
      string s = BFS_shortest(rolex,start,nodes);
      cout << "ANS " << s ;
    }
    return 0;
}
