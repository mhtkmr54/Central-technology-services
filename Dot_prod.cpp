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
deque<lli> one;
deque<lli> two;
lli T;

int main(){
	cin >> T;
    for (lli k = 0; k < T; k++){
    	cout << "POPULATING one" << endl;
    	lli el;
    	cin >> el;
    	one.push_back(el);
    }
    for (lli k = 0; k < T; k++){
    	cout << "POPULATING two" << endl;
    	lli elem;
    	cin >> elem;
    	two.push_back(elem);
    }
    cout << "SPRTING Start" << endl;
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    cout << "SPRTING DONE" << endl;
    //reverse(two.begin(),two.end());
    lli ans = 0;

    for (lli k = 0; k < T; k++){
        ans += one[k] * two[T-k-1];
    }
    cout << ans << endl;

	return 0;
}








#include <bits/stdc++.h>
#define M 1000005
#define ll long long int 
using namespace std;
 
 
 
int main(){
 
ll n;
cin>>n;
ll a1[n],a2[n];
for (int i = 0; i < n; ++i)
{
  cin>>a1[i];
}
for (int i = 0; i < n; ++i)
{
  cin>>a2[i];
}
 
sort(a1,a1+n);
sort(a2,a2+n);
ll sum=0;
for (int i = 0; i < n; ++i)
{
//	cout<<a1[i]<<" "<<a2[n-1-i]<<" "<<sum<<" \n";
    sum=sum+a2[n-1-i]*a1[i];
}
cout<<sum<<"\n";
 
 
return 0;
}
