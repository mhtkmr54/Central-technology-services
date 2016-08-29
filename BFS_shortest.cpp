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
  //cout << "BFS" << endl;
  map <int,int> level;
  map <int, int> parent;
  deque <int> frontier;
  for (int k = 0; k < nodes; k++)
   {
       level.insert(pair<int,int>(k,-99));
       //cout << k << "  "<<" has level ---  " << level[k] << endl;
   }
   level[start] = 0;
  parent.insert(pair<int,int>(start, -99));
  frontier.push_back(start);
  int i =1;
/*  for (int i =0; i < nodes ; i++)
  {
     for (int j =0; j < nodes; j++)
     {
        cout << arr[i][j] << " ";
     }
     cout << endl;
  }*/
/*  cout << "parent" << endl;
  for(auto elem : parent)
      {
         std::cout << elem.first << " " << elem.second << " " << "\n";
      }

  cout << "level" << endl;
  for(auto elem : level)
      {
         std::cout << elem.first << " " << elem.second << " " << "\n";
      }*/

 while(!frontier.empty()){
/*      cout << "BFS FRONTIER" << endl;
      for(auto elem : frontier)
      {
         std::cout << elem << endl;
      }*/
      deque <int> next;
      //cout << "---------------------------------------------------in While" << endl;
      for (int k = 0; k < frontier.size(); k++)
      {
      int u = frontier[k];
      for (int k = 0; k < nodes; k++) ///for adjacents of u
        {
          //cout << "going 4 chk" << k << endl;
          if (arr[u][k] != -99 && level[k] ==  -99)
          {

              level[k] = i;
              parent.insert(pair<int,int>(k, u));
              //cout << "node going into next  " << k << endl;
              next.push_back(k);
          }
        }
      }
      //cout << "Next Elements which will become frontier " << endl;
/*      for(auto elem : next)
      {
         cout << "next el "<< elem << " ";
      }
      cout << "parent when a new frontier is to be set" << endl;
      for(auto elem : parent)
      {
         std::cout << elem.first << " " << elem.second << " " << "\n";
      }*/

      //cout << "level parent when a new frontier is to be set" << endl;
/*      for(auto elem : level)
      {
         std::cout << elem.first << " " << elem.second << " " << "\n";
      }
      cout << endl;*/
      frontier = next;
      i++;
  }
  vector <int> reach;
  for (int z = 0; z < nodes; z++)
  {
    //cout << "z  "  << z << endl;
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

  cout << "reach "<< endl;
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
      //cout << "Another Query ?? " <<endl;
      int nodes;
      int edges;
      vector < vector<int> > rolex;
      cin >> nodes >> edges;
      rolex.resize(nodes,vector<int>(nodes, -99));
      for (int k =0; k < edges; k++)
      {
        //cout << "in For loop for edge           " <<endl;
        int f,s;
        cin >> f >> s;
        rolex[f-1][s-1] = 6;
        rolex[s-1][f-1] = 6;
      }
      int start;
      cin >> start;
      //cout << "Out of getting edge and got Start--->  " << start << endl;
      start = start -1;
      //cout << "The Start is set to be--->  " << start << "now calling BFS" << endl;
      string s = BFS_shortest(rolex,start,nodes);
      //cout << "BFS CALLED"<< endl;
      //cout << "ANS " << s;
    }
    return 0;
}
