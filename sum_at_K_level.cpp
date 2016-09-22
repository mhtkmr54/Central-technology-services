#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,i,lvl,ans;
    string t;
    cin>>t>>k;

    lvl=-1;
    ans=0;
    for(i=0;t[i]!='\0';i++)
    {
        if(t[i]=='(')
            lvl++;
        else if(t[i]==')')
            lvl--;
        else
        {
            if(lvl==k)
                ans+=(t[i]-'0');
        }
    }
    cout<<ans;
    return 0;
}