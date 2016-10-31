#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cfloat>
#include <iomanip>
#include <stack>
#include <bitset>


using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define bitcount(n) __builtin_popcountll(n)
#define pii pair<int, int>


typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 300000 + 7;
const int M = 103;
const int inf = 1e9 + 9;
const long long linf = 1ll * inf * (inf - 1);
const double pi = acos(-1);
const double eps = 1e-6;
const bool multipleTest = false;




int sl[200];
int DP[107][207];
int n;
int ans = 0;


void solve(){
    cin >> n;
    ans = n;
    
    for(int i = 1; i <= n; ++i) {
        int u; scanf("%d", &u);
        
        for(int diff = -100; diff <= 100; ++diff) {
            if (u - diff >= 1 && u - diff <= 100) {
                DP[u][diff + M] = (DP[u][diff + M] + DP[u - diff][diff + M]) % inf;
                DP[u][diff + M] = (DP[u][diff + M] + sl[u - diff]) % inf;
            }
            
        }
        sl[u]++;
    }
    
    for(int u = 1; u <= 100; ++u)
        for(int diff = -100; diff <= 100; ++diff) ans = (ans + DP[u][diff + M]) % inf;
    
    cout << (ans + 1) % inf << "\n";
}

void createTest() {
    freopen("in.txt", "w", stdout);
    int n = 10;
    cout << n << "\n";
    set<int> st;
    for(int i = 1; i < 2 * n; ++i) st.insert(i);
    
    for(int i = 1; i < 2 * n; ++i) {
        int u = rand() % 200000;
        ft(st) it = st.lower_bound(u);
        if (it == st.end()) --it;
        printf("%d ", *it);
        st.erase(it);
    }
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
    clock_t t1 = clock();
#endif
//    createTest();
//    return 0;
//    freopen("out.txt", "w", stdout);
    
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    
    for(int i = 0; i < Test; ++i) {
//        printf("Case #%d: ", i + 1);
        solve();
    }
    
#ifdef _LOCAL_
    cout<<"\n" << 1.0 * (clock() - t1) / CLOCKS_PER_SEC<<endl;
#endif
    
}
