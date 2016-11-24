 // like pariksha C(m+n-2, m-1).
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

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

int uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long c[5001][5001];
    const int MOD = 1000000009;
    
    for (int i = 1; i <= 5000; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 2; i <= 5000; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		
    int n = A+B-2;
    int r1 = A-1;
    int r2 = B-1;
    return  c[n][r1];
    
    
}


 int uniquePaths1(int m, int n) {
            // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
            long long ans = 1;
            for (int i = n; i < (m + n - 1); i++) {
                ans *= i;
                ans /= (i - n + 1);
            }
            return (int)ans;
 }

int uniquePaths(int A, int B) {
    if(A==1 || B==1)    return 1;
    return uniquePaths(A-1,B)+uniquePaths(A,B-1);
}







int Solution::uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long c[A+1][B+1];
    const int MOD = 1000000009;
    
    for (int i = 1; i <= A; i++){
		c[i][1]  = 1;
    }
	 for (int i = 1; i <= B; i++){
		c[1][i]  = 1;
	 }
	for (int i = 2; i <= A; i++){
		for (int j = 2; j <= B; j++){
			c[i][j] = (c[i - 1][j] + c[i][j - 1]) % MOD;
		}
	}		
			
   return c[A][B];
    
}




int main(){
	cout << uniquePaths(100,1) << endl;
	return 0;
}