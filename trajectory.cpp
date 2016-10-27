#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(lli i=(lli)a;i<=(lli)b;i++)
#define endl "\n"
#define mp make_pair
#define X first
#define Y second
#define inf 1e18
#define mod 1000000007
#define pb push_back
#define pi 3.14159265359
#define gc getchar
#define Case cout<<"Case "<<++cas<<": ";
#define EPS 0.000000001
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef vector<pii> vii;
typedef pair<lli,lli> pll;
int main()
{
    fastio;
    lli T,x1,x2,y1,y2,a,b,gcd;
    cin>>T;
    while(T--)
    {
        cin>>x1>>y1>>x2>>y2;
        a=abs(x1-x2);
        b=abs(y1-y2);
        if(a==0 || b==0) {cout<<0<<endl;continue;}
        gcd=__gcd(a,b);
        cout<<a+b-gcd<<endl;
    }
    return 0;
}