// Program to print all prime factors
# include <stdio.h>
# include <math.h>
# include <iostream>
# include <map>

using namespace std; 
// A function to print all prime factors of a given number n
map<int,int> m;
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        m[2] += 1;
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            int k = i;
            printf("%d ", i);
            m[k] += 1; 
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        m[n] += 1; 
        printf ("%d ", n);

   
   cout << endl;
}
 
/* Driver program to test above function */
int main()
{
    int n;
    cin >> n;
    primeFactors(n);
    map<int,int>::iterator it;
    int to = 1;
    for(it = m.begin(); it != m.end(); ++it){
        cout << it->first << " appeared " << it->second << " times "<< endl;
        to *= (it->second+1);
    }
    cout << to << " total facts" << endl;
    return 0;
}
