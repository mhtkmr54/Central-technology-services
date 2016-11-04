#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>


using namespace std;

#define MAX 999001
typedef long long int lli;

deque <lli> coins;

lli printCombinations( deque<lli> R, deque <lli> coins){
  if (R[R.size() - 1] == -1){
  //cout << "nein Solutions" << endl;
  return 0;
  }
  lli start = R.size() - 1;
  while (start != 0){
  lli el = R[start];
  //cout << coins[el] << " ";
  start = start - coins[el];
 }
 //cout << endl;
 return 1;
}

lli possiblity(lli total, deque <lli> coins){
  deque <lli> T;
  T.resize(total+1,MAX);
  deque <lli> R;
  R.resize(total+1,-1);
  T[0] = 0;
  R[0] = 0;
  for (lli k = 0; k < coins.size(); k++){
   for (lli m = 1; m < T.size(); m++){
     if(m >= coins[k]){
      if (1+T[m-coins[k]] < T[m]){
      T[m] = 1 +  T[m-coins[k]];
      R[m] = k;
     }
    }
   }
  }
  return printCombinations(R,coins);
}



deque<lli> max_div(lli num, lli N){
   deque<lli> my_llis;
   for (lli i = N; i > 0; --i){
    if (fmod(num,i) == 0){
    	my_llis.push_back(i);   
     }  
    }

  return my_llis;
}





int main(){ 
   lli T;
   cin >> T;
   deque <lli> ans;
   while (T-- > 0){
   	   lli M,N,A,B;
       cin >> M >> N >> A >> B;
	   deque <lli> coins;
	   coins.push_back(A);
	   coins.push_back(B);
	   deque <lli> divs;
	   divs = max_div(M,N);
	   lli k = 0;
	   while ( divs[k] > N){
	   	  ++k;
	    }
	    while ( possiblity(divs[k],coins) != 1){
	    	++k;
	    }
	   cout << "THE ANS " << divs[k] << M << " "<< N << " " << A << " " << B << endl;
	   ans.push_back(M/divs[k]);
   }
   for (auto elem : ans){
   	cout << elem << endl;
   } 
	return 0;
}


//Anmol
using namespace std;
#include <bits/stdc++.h>
#define rep(i,a,n) for( i=a;i<n;i++)
#define repeq(i,a,n) for( i=a;i<=n;i++)
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
typedef long long ll;
typedef unsigned long long ull;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
int main() {
    ios_base::sync_with_stdio(false);
    
   
   ll m,t,a,i,j,b,n,ans;
   cin>>t;
   rep(i,0,t)
   {
      cin>>m>>n>>a>>b;
      ll maxi=0;
      repeq(j,0,n/a)
      {
          ll p=n-j*a;
          ll q=p/b;
          ll r=j*a+q*b;
          maxi=max(r,maxi);
      }
      ll req=m/maxi;
      if(m%maxi!=0)
      req++;
   cout<<req<<"\n";
   }
      
   
    return 0;
}
