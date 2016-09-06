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

map<int,int> check;
map<int,int> children;
map<int,int> level;
map <int,int> parent;
deque<int> frontier;
deque<int>::iterator it;
deque< deque<int> > graph;
int start, lvl, temp;
int nodes, edges, buff;

void geteven(){
   for (int k = 0; k < nodes; k++)
   {
       level.insert(pair<int,int>(k,-99));
   }
   level[start] = 0;
   parent.insert(pair<int,int>(0,-1));
   frontier.push_back(start);
   lvl = 1; 


   while (!frontier.empty()){
   deque<int> next;
   for (int z =0 ; z< frontier.size(); z++){
   int curr_node = frontier[z];
   check[curr_node] = 1;
		   for (int m =0 ; m< nodes; m++){
		   	    if (graph[curr_node][m] != -99 && check[m] == 0){
		   	    	next.push_back(m);
		            level[m] = lvl;
		            parent[m] = curr_node;
		   	    }
		   }
   }
   lvl++;
   frontier = next;
   //delete next;
   }

	return;
}

int DFS_visit(int j){
   for (int d =0; d < nodes; d++){
   	 cout << graph[j][d] << " " << check[d] << " " << "parent of " << d << " is  " <<  parent[d] <<endl;
   	 cout << "looking reachable d from curr " << j << endl;
     if (graph[j][d] != -99 && check[d] == 0 && parent[d] == -99)
     {
        cout << "FOUND     " << d << "  from this  "<< j << endl;
          cout << "inc temp" << endl;
          parent[d] = j;
          temp++;
          cout << "now temp is " << temp << endl;
          DFS_visit(d);
          cout << "----------------AFTER---------------" << endl;
     }
    }
    return temp;
}




void DFS(){
  for (int k = 0; k < nodes; k++)
	   {
	       check[k] = 0;
	   }
  for (int j =0; j < nodes; j++){
  	  for (int k = 0; k < nodes; k++)
	   {
	       parent[k] = -99;
	   }
      //for each node fresh parent and fresh temp (#child + 1(curr node))
      temp = 1;
	  cout << " --------------------  checking for ------------------" << j << endl;
	  for (auto el : check){
	  	cout << el.first << " :  "<<el.second << endl;
	  }
      check [j] = 1;
      temp =  DFS_visit(j);
      cout << "j has " << temp << "childs" << endl;
      children[j] = temp;

      for (int k = 0; k < nodes; k++)
	   {
	       parent[k] = -99;
	   }
     /*}*/

  }
  return;
}

int main(){
	cin >> nodes >> edges ;
	graph.resize(nodes,deque<int>(nodes,-99));
	int s, d, dist;
	for (int j = 0; j < edges; j++){
		cin >> s >> d ;
		graph[s-1][d-1] = 1;
		graph[d-1][s-1] = 1;
	}
	start = 0;
    for (int k = 0; k < nodes; k++)
	 {
       check.insert(pair<int,int>(k,0));
	 }
    geteven();


    for (auto elem : parent){
    	cout << "parent of  " << elem.first << ": " << elem.second << endl;
    }
    cout << endl;
    cout << endl;
    for (auto elem : level){
    	cout << "lvl of  " << elem.first << ": " << elem.second << endl;
    }
    
    //prep for dfs

    for (int k = 0; k < nodes; k++)
	   {
	       parent[k] = -99;
	   }
	 parent[start] = -1;

	cout << "check parent b4 dfs call" << endl;
    for (auto el : parent){
	  	cout << el.first << " :  "<<el.second << endl;
	  }
    DFS();
    for (auto elem : children){
    	cout << "has child of  " << elem.first << ": " << elem.second << endl;
    }

	return 0;
}