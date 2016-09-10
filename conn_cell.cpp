#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <iterator>
#include <string>


using namespace std;

deque < deque <int> > arr;
int rows;
int columns;
map <string,int> visited;
map <string,string> parent;
int ans_max = -999999;
int counter;

void DFS_visit(int i, int j){
	for (auto el : visited){
		cout << el.first << " : " << el.second << endl;
	}
	deque< pair<int, int> > dirs;
	dirs.push_back(pair<int,int>(i-1,j-1));
    dirs.push_back(pair<int,int>(i-1,j));
    dirs.push_back(pair<int,int>(i-1,j+1));
    dirs.push_back(pair<int,int>(i,j-1));
    dirs.push_back(pair<int,int>(i,j+1));
    dirs.push_back(pair<int,int>(i+1,j-1));
    dirs.push_back(pair<int,int>(i+1,j));
    dirs.push_back(pair<int,int>(i+1,j+1));
    string resp = to_string(i) + to_string(j);


     for (int d =0; d < dirs.size(); d++){
      int l = dirs[d].first;
      int m = dirs[d].second;
      cout << "testing---------------------------------------------" << l << " " << m << endl;
	  if (l >= 0 && m >= 0 && m < columns && l < rows){
	    	string resc = to_string(l) + to_string(m);
	    	cout << "basic cond satisfy--------------------------------------------" << l << " " << m << endl;
	    	if (arr[l][m] == 1 && visited[resc] != 1){ 
	    		cout << "################################################# INSIDE #############resc" <<resc << " ##  from ##  " << resp << endl;
	    		visited[resc] = 1;
	    		parent[resc] = resp;
	    		cout << "-------------------------------------increasing by 1----------------------" << endl;
	    		counter++;
	    	    DFS_visit(l,m);
	    		
	    	}
	    }
    }

    return;

}



void findreg(){
  for (int i =0; i < rows ; i++)
   {
    for (int j =0; j < columns; j++)
     {
        string rest = to_string(i) + to_string(j);
        if (visited[rest] == -99 && arr[i][j] == 1){
        	visited[rest] = 1;
        	counter = 1;
        	DFS_visit(i,j);
        	if (counter >  ans_max){
        		ans_max = counter;
        	}
        	counter = 0;
        }

     }
   }
 

	return;
}







int main(){
 
  cin >> rows;
  cin >> columns;
  
  arr.resize(rows,deque<int>(columns, 0));
  for (int i =0; i < rows ; i++)
  {
     for (int j =0; j < columns; j++)
     {
        cin >> arr[i][j];
     }
  }
  cout << endl;
  cout << endl;
  for (int i =0; i < rows ; i++)
   {
    for (int j =0; j < columns; j++)
     {
     	string res = to_string(i) + to_string(j);
        visited.insert(pair<string,int>(res,-99));
        parent.insert(pair<string,string>(res,""));
        cout << arr[i][j] << " " ;
     }
     cout << endl;
   }
   cout << endl;
   parent["00"] = "00";
   findreg();
   cout << ans_max << endl;
	return 0;
}
