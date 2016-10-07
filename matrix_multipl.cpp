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



for(i=0; i<r1; ++i)
    for(j=0; j<c2; ++j)
    for(k=0; k<c1; ++k)
    {
        mult[i][j]+=a[i][k]*b[k][j];
    }

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

