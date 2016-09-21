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

deque < deque <char> > arr;
int rows;
int columns;
map <string,int> visited;
map <string,string> parent;
int ans_max = -999999;
int counter;
int tests;
int flag;
int waves;
int starti;
int startj;

int DFS_visit(int i, int j){
  /*for (auto el : visited){
    cout << el.first << " : " << el.second << endl;
  }

*/  deque< pair<int, int> > dirs;
  //dirs.push_back(pair<int,int>(i-1,j-1));
    dirs.push_back(pair<int,int>(i-1,j));
    //dirs.push_back(pair<int,int>(i-1,j+1));
    dirs.push_back(pair<int,int>(i,j-1));
    dirs.push_back(pair<int,int>(i,j+1));
    //dirs.push_back(pair<int,int>(i+1,j-1));
    dirs.push_back(pair<int,int>(i+1,j));
    //dirs.push_back(pair<int,int>(i+1,j+1));
    string resp = to_string(i) + "-" +to_string(j);
    cout << endl;
    flag = 0;
    cout << i << j << endl;
    if (arr[i][j] == '*'){
      flag = 1;
      cout << "FOUND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      arr[i][j] = 'S';
      for (int i =0; i < rows ; i++)
       {
        for (int j =0; j < columns; j++)
         {
            cout << arr[i][j] << " " ;
         }
         cout << endl;
       }

      return 0;

    }else{
      arr[i][j] = '/';
      for (int d =0; d < dirs.size(); d++){
          if (flag == 1){
              return 0;
           }
        int l = dirs[d].first;
        int m = dirs[d].second;
        //cout << "testing---------------------------------------------" << l << " " << m << endl;
        if (l >= 0 && m >= 0 && m < columns && l < rows && arr[l][m] != 'X'){
          string resc = to_string(l) + "-" + to_string(m);
          if (flag == 6 ){
            cout << "basic cond satisfy--------------------------------------------" << l << " " << m << endl;
            cout << "testing---------------------------------------------" << l << " " << m << endl;
          }
          
          if (arr[l][m] != 'X'  && visited[resc] != 1){ 
            cout << " INSIDE #############resc" <<resc << " ##  from ##  " << resp << endl;
            visited[resc] = 1;
            parent[resc] = resp;
            //cout << "-------------------------------------increasing by 1----------------------" << endl;
            counter++;
              DFS_visit(l,m);
          }
        }
      }
      if (counter >= 2)
      {
        waves++;
        counter = 0;
      }
    }
 /*   counter = 0;
    if (counter >  1)
    {
      ans_max = counter;
    }
    counter = 0;*/
    return 0;
}



void findreg(){
  counter = 0;
  //                           start[0]-'0',start[1]-'0'
  int zen = DFS_visit(starti, startj);
  cout << "waves" << waves << endl;
  return;
}




int main(){
  cin >> rows;
  cin >> columns;
  int K;
  int Z = 0;
  arr.resize(rows,deque<char>(columns, '0'));
  for (int i =0; i < rows ; i++)
  {
     for (int j =0; j < columns; j++)
     {
        cin >> arr[i][j];
        if (arr[i][j] == 'M'){
          starti = i;
          startj = j;
        }
        cout << "i wan more" << endl;
        Z++;
        cout << "Z" << Z << endl; 

     }
     cout << endl; 
  }
  cin >> K;
  cout << "ok";
  cout << K << endl;
  cout << endl;
  cout << endl;
  for (int i =0; i < rows ; i++)
   {
    for (int j =0; j < columns; j++)
     {
      string res = to_string(i) + "-" +to_string(j);
        visited.insert(pair<string,int>(res,-99));
        parent.insert(pair<string,string>(res,"0"));
        cout << arr[i][j] << " " ;
     }
     cout << endl;
   }
   cout << endl;
   parent["00"] = "00";
   findreg();
   cout << ans_max << endl;

  for (int i =0; i < rows ; i++)
       {
        for (int j =0; j < columns; j++)
         {
            cout << arr[i][j] << " " ;
         }
         cout << endl;
       }

  return 0;
}
