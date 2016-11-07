/*
 * Complete the function below.
 */
/*
	For the weighted graph:
	1. The number of nodes is <name>_nodes.
	2. The number of edges is <name>_edges.
	3. An edge exists between <name>_from[i] to <name>_to[i] and the weight of the edge is <name>_weight[i].
*/
deque<int> chose;

int Dijkstra(vector<vector<int> > arr, int start, int end){
   int nodes = arr[0].size();    
 vector<int>::iterator it;
 int pathlen = 0;
 map <int,int> vis;
 int len  = arr[0].size();
 for (int k = 0; k < len ; k++)
 {
     vis.insert(pair<int,int>(k,0));
 }
 deque<pair<int,int> >mydeque;
 mydeque.push_back(make_pair(pathlen,start));
 while(!mydeque.empty()){
    int path = mydeque.front().first;
    int curr  = mydeque.front().second;
    mydeque.pop_front();
    if (vis[curr] == 0){
      vis[curr] = 1;
      if (curr == end){
        return path;
      }
      for (int k = 0; k < len; k++)
      {
        if (arr[curr][k] != -99 && vis[k] == 0){
            int edgelen = arr[curr][k];
           mydeque.push_back(make_pair(edgelen+path ,k));
        }
      }
      sort(mydeque.begin(),mydeque.end());
      chose.push_back(mydeque[0].first);
    }
 }
return -1;
}


int minCost(int g_nodes, vector < int > g_from, vector < int > g_to, vector < int > g_weight, int start, int end, int w_extra) {
    vector < vector <int> > arr;
    arr.resize(g_nodes,vector<int>(g_nodes, -99));
      for (int j = 0 ; j < g_from.size(); j++)
      {
        int f,s,dist;
        f = g_from[j];
        s = g_to[j];
        dist = g_weight[j];
        arr[f-1][s-1] = dist;
          
        arr[s-1][f-1] = dist;
      }
     start = start - 1;
     end = end - 1;
     int wt  = Dijkstra(arr,start,end);
     if (wt > w_extra && w_extra >= 0){
         cout << "wt " << wt << " extra " << w_extra << endl;
         for (int i = 0; i < g_nodes; i++){
             for (int j  = 0; j < g_nodes ; j++){
                 cout << "testing " << i << " " << j << endl;
                if (arr[i][j] == -99){
                    //cout << "found a  candidate ----------------------  " << endl; 
                    arr[i][j] = w_extra;
                    arr[j][i] = w_extra;
                    cout << " which gave " << Dijkstra(arr,start,end) << endl;
                    if (Dijkstra(arr,start,end) < wt){
                        //cout << "----------------------------------------------found " << i << " " << j << endl;
                        wt = Dijkstra(arr,start,end);
                    }
                    else{
                       arr[i][j] = -99;
                       arr[j][i] = -99;
                    }
                }
             }
         }
     }
   
      
     return wt;

}


