/*
 * Complete the function below.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <iterator>
using namespace std;

int rep = 0;
int rep_so = 0;

int cal_rep(vector < int >& s_boys, vector < int >& s_girls){
  int temp_rep;
  int size = s_boys.size();
  for (int k = 0 ; k < size; k++){
      temp_rep += s_boys[k]*s_girls[k];
  }
  return temp_rep;    
}

void use_m(vector < int >& s_boys, vector < int >& s_girls){
   int size = s_boys.size();
   for (int i = 0 ; i < 2; i++ ){
    for (int j = 0 ; j < size; i++ ){
      int size = s_boys.size();
      if (i == 0){
          s_boys[j] += 1;
          if (cal_rep(s_boys,s_girls) > rep_so){
              rep_so = cal_rep(s_boys,s_girls);
          }
          else{
               s_boys[j] =  s_boys[j] -1;
          }
      }
      if (i == 1){
          s_girls[j] += 1;
          if (cal_rep(s_boys,s_girls) > rep_so){
              rep_so = cal_rep(s_boys,s_girls);
          }
          else{
               s_girls[j] =  s_girls[j] -1;
          }
      }
  }  
  } 
}
int flag = -99;

int maxReputation(vector < int >& s_boys, vector < int >& s_girls, int m) {
   rep = cal_rep(s_boys,s_girls);
   int size = s_boys.size();
   deque <pair <int, pair<int,int > > > my_deq;
   for (int k = 0 ; k < size; k++){
       
      int prod = s_boys[k]*s_girls[k];
      cout << "prd" << prod << endl;
       pair<int, int> foo;
      foo = make_pair(s_boys[k],s_girls[k]);
      pair <int,pair<int, int> > bar;
      bar = make_pair(prod,foo);
      my_deq.push_back(bar);
      cout << my_deq.back().first << endl;
   }
    sort(my_deq.begin(),my_deq.end());
    for (int j = size - 1; j >= 0; j--){
        cout << "srted " << my_deq[j].first << endl;
        if (m > 0){
             cout << "aaaa" << endl;
             int c1 = (my_deq[j].second.first+1)*my_deq[j].second.second;
             int c2 = (my_deq[j].second.first)*(my_deq[j].second.second+1);
             cout << "c1 " << c1 << endl;
             cout << "c2 " << c2 << endl;
            // (my_deq[j].second.first)*(my_deq[j].second.second+1));
             my_deq[j].first = max(c1 , c2);
             if (c1 > c2 && (flag == 0 || flag == -99)){
                 cout << "inc first" << endl;
                 my_deq[j].second.first++;
                 if (flag == -99){
                  flag = 0;
                 }
             } 
             else{
              my_deq[j].first = c2;
             }
             if (c1 < c2 && (flag == 1 || flag == -99)){
                cout << "inc sec" << endl;
                my_deq[j].second.second++;
                if (flag == -99){
                  flag = 1;
                 }
            }else{
              my_deq[j].first = c1;
            }
            if (c1 == c2){
                cout << "equal" << endl;
                if (flag == -99 | flag == 1){
                  my_deq[j].second.second++;
                  flag = 1;
                }
                if (flag == -99 | flag == 0){
                  my_deq[j].second.second++;
                  flag = 0;
                }
                
            }
            m--; 
             j++;
        }
    }
    for (auto el : my_deq){
       rep_so += el.first; 
    }
  
  /*while(m-- > 0){
      use_m(s_boys,s_girls);  
  }*/
  return rep_so;
}
int main (){
  int m = 2;
  vector<int> s_boys = {-1,2};
  vector<int> s_girls = {0,2};

  cout << maxReputation(s_boys,s_girls,m) << endl;
  return 0;
}

