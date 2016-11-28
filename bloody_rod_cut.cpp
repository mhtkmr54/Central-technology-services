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

typedef long long LL;

//ans vector
vector<int> ans;

//cuts vector
vector<int> ar;

//dp array
vector<vector<LL> > dp;

//parent array
vector<vector<int> > parent;

//solve for dp(l, r)
LL rec(int l, int r){
    //base case
    if(l+1>=r)return 0;

    //for memoisation
    LL &ret=dp[l][r];

    if(ret!=-1)return ret;


    ret=LLONG_MAX;
    int bestind;    //stores the best index

    for(int i=l+1; i<r; i++){
        //recurrence
        LL p=rec(l,i)+rec(i,r) + (LL)ar[r]-(LL)ar[l];

        //update best
        //note that we choose lexicographically smallest index
        //if multiple give same cost
        if(p<ret){
            ret=p;
            bestind=i;
        }
    }

    //store parent of (l, r)
    parent[l][r]=bestind;

    return ret;
}

//function for building solution
void back(int l, int r){
    //base case
    if(l+1>=r)return;

    //first choose parent of (l,r)
    ans.push_back(ar[parent[l][r]]);

    //call back recursively for two new segments
    //calling left segment first because we want lexicographically smallest
    back(l,parent[l][r]);
    back(parent[l][r],r);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    //insert A and 0
    B.push_back(A);
    B.insert(B.begin(),0);


    int n=B.size();
    ar.clear();
    for(int i=0; i<n; i++)
        ar.push_back(B[i]);

    //initialise dp array
    dp.resize(n);
    parent.resize(n);
    ans.clear();
    for(int i=0; i<n; i++){
        dp[i].resize(n);
        parent[i].resize(n);
        for(int j=0; j<n; j++)
            dp[i][j]=-1;
    }

    //call recurrence
    LL best=rec(0,n-1);

    //build solution
    back(0,n-1);

    return ans;
}

int main(){
    vector <int> B;
    B.push_back(1);
    B.push_back(2);
    B.push_back(5);
    rodCut(6,B);
	return 0;
}
