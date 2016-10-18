#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    int t =1;
    for(int p = 0; p< t; p++)
    {
        int n; 
        int k; 
        int x,y=0;
        scanf("%d %d",&n,&k);
        	if(n<2||n>1000||k<2||k>n)
		{
			exit(0);
		}
        for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				
				x=i&j;
                cout << " x " << x << " is BITwise & of "<< i  << " " << j << " " << endl;
                if((x>y)&&(x<k))
                    y=x;
            }
        }
        printf("%d\n",y);
    }
    int three = 3;
    int y = three>>1;
    cout << y << " three>>1 " << endl;
    int one = 1;
    int four = 4;
    one = one<<2;
    int res = four^one;
    cout << res << " four^(one << 2) here idx 2 is toggle pos " << endl;  
    int six = 6;
    int on =1;
    on = on<<1;
    int re = six^on;
    cout << re << " 6^(one << 1) here idx 1 is toggle pos " << endl;  
    string test = "mn";
    int ob  = test[0] + 2;
    cout << "ob " << ob << " (ascii(m) + 2) -> " << endl;
    char obmax = ob;
    string obmax1(1,ob);
    cout << obmax << " (ascii(m) + 2) " << obmax1 << endl;
    return 0;
}