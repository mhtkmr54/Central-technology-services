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

lli binarySearch(deque<lli> arr, lli l, lli r, lli x)
{
   if (r >= l)
   {
        lli mid = (r + l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid+1;
        //  To get thr index of first occurnce of x if ( (mid == 0 || x > arr[mid-1]) && (arr[mid] == x) ) return mid;
        if(mid-1 >= 0){
            if (arr[mid] > x && arr[mid-1] < x){
              //cout << "inserting b/w " << arr[mid-1] << " & mid ->" << arr[mid] << endl;
              return mid;  
            }       
        }
        
        if (mid + 1 <= arr.size()-1){
            
            if (arr[mid] < x && arr[mid+1] < x) {
               // cout << "inserting b/w " << arr[mid] << " & " << arr[mid+1] << endl;
                return mid+1;
            } 
        }
        
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}


int main(){
	lli N, X;
	cin >> N >> X;
	deque<lli> mine;
	while(N-- > 0){
		lli ele;
		cin >> ele;
		mine.push_back(ele);

	}
    cout << "srting " << endl;
	sort(mine.begin(), mine.end());
    cout << "sorted" << endl;
    deque<lli> must;
    lli sum;
	for(lli len = 1; len <= mine.size(); len++){
        cout << "iter" << endl;
        sum = 0;
        //cout << "size " << mine.size() << " len " << len << " exp "<< ((mine.size()-1)-(len-1)) << endl;
		for(lli el = ((mine.size()-1)-(len-1)); el <= mine.size()-1; el++){
            //cout << "el " << mine[el] << " index "<< el << endl;
             sum += mine[el];
		}
        //cout << "sum ----------------------"<< sum << endl;
		must.push_back(sum);
	}
    cout << "iter DOME ###########" << endl;
/*    for (auto el : must){
        cout << el << " ";
    }*/
    //cout << endl;
    sort(must.begin(), must.end());
	if(must[must.size() -1] <= X){
		cout << must.size() << endl;
	}else{
       // cout << "Sda" << endl;
		//cout << binarySearch(must,0,must.size()-1,X) << endl;
        for(int k = must.size()-1; k >= 0; k--){
            cout << "searc " << endl;
            if (X > must[k]){
               cout << k+1 << endl;
               break;
            }
            if(X == must[k]){
                cout << k+1 << endl;
                break;
            }
        }
	}
	
	return 0;
}




#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n, x;cin>>n>>x;
    ll a[100100]={0};
    ll flag=1;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        if(a[i] > x)
            flag = 0;
        a[i]+=a[i-1];
    }
    if(!flag){
        cout<<"-1\n";
        return 0;
    }
    ll left = 1, right = n;
    ll ans = -1;
    while(left <= right){
        ll mid = (left+right)/2;
        ll flag = 1;
        for(ll i=mid; i<=n; i++){
            if(a[i]-a[i-mid] > x){
                flag = 0;
                break;
            }
        }
        if(flag){
            left = mid+1;
            ans = mid;
        }
        else{
            right = mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}