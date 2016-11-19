#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <string>
#include <cstring>
#include <iterator>

using namespace std;
//g++ -std=c++0x

map <string,int> memo;

int solve(deque<int> mine, int i, int j){
    //int cost = 0;
      cout << " i " << " j " << i << " " << j << endl;
      string res = to_string(i) + to_string(j);
       if (memo.find(res) != memo.end()){
          return memo[res];
       }else{       
                int min = 999999999;
                int el;
                int mindx;
                for(int k = i+1; k < j; k++){
                    el = mine[j] - mine[i] + solve(mine,i,k) + solve(mine,k,j);
                    cout << " elinc  "<< el << " mine[j]" << j <<   " - mine[i]" << i << " " <<  mine[j] << " - " << mine[i] << endl;
                    if (el < min){
                        min = el;
                        mindx = k;
                        cout << "____________________________" << k << " for " << i << " " << j << endl;
                    }
                }
                if(min != 999999999){
                	return memo[res] = min;
                }else{
                	return 0;
                }
                
       }
       return 0;
}

void rodCut(int A, vector<int> &B) {
    deque<int> mine;
    for(int k=0; k<B.size(); k++){
        mine.push_back(B[k]);
    }
    //cout << mine.size() << endl;
    deque<int> parts;
    mine.push_back(A);
    mine.push_front(0);
    int ans = solve(mine,0,mine.size()-1);
    cout << ans << endl;
}

int main(){
    vector <int> B;
    B.push_back(1);
    B.push_back(2);
    B.push_back(5);
    rodCut(6,B);
	return 0;
}
