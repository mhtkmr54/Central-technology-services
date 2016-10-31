#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin >> N;
    deque<int> mine;
    deque<int> Diffs;
    for (int i =0; i < N; i++){
        int el;
        cin >> el;
        mine.push_back(el);
    }
    int mn = *min_element(mine.begin(),mine.end());
    int mx = *max_element(mine.begin(),mine.end());
    int range = mx - mn;
    for (int j = range; j >= -range; j--){
        cout << "range " << j << endl;
        int diff_num = 1;
        int flag = 0;
        for (int k =0; k < N; k++){   
            int elem = mine[k]+j;
            cout << "finding : native" << elem << " : " << k << endl;
            while(find(mine.begin()+k, mine.end(), elem) != mine.end()){
               
              flag = 1; 
              elem += j;
              ++diff_num;
             }
             if (flag == 1){
              break;
             }

         }
        if(flag == 1){
            cout << "max subseq " << diff_num << endl;
            Diffs.push_back(diff_num);
        }else{
            continue;
        }
        
     }
     int total = 0;
     total += 1 + N;
     for (auto e : Diffs){
         int to_add = (e*(e-1))/2;
         total +=  to_add;
     }
    cout << total << endl;
    return 0;
}
