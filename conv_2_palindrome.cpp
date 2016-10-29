#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <iterator>
using namespace std;


"""
NAIVE
int findMinInsertions(char str[], int l, int h)
{
    // Base Cases
    if (l > h) return INT_MAX;
    if (l == h) return 0;
    if (l == h - 1) return (str[l] == str[h])? 0 : 1;
 
    // Check if the first and last characters are same. On the basis of the
    // comparison result, decide which subrpoblem(s) to call
    return (str[l] == str[h])? findMinInsertions(str, l + 1, h - 1):
                               (min(findMinInsertions(str, l, h - 1),
                                   findMinInsertions(str, l + 1, h)) + 1);
}

// A DP recursive program to find minimum number insertions
int findMinInsertionsDP(char str[], int n)
{
    // Create a table of size n*n. table[i][j] will store
    // minumum number of insertions needed to convert str[i..j]
    // to a palindrome.
    int table[n][n], l, h, gap;
 
    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));
 
    // Fill the table
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                          (min(table[l][h-1], table[l+1][h]) + 1);
 
    // Return minimum number of insertions for str[0..n-1]
    return table[0][n-1];
}
"""


map <char,int> vis;

int isPalindrome(string s){
	string dem = s;
	reverse(dem.begin(),dem.end());
	if (dem == s){
		return 1;
	}
	else{
		return 0;
	}
}

int conv2palin(string s){
	int count = 0; 
    for (int i =0; i < s.length()/2; i++){
    	if (s[i] != s[s.length()-1-i]){
    	   string elem(1,s[i]);
           s.insert((s.length()-1-i),elem);
    	   count = count + 1;
    	}

    }
	return count;
}

int main(){
	int T;
	cin >> T;
	while(T-- > 0){
      string s;
      cin >> s;
      if (!isPalindrome(s)){
        cout << conv2palin(s) << endl;
      }else{
        cout << 0 << endl;
      }
	}
	return 0;
}