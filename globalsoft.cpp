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

lli isPrimeBest(lli n){
        lli count = 0;
        // check lower boundaries on primality
        if( n == 2 || n == 3){ 
            //prlliStats(++count, n, true);
            return 1;
        } // 1 is not prime, even numbers > 2 are not prime
        else if( n == 1 || (n & 1) == 0){
           // prlliStats(++count, n, false);
            return 0;
        }

        // Check for primality using odd numbers from 3 to sqrt(n)
        for(lli i = 3; i <= sqrt(n); i += 2){
            // n is not prime if it is evenly divisible by some 'i' in this range
            if( n % i == 0 ){ 
                //prlliStats(++count, n, false);
                return 0;
            }
        }
        // n is prime
       // prlliStats(++count, n, true);
        return 1;
    }
    
deque<lli> prime_vec(lli N){
    deque<lli> primes;
    for (lli k = 2; k <= N; k++){
      if (isPrimeBest(k)){
        primes.push_back(k);
      }
    }
    return primes;
}

lli getans(lli N, lli L, lli R){
    deque<lli> allprimes = prime_vec(N);
    int icount = 0;
    for (lli w = L; w <= R; w++){
     for (auto elem : allprimes){
        if(fmod(w,elem) == 0){
            ++icount;
            break;
        }
     }      
    }
   return icount;
}
    
    
int main(){
	lli T;
	cin >> T;
    deque <lli> ans;
	while(T-- > 0){
		lli N;
		lli L;
		lli R;
		cin >> N >> L >> R;
		ans.push_back(getans(N,L,R));
	}
    for (auto elem : ans){
        cout << elem << endl;
    }
	return 0;
}