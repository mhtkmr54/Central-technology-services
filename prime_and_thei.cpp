#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

const int MOD = 1000000009;
typedef long long int lli;
 map <lli,lli> memo;

lli fact(int n)
{
    if (memo.find(n) != memo.end()){
      return memo[n];
       }
    if (n >= 1)
        return memo[n] = n*fact(n-1);
    else
        return 1;
}

bool isPrime(int n) {
        if (n <= 1) {
                return 0;
        }
        if (n == 2) {
                return true;
        }
        if (!(n % 2)) {
                return false;
        }
        for (int i = 2; i*i <= n; i++) {
                if (!(n % i)) {
                        return 0;
                }
        }
        return 1;
}

int primeNumbers(int k) {
	    int icn = 1;
        for ( int i = 3; i <= k; i += 2) {
                if (isPrime(i)) {
                        ++icn;
                }
        }
        return icn;
}

int main(){
	map <int,int> memo;
	int M;
	cin >> M;
	int C =  primeNumbers(M) ;
    cout << (fact(C)*fact(M-C)) % MOD;
    cout << endl;
	return 0;
}

