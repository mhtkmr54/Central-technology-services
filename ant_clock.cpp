#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque< deque<int> > my_deq;
deque <int> rotat;

int R,C,D;

void rotate(int D){
     
     for (int i = 0; i < R/2; i++){
        int p;
        for(p = i ; p < C-i; p++){
          //cout << " i p " << i << " " << p << " " << my_deq[i][p] << " - " << endl; 
          rotat.push_back(my_deq[i][p]);
        }
        p--;
        int j;
        for(j = i+1; j < R-i; j++){
           //cout << " j p " << j << " " << p << " " << my_deq[j][p] << " - " << endl; 
           rotat.push_back(my_deq[j][p]);
          
        }
        j--;
        int m;
        cout << p << endl;
        for(m = p-1; m >= i; m--){
          //cout << " j m " << j << " " << m << " " << my_deq[j][m] << " - " << endl; 
          rotat.push_back(my_deq[j][m]);
        }
        m++;
        int n;
        for(n = j-1; n > i; n--){
          //cout << " n m " << n << " " << m << " " << my_deq[n][m] << " - " << endl; 
          rotat.push_back(my_deq[n][m]);
        }
        j++;
        while (D-- > 0){
            int fr = rotat.front();
            rotat.pop_front();
            rotat.push_back(fr);
        }
        //--------------------------------------------------------------------------
        for(p = i ; p < C-i; p++){
          my_deq[i][p] = rotat.front();
          rotat.pop_front();
        }
        p--;
        for(j = i+1; j < R-i; j++){
           my_deq[j][p] = rotat.front();
           rotat.pop_front();
        }
        j--;
        cout << p << endl;
        for(m = p-1; m >= i; m--){
          my_deq[j][m] = rotat.front();
          rotat.pop_front();
        }
        m++;
        for(n = j-1; n > i; n--){
          my_deq[n][m] = rotat.front();
          rotat.pop_front();
        }
        j++;
       cout << endl;

     } 

     return;
}
     
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T-- > 0){
         cin >> R >> C >> D;
         my_deq.resize(R,deque<int>(C,0));
         for (int i =0; i < R ; i++){
               for (int j =0; j < C; j++){
                  cin >> my_deq[i][j];
               }
            }
    }
    rotate(D);
    for (int i =0; i < R ; i++){
     for (int j =0; j < C; j++){
        cout << my_deq[i][j] << " ";
     }
     cout << endl;
  }
  cout << endl;
    return 0;
}
