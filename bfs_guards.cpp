#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>


using namespace std;

deque < deque <char> > arr;
deque < deque <int> > the_deal;
int size;

int BFS(int m , int n)
{
  map <string,int> level;
  map <string, string> parent;
  deque <pair<int,int> >  frontier;
  string res = to_string(m) +to_string(n);
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
       string resc = to_string(p) +to_string(q);
         if (p >= 0 && q >= 0 && p < size && q < size){
       	   if (arr[p][q] == 'O' | arr[p][q] == 'G' ){ 
          if (level.find(resc) == level.end())
          {
              level[resc] = i;
              if (arr[p][q] == 'G'){
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
  }
  return 0;
}


int main(){
     cin >> size;
     arr.resize(size,deque<char>(size, 'O'));
     the_deal.resize(size,deque<int>(size, 0));
     for (int i =0; i < size ; i++)
     { 
     for (int j =0; j < size; j++)
     {
        cin >> arr[i][j];
     }
     }

   for (int i =0; i < size ; i++)
     { 
     for (int j =0; j < size; j++)
     {
        if (arr[i][j] == 'O'){
        	int lvl = BFS(i,j);
          the_deal[i][j] = lvl;

        }
       if (arr[i][j] == 'W'){
          the_deal[i][j] = -1;
        }
      if (arr[i][j] == 'G'){
          the_deal[i][j] = 0;
        }

     }
     }
     cout << endl;
          for (int i =0; i < size ; i++)
     { 
     for (int j =0; j < size; j++)
     {
        cout << the_deal[i][j] << " ";
     }
     cout << endl;
     }
     cout << endl;

	return 0;
}

