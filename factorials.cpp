#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;
typedef long long int lli;

lli fact(map<lli,lli>& memo, lli x)
{
    if (memo.find(x) != memo.end()){
        cout << "gen ret " << x << endl;
        return memo[x];
       }
    else{
        cout << "cal  " << endl;
          if (x >= 1){
            return memo[x] = x*fact(memo, x-1);
          }else{
           return  1; 
         }
            
     }
 }

lli fact_dp(lli result[], lli n)
{
    if (n >= 0) 
    {
        result[0] = 1;
        for (lli i = 1; i <= n; ++i) 
        {
          result[i] = i * result[i - 1];
        }
        return result[n];
    }
}
  
        

lli uniquePaths(lli A, lli B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not prlli the output, instead return values as specified
    // Still have a doubt. Checkout www.llierviewbit.com/pages/sample_codes/ for more details
    lli result[1000] = {0};
    lli n = A+B-2;
    lli r1 = A-1;
    cout << r1 << endl;
    lli r2 = B-1;
    lli ans = fact_dp(result,n);
    cout << "mem test n " << fact_dp(result,n) << endl;
    
    for (int i =0; i<101; i++){
        cout << " " << result[i] << " ";
    }

    cout << "mem test " << fact_dp(result,r2) << endl;
    lli ansd =  fact_dp(result,r1)*fact_dp(result,r2);
    cout << "ans" << ansd << endl;
    lli fin = ans/ansd;
    return fin;  
}

int main(){
    cout << uniquePaths(100,1);
    return 0;
}