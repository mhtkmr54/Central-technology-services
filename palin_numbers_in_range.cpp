#include<iostream>
#include<deque>
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
        if (isPalindrome(i)){
          ++ct;	
        }
          
    return ct;
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
    	answer.push_back(countPal(L,R));
    }
    for (auto el : answer){
    	cout << el << endl;
    }
}