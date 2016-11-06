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
 
// A function to check if n is palindrome
int isPalindrome(int n)
{
    // Find reverse of n
    int rev = 0;
    for (int i = n; i > 0; i /= 10)
        rev = rev*10 + i%10;
 
    // If n and rev are same, then n is palindrome
    return (n==rev);
}
 
// prints palindrome between min and max
int countPal(int min, int max)
{
	int ct = 0;
    for (int i = min; i <= max; i++)
        if (isPalindrome(i))
          ++ct;
          
    return ct;
}
 
int the_optim(int L, int R)
{
	int cot = 0;
	
    for (int i = L; i <= R; i++){
      int fm = fmod(i,100);
      if (fmod(i,100) == 0){
      	//cout << "step of 100 " << endl;
      	cot += 10;
      	if (i+99 <= R){
      		i += 99;
      	}	
      }
      else if ( i + (100 - fm - 1) <= R){
      	//cout << "to 100 " << endl;
      	cot += countPal(i, i + (100 - fm-1));
      	i += (100 - fm - 1);
      }else{
      	//cout << "gen" << endl;
      	cot += countPal(i,R);
      	i = R;
      }
    }
    return cot;
}


// Driver program to test above function
int main()
{   deque<int> answer;
    int T;
    cin >> T;
    while (T-- > 0){
    	int L;
    	int R;
    	cin >> L >> R;
    	answer.push_back(the_optim(L,R));
    }
    for (auto el : answer){
    	cout << el << endl;
    }
}