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
#define R 8
#define C 8

deque<int> vis;
deque<bool> inStack;
deque<int> order;
deque< deque<int> > graph;

void dfs(int x, int parent){
    vis[x] = 1;
    inStack[x] = true;
    for(int u = 0; u < R; u++) {
        if (graph[x][u] == 1 && u != parent && vis[u] == 1 && inStack[u]) {
            // there is a cycle: u -> ... -> parent -> x
            cout << "threre is cycle " << x << " to " << u << endl;
        }
        if(vis[u] == 0 && graph[x][u] == 1) {
            dfs(u, x);
        }
    }
    vis[x] = 2;
    inStack[x] = false;
    order.push_back(x);
}

int main(){
    vis.resize(C, 0);
    inStack.resize(C, false);
    graph.resize(R,deque<int>(C, 0));
    int edges;
    cin >> edges;
   for (int j = 0 ; j < edges; j++)
   {
    int f,s;
    cin >> f >> s;
    graph[f-1][s-1] = 1;
    //graph[s-1][f-1] = 1;
   }
   for(int i = 0; i < C; i++){
   	if(vis[i] == 0){
   		dfs(i,99);
   	}
   }
   //	dfs(0,99);
   for(auto el : order){
   	cout << el << " ";
   }
   cout << endl;
	return 0;
}

