#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>


using namespace std;
int flag = 0;

int size;

int BFS(int m , int n, deque < deque <char> > arr, int R, int C)
{
   map <string,int> level;
   map <string, string> parent;
   deque <pair<int,int> >  frontier;
   string res = to_string(m) + "-" + to_string(n);
   level[res] = 0;
    frontier.push_back(make_pair(m,n));
   int i =1;
   deque< pair<int, int> > dirs;
   while(!frontier.empty()){
      deque <pair<int,int> >  next;
      for (int k = 0; k < frontier.size(); k++)
      {
      int m = frontier[k].first;
      int n = frontier[k].second;
      deque< pair<int, int> > dirs;
      dirs.push_back(pair<int,int>(m-1,n));
      dirs.push_back(pair<int,int>(m,n-1));
      dirs.push_back(pair<int,int>(m,n+1));
      dirs.push_back(pair<int,int>(m+1,n));
      for (int d =0; d < dirs.size(); d++){
       int p = dirs[d].first;
       int q = dirs[d].second;
       string resc = to_string(p) + "-" + to_string(q);
         if (p >= 0 && q >= 0 && p < R && q < C){
          //cout << "vis " << p << q << " " << arr[p][q] << endl;
           if (arr[p][q] == '.' || arr[p][q] == 'P'){ 
            
          if (level.find(resc) == level.end())
          { 
              level[resc] = i;
              if (arr[p][q] == 'P'){
                flag = 1;
                //cout << p << q <<  " savsdbjh" << endl; 
                return i;
              }
              parent[resc] = res;
              next.push_back(make_pair(p,q));
          }
        }
      }
    }
  }
      frontier = next;
      i++;
      //cout << "----------------------------" << i << endl;
  }
  return 0;
}


int main(){
  int T;
  deque<int> answer;
  cin >> T;
 
   while(T-- > 0) {
     int R;
     int C;
    deque < deque <char> > arr;
    deque < deque <int> > the_deal;
     cin >> R >> C;
     arr.resize(R,deque<char>(C, 'O'));
     the_deal.resize(R,deque<int>(C, 0));
     for (int i =0; i < R ; i++)
     { 
     for (int j =0; j < C; j++)
     {
        cin >> arr[i][j];
     }
     }


    int moves = 0;
     for (int i =0; i < R ; i++)
     { 
     for (int j =0; j < C; j++)
     {
        if (arr[i][j] == 'M'){
           moves = BFS(i,j, arr, R, C);
           if(flag == 1){
            answer.push_back(moves);
           } 
           else{
            answer.push_back(-1);
           }
          //the_deal[i][j] = lvl;
        }
     }
     }
     flag = 0;
     

}
       for (int k =0; k < answer.size(); k++){
      cout << answer[k] << endl;
     }
     return 0;
}