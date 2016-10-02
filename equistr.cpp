#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <locale>


using namespace std;


 
int editDistDP(char *str1, char *str2, int m, int n)
{
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            cout << i << j << endl;
            if ( i == 0 && j == 0){
              continue;
            }
            if (i==0 && j >= 1){
                
                dp[i][j] = dp[i][j-1] + str2[j-1] - '0';  // Min. operations = j
                cout << "1 " <<   dp[i][j-1] << " + " << str2[j-1] - '0' << endl;

            } 
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0 && i >= 1){
                cout << "2 " << endl;
                dp[i][j] = dp[i-1][j] + str1[i-1] - '0'; // Min. operations = i
            }
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1]){
                cout << "3 " << endl;
                dp[i][j] = dp[i-1][j-1];
            }
 
            else{
                 cout << "4 " << endl;
                dp[i][j] = 0 + min(dp[i][j-1] + str2[j-1] - '0',  // Insert
                                   dp[i-1][j] + str1[i-1] - '0'  // R(int)str1[i] - '0'emove
                                   );
            }
        }
    }
 
  for (int i =0; i < m+1 ; i++)
  {
     for (int j =0; j < n+1; j++)
     {
        cout << dp[i][j] << " ";
     }
     cout << endl;
  } 
  cout << endl;


    return dp[m][n];
}

int main()
{
    // your code goes here
    char str1[] = "816337897";
    char str2[] = "816393804";
    //cout << "STR ! " << str1[0] - '0' + 7 << endl;
    cout << editDistDP(str1, str2, strlen(str1), strlen(str2));
 
    return 0;
}