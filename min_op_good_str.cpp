#include <map>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int flag = 0;


int solve(string str, int m, int n, map<string,int>& memo)
{
  //cout << m << " "<< n << endl;
  string res = to_string(m) + to_string(n);
   if (memo.find(res) != memo.end()){
      return memo[res];
   }
   else{
          if (m>=n){
            //flag = -1;
            return 0;
         }  
         if (str[m] == str[n]){
          return 0;
         }
         else{
           return memo[res] = min(1 + solve(str, m+1, n, memo), 1 + solve(str, m, n-1, memo));
         }
   }

}


int lcs1(string str, int m, int n )
{
   int L[n][n];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=m; i<=n; i++)
   {
     for (j=n; j>=m; j++)
     {
       if (i == 0 || j == 0 || i >= j)
         L[i][j] = 0;
  
       else if (str[i] == str[j])
         L[i][j] = 0;
  
       else
         L[i][j] = min(1 + L[i+1][j], 1 + L[i][j-1]);
     }
   }

   return L[n][n];
  }

int main()
{   
    deque<int> answer;
    int T;
    cin >> T;
    while (T-- > 0){
      string a;
      cin >> a;
      map<string,int> memo;
      map<char,int> mine;
      for(int k = 0; k < a.length(); k++){
            if (mine.find(a[k]) != mine.end()){
              mine[a[k]] += 1;
              flag = 1;
            }
            else{
              mine[a[k]] = 1;
            }
      }
      if (flag == 1){
        //answer.push_back(solve(a, 0, a.size()-1, memo));
        answer.push_back(lcs1(a, 0, a.size()-1));
      }else{
        answer.push_back(-1);
      }
      flag = 0;
    }
    for (auto el : answer){
      cout << el << endl;
    }
    return 0;
}