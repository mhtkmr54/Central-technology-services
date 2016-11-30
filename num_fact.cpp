/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)    
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod
typedef long long int LL;
using namespace std;






int main(){

int total = 0, N = 0, Number;
scanf ("%d", &total);
while (total--)
{
    scanf ("%d", &N);
    map<int, int> Counter;
   deque<int> mi;
    mi.resize(N,0);
    for (int i = 0; i < N; i++)
    {
        int el;
        cin >> el;
        mi[i] = el;
    }

    for (int i = 0; i < N; i++)
    {
         Number = mi[i];
         cout << "w" << " " << Number << endl;
        for (int j = 2; j * j <= Number; j++)
        {
            cout << "Number" << Number << endl;
            while (Number % j == 0)
            {
                Counter[j]++;
                Number /= j;
            }
        }
        if (Number > 1) Counter[Number]++;
    }
    int Answer = 1;
    for (map<int, int>::iterator it = Counter.begin(); it != Counter.end(); it++){
        Answer *= (it->second + 1);
    }
    printf ("%d\n", Answer);
}

    return 0;
}