#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque < deque <char> > arr;
deque < deque <int> > vis;
int size;

void DFS_visit(int i, int j){
    vis[i][j] = 1;
    deque< pair<int, int> > dirs;
    dirs.push_back(pair<int,int>(i-1,j));
    dirs.push_back(pair<int,int>(i,j-1));
    dirs.push_back(pair<int,int>(i,j+1));
    dirs.push_back(pair<int,int>(i+1,j));
    for (int d =0; d < dirs.size(); d++){
       int l = dirs[d].first;
       int m = dirs[d].second;
       if (l >= 0 && m >= 0 && m < size && l < size){
       	   if (arr[l][m] == 'Y'  && vis[l][m] == 0){ 
       	    DFS_visit(l,m);
       	   }

       }
    }
	return;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin >> size;
    arr.resize(size,deque<char>(size, '0'));
    vis.resize(size,deque<int>(size, 0));
     for (int i =0; i < size ; i++)
     { 
     for (int j =0; j < size; j++)
     {
        cin >> arr[i][j];
     }
     }
     int count = 0;
     for (int i =0; i < size ; i++)
     { 
     for (int j =0; j < size; j++)
     {
        if (arr[i][j] == 'Y' and vis[i][j] == 0 ){
        	count += 1;
        	DFS_visit(i,j);
        }

           for (int i =0; i < size ; i++){ 
           for (int j =0; j < size; j++){
              cout << vis[i][j] << " ";

            }
            cout << endl;
           }
           cout << endl;


     }
     }
     cout << count << endl;
    return 0;
}
