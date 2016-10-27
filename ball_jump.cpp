#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque < deque <int> > arr;
deque < deque <int> > vis;
int R,C;
int icount = 0;

void DFS_visit(int i, int j, int& icount){
    vis[i][j] = 1;
    pair<int,int> foo;
    int min_ = 99999999;
    deque< pair<int, int> > dirs;
    dirs.push_back(pair<int,int>(i-1,j));
    dirs.push_back(pair<int,int>(i,j-1));
    dirs.push_back(pair<int,int>(i,j+1));
    dirs.push_back(pair<int,int>(i+1,j));
    for (int d =0; d < dirs.size(); d++){
       int l = dirs[d].first;
       int m = dirs[d].second;
       if (l >= 0 && m >= 0 && m < C && l < R){
            cout << "out core" << l << " " << m << " " << arr[l][m] << endl;
            if (arr[l][m] < min_ && vis[l][m] == 0 && arr[l][m] < arr[i][j]){
            cout << "innr core" << endl;
             min_ =  arr[l][m];
             foo = make_pair(l,m);
            }
       }
    }
    if (min_ != 99999999){
      cout << "CHOSEN ONE " <<  foo.first << " " << foo.second << " " << arr[foo.first][foo.second] << endl;
      icount = icount + 1;
      DFS_visit(foo.first, foo.second, icount);
    }
    else{
      return;
    }
	return;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T-- > 0){
          cin >> R >> C;
          arr.resize(R,deque<int>(C, 0));
          vis.resize(R,deque<int>(C, 0));
           for (int i =0; i < R ; i++)
           { 
           for (int j =0; j < C; j++)
           {
              cin >> arr[i][j];
           }
           }
          
          DFS_visit(1,2,icount);
          cout << " icount " << icount + 1 << endl; 
    }
    return 0;
}
