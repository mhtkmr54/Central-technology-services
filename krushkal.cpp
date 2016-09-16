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
int edges;

map<string,int> check;
deque <int> selected;
vector< vector<int> > graph;
map <int,int> visited;
map <int,int> parent;
int omega  = 0;
//int flag;
int to_add;
int so;
int dt;



void DFS_visit(int j, int temp){
   cout << "checking " << j <<  endl;   
   cout << "-----------------------------checlk" << endl;
   for (auto elem : check){
    cout << elem.first << " : " << elem.second << endl;
   }
   cout << "end end end ------------------------" << endl;
   for (int d =0; d < nodes; d++){
     if (graph[j][d] != -99)
     {
       cout << "now that we know that the are connected  " << j << " and " << d << " " << endl;
       if (visited[d] == -99){
          cout << "reachi  to " << d << " whose parent is " << endl;
          parent[d] = j;
          cout << parent[d] << endl;
          visited[d] = 1;
          DFS_visit(d,temp);
        }
        else if (visited[d] == 1 && j != parent[d]){
          cout << "MUST BE A CYCLE  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ " << endl;
        }
     }
    }
    return;
}

// need pre decl of visited (0,-99)and parent(0,-99) 

void DFS(){
  for (int j =0; j < nodes; j++){
     cout << "FOR J  " << j << endl;
     if (visited[j] == -99)
     { 
      visited[j] = 1;
      int temp = j;
      DFS_visit(j,temp);
      //flag = 0;
     }

  }
  return;
}


int main() {
  cin >> nodes;
  cin >> edges;
  for (int j = 0 ; j < edges; j++)
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
  for (int j =0; j < nodes; j++){
       visited[j] = -99;
    }
  for (int k =0; k < nodes; k++){
      parent[k] = -99;
   }
   parent[0] = -1;
  //-------------------------------------------------

  while (selected.size() != nodes - 1){
     omega = 0;
      cout << "-------------MyMAp --While Start---" << endl;  
      for (auto el : mymap){
        cout << el.first << " : " << el.second.first << "  " << el.second.second << endl;
      }
      cout << "-------------- b4 Top off------------" << endl;
  	  to_add = mymap[0].first;
      so = mymap[0].second.first;
      dt = mymap[0].second.second;
      mymap.erase(mymap.begin());
      graph[so][dt] = to_add;
      graph[dt][so] = to_add;
      cout << "##############################################Checking for edge " << so << " : "<< dt << " with wt " << to_add << endl;
      DFS();
      if (omega == 1){
           for (int i =0; i < nodes ; i++)
            {
               for (int j =0; j < nodes; j++)
               {
                  cout << graph[i][j] << " ";
               }
               cout << endl;
            }
         graph[so][dt] = -99;
         graph[dt][so] = -99;
        cout << "cycle detected" << endl;
      }else{
         sum += to_add;
         selected.push_back(1);
      }
  for (int j =0; j < nodes; j++){
    visited[j] = -99;
    }
/*  for (int j =0; j < nodes; j++){
      parent[j] = -99;
   }*/
  parent[0] = -1;
  }
  cout << "SUMMM" <<sum << endl;


    return 0;
}