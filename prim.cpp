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
map<int,pair<int,int> > mymap;
map<int,pair<int,int> >::iterator it;
deque <int> nodes;

int main() {
    
  int nodeno;
  int edges;
  cin >> nodeno;
  cin >> edges;
  for (int j = 0 ; j < edges; j++)
  {
    int f,s,dist;
    cin >> f >> s >> dist;
    mymap[dist] = pair<int,int>(f,s);
  }
  int start;
  cin >> start;
  for (auto elem : mymap){
  	cout << elem.first << ": " << elem.second.first << " " << elem.second.second << endl;
  } 
  
  int sum = 0; 
  it = mymap.begin();

  while (!mymap.empty()){
  	it = mymap.begin();
    //sum = sum + it->first;
    int prevsize = nodes.size();
    nodes.push_back(it->second.first);
    nodes.push_back(it->second.second);  
    sort(nodes.begin(), nodes.end());
    nodes.erase( unique(nodes.begin(),nodes.end()), nodes.end());
    if (nodes.size() > prevsize)
    {
       sum = sum + it->first;
    }
  	mymap.erase (it->first);
  }
  cout << sum;


    return 0;
}