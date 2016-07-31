#include <cstdio>
#include <algorithm>
using namespace std;
    
int l, r, a, b, ret;
    
int main () {
    scanf("%d %d", &l, &r);
    for(a = l; a <= r; a++)
        for(b = a; b <= r; b++)
            ret = max(ret, a ^ b);
    printf("%d\n", ret);
    return 0;
}