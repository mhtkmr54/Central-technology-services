#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */



bool bsearch(vector<int> myvector, int look)
    {
    int mid,l = 0;
    int h = myvector.size() - 1;
    while (l <= h){
        mid = (h+l)/2;
        if (look > myvector[mid]){
             l = mid+1;
        }
        else if (look < myvector[mid]){
            h = mid-1;
        }
        else{
            return true; // NOT True
        }
        
    }
    return false;
    }



int pairs(vector < int > a,int k) {
   int ans = 0;
   vector<int> sorted_a;
   sort(a.begin(),a.end());
   for (int j =0; j < a.size(); j++)
    {
       int look = a[j] + k;
       bool faisla = bsearch(a,look);
       if (faisla == true){
           //cout << "match of diff\  " << endl;
           ans++;
       }
   }   
    
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}

