#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;
    
int l, r, a, b, ret;
    
int main () {
    cin >> a >> b;
    ret = a ^ b;
    printf("%d\n", ret);
    return 0;
}