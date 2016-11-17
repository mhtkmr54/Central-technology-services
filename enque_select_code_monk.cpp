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
#include <initializer_list>

using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
map<char,int>::iterator it;

int main(){
	int T;
	cin >> T;
	deque<pii> mine;
	deque<int> t_man;
	deque < deque<int> > arr;
	arr.resize(5,deque<int>(0,0));
	while (T-- > 0){
      char el;
      cin >> el;
      if(el == 'E'){
      	int c;
      	int roll;
      	cin >> c >> roll;

      	if(!t_man.empty()){
      	  int flag = 0;
	      	  for(int i =0; i < t_man.size(); i++){
	      	  	if(c == t_man[i]){
	      	  		flag = 1;
	      	  	}
	      	  }
		      	  if (flag == 1){
		      	  	arr[c].push_back(roll);
		      	  }
		      	  else{//not fnd
                     t_man.push_back(c);
                     arr[c].push_back(roll);
		      	  }
          
      	}else{
      		t_man.push_back(c);
      		arr[c].push_back(roll);


      	}
   /*   	pii par = make_pair(c,roll);
      	if(!mine.empty()){
      	   int flag = 0;
           for(int i = mine.size()-1; i >= 0; i--){
           	  if(par.first == mine[i].first){
           	  	mine.insert(mine.begin()+i+1,par);
           	  	flag = 1;
           	  }
           }
           if (flag == 0){
               mine.push_back(par);
           }
      	}
      	else{
          mine.push_back(par);
      	}*/

	     /*cout << "ENQUING DONE" << endl;
	     for(auto el : mine){
	     	cout << el.first << " - " << el.second << endl;
	     }
	     cout << endl;
	     cout << endl;*/
/*	    for (int i = 0; i < 5; i++){
            cout << " i   " << i << endl;
            cout << "inside";
            for(auto el : arr[i]){
               cout << el << " ";
            }
            cout << endl;
	     }*/

      }
      else{
      	int cl = t_man.front();
      	int rl = arr[t_man.front()].front();
      	arr[t_man.front()].pop_front();
      	if (arr[t_man.front()].empty()){
      		t_man.pop_front();
      	}
      	cout << cl << " " << rl << endl;
      }
	}
	return 0;
}