//satyaki3794
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cassert>
#include <queue>
#include <cmath>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
bool is_palindrome(string str){
    string temp = str;
    reverse(temp.begin(), temp.end());
    return (str == temp);
}
int main(){
    ios_base::sync_with_stdio(0);
    // freopen("in00.txt", "r", stdin);
    // freopen("out00.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    int t, len, ans = 0;
    cin>>t>>len;
    assert(t <= 10);
    assert(len <= 50);
    while(t--){
        string str;
        cin>>str;
        int n = str.length();
        assert(n <= len);
        bool yes = false;
        if(is_palindrome(str))  yes = true;
// cout<<yes<<endl;
        for(int l1=0;l1<n;l1++)
        for(int r1=l1;r1<n;r1++){
            string temp = str;
            reverse(temp.begin()+l1, temp.begin()+r1+1);
            if(is_palindrome(temp)){
                yes = true;
        // cout<<"yolo "<<l1<<" "<<r1<<endl;
            }
        }
// cout<<yes<<endl;
        for(int l1=0;l1<n;l1++)
        for(int r1=l1;r1<n;r1++)
            for(int l2=r1+1;l2<n;l2++)
            for(int r2=l2;r2<n;r2++){
                string temp = str;
                reverse(temp.begin()+l1, temp.begin()+r1+1);
                reverse(temp.begin()+l2, temp.begin()+r2+1);
                if(is_palindrome(temp))
                    yes = true;
            }
        if(yes){
            // cout<<str<<" YES\n";
            ans++;
        }
        else{
            // cout<<str<<" NO\n";
        }
    }
    cout<<ans;
    return 0;
}