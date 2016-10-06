#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>


using namespace std;





void foo(int n, int sum)
{
  int k = 0, j = 0;
  if (n == 0) return;
    k = n % 10; 
  j = n / 10;
  sum = sum + k;
  foo (j, sum);
  printf ("%d,", k);
}
  
int main ()
{
  int a = 2048, sum = 0;
  char b = 'a';
  if (a,b){
   printf ("%d\n", a);  
  }
    
  getchar();
}

