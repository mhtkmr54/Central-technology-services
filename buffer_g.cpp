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
typedef long long int lli;
typedef pair<int,int> pii;
map<lli,lli> check;
//keps trk of min reachable
//deque<lli> nodetrk;
deque<lli> vis;
deque<lli>::iterator it;
deque< deque<lli> > graph;
lli start, pos;
lli nodes, edges;
lli Sum = 0;
lli curr_min;
lli counter = 1;

bool Compare(pii a, pii b)
{
    return a.first > b.first;//max
    //return a.time_to_prep > b.time_to_prep;//min heap ??
}

priority_queue<pii, vector<pii>, std::function<bool(pii a, pii b)> > nodetrk(Compare);

void Primsalgo(){
    while (counter != nodes + 1 ){
       //cout << "ins w" << endl;
/*       lli curr_min = 99999999;
       for (lli l = 0; l < nodes; l++){
          if(nodetrk[l] < curr_min && check[l] == 0){
          	pos = l;
          	curr_min = nodetrk[l];
          }
       }*/
        pos = nodetrk.top().second;
        Sum += nodetrk.top().first;
	      check[pos] = 1;
	      for (lli k = 0; k < nodes; k++)
	       {
		        if (graph[pos][k] != -99 && check[k] == 0 && graph[pos][k] <  nodetrk[k].first){
	                     nodetrk[k].first = graph[pos][k];
		    	}
		    }
    counter++;   
    }
	return;
}



int main(){
	cin >> nodes >> edges ;
	graph.resize(nodes,deque<lli>(nodes,99999999));
	lli s, d, dist;
	for (lli j = 0; j < edges; j++){
		cin >> s >> d >> dist;
		if (graph[s-1][d-1] > dist && graph[d-1][s-1] > dist){
          graph[s-1][d-1] = dist;
		  graph[d-1][s-1] = dist;
		}
		
	}
	lli start = 1;
	start = start -1;
	
	
	pii foo = make_pair(0,0);
	
    for(int k =1; k < nodes ; k++){
    	pii foo = make_pair(99999999,k);
    }
    
    for (lli k = 0; k < nodes; k++)
	 {
       check.insert(pair<lli,lli>(k,0));
	 }
    Primsalgo();
/*    for (auto el : nodetrk){
    	cout << el << endl;
    }*/
    //sort(nodetrk.begin(), nodetrk.end());
    nodetrk.pop();
    //reverse(nodetrk.begin(), nodetrk.end());
    lli S;
    cin >> S;
    deque <lli> replac;
    while(S-- > 0){
      lli el;
      cin >> el;
      replac.push_back(el);
    }
    int len = nodetrk.size();
    sort(replac.begin(), replac.end());
    for (lli it = 0; it < nodetrk.size(); it++){
    	if (it < replac.size()){
         if(nodetrk[len-1-it] > replac[it]){
    		swap(nodetrk[len-1-it], replac[it]);
    	  }
    	}
 
    }
    lli lat = 0;
    for(auto e : nodetrk){
       lat += e;
    }
    cout << lat << endl;
	return 0;
}