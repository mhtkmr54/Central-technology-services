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

deque<pair<int,pair<int,int> > > mymap;
deque<pair<int,pair<int,int> > >::iterator it;
int nodes;
int edgesno;
deque<pair<int,int> >edges;
map<string,int> check;
deque <int> selected;
vector< vector<int> > graph;
map <int,int> visited;
int omega  = 0;
//int flag;
int to_add;
int so;
int dt;

// A utility function to find the subset of an element i
int find(map<int,int>& parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
 
// A utility function to do union of two subsets 
void Union(map<int,int>& parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int find_union(){ // KRUSKAL O(MLOGN)
  map<int,int> parent;
  for (int k =0; k < nodes; k++){
      parent[k] = -1;
   }
  for (auto el : edges){
     int x  = find(parent, el.first);
     int y  = find(parent, el.second);
     if (x == y){
      return 1;
     }
     Union(parent , x, y);
  }

  return 0; 
}

int main() {
  cin >> nodes;
  cin >> edgesno;
  for (int j = 0 ; j < edgesno; j++)
  {
    int f,s,dist;
    cin >> f >> s >> dist;
    mymap.push_back(make_pair(dist,pair<int,int>(f,s)));
  }
  int start;
  sort(mymap.begin(),mymap.end());
  
  int sum = 0; 
  
  // set for cycles detect-----------------------
  graph.resize(nodes,vector<int>(nodes, -99));

  //-------------------------------------------------

  while (selected.size() != nodes - 1){
  	  to_add = mymap[0].first;
      so = mymap[0].second.first;
      dt = mymap[0].second.second;
      edges.push_back(make_pair(so,dt));
      mymap.erase(mymap.begin());
      int omega = find_union();
      if (omega == 1){
           edges.pop_back();
           cout << "cycle detected" << endl;
      }else{
         sum += to_add;
         selected.push_back(0);
      } 
  }
  cout << "SUMMM" << sum << endl;


    return 0;
}