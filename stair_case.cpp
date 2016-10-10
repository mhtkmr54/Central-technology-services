#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int ways;

map <int,int> mem;

//top down

int solve(int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    if(mem.find(n) != mem.end())
        return mem[n];
    return mem[n] = solve(n-1) + solve(n-2) + solve(n-3);
}

void go_n(int now, int h){
    if(now >= h){
        ways += 1;
        return;
    }
    if(now+1 <= h){
        
        go_n(now+1,h);
    }
   if(now+2 <= h){
        go_n(now+2,h);
    }
    if(now+3 <= h){
        go_n(now+3,h);
    }
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int h;
        cin >> h;
        ways = 0;
        go_n(0,h);
        cout << ways << endl;
        ways = 0;
    }
    return 0;
}
