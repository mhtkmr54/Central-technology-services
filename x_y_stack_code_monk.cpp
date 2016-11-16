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
map<char,int>::iterator it;

int main(){
	int T;
	cin >> T;
	deque<int> mine;
	deque<int>::iterator it;
	while (T-- > 0){
		int el;
		cin >> el;
		mine.push_back(el);		
	}
   deque<int> xx;
   deque<int> yy;
   for(int i = 0; i < mine.size()-1; i++){
      


      int el = *max_element(mine.begin()+i+1, mine.end());
      



      it = max_element(mine.begin()+i+1, mine.end());
      

      cout << "currently at " << i << endl;
      int e = it - mine.begin() + 1;
      cout << it - mine.begin() <<  " pos "<<endl;
      cout << el << " max_el" << endl;
      cout << endl;
      if(mine[i] < el){
         xx.push_back(e);
      }else{
      	xx.push_back(-1);
      }
   }
   xx.push_back(-1);
    for(int i = mine.size()-1; i > 0; i--){
      int el = *max_element(mine.begin(), mine.begin()+mine.size()-1);
      it = max_element(mine.begin(), mine.begin()+mine.size()-1);
      cout << "currently at " << i << endl;
      int e = it - mine.begin() + 1;
      cout << it - mine.begin() <<  " pos "<<endl;
      cout << el << " max_el" << endl;
      cout << endl;
      if(mine[i] < el){
         yy.push_front(e);
      }else{
      	yy.push_front(-1);
      }
   }
   yy.push_front(-1);
   
	return 0;
}