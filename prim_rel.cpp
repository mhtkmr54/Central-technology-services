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
//keps trk of min reachable
deque<int> nodetrk;
deque<int> vis;
deque<int>::iterator it;
deque< deque<int> > graph;
int start, pos;
int nodes, edges;
int Sum = 0;
int curr_min;
int counter = 1;


void Primsalgo(){
    while (counter != nodes + 1 ){
       //cout << "ins w" << endl;
       int curr_min = 99999999;
       for (int l = 0; l < nodes; l++){
          if(nodetrk[l] < curr_min && check[l] == 0){
          	pos = l;
          	curr_min = nodetrk[l];
          }
       }
        Sum += curr_min;
	    check[pos] = 1;
	    for (int k = 0; k < nodes; k++)
	       {
		        if (graph[pos][k] != -99 && check[k] == 0 && graph[pos][k] <  nodetrk[k]){
	                     nodetrk[k] = graph[pos][k];
		    	}
		    }
    counter++;   
    }
	return;
}



int main(){
	cin >> nodes >> edges ;
	graph.resize(nodes,deque<int>(nodes,-99));
	int s, d, dist;
	for (int j = 0; j < edges; j++){
		cin >> s >> d >> dist;
		graph[s-1][d-1] = dist;
		graph[d-1][s-1] = dist;
	}
	cin >> start;
	start = start -1;
    nodetrk.resize(nodes,99999999);
    nodetrk[start] = 0;
    for (int k = 0; k < nodes; k++)
	 {
       check.insert(pair<int,int>(k,0));
	 }
    Primsalgo();
    cout << Sum;
	return 0;
}