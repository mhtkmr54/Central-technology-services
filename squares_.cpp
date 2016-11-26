#include <bits/stdc++.h>
using namespace std;
int a[105];
 
int main() {
	memset(a,0,sizeof(a));
	for(int i=1;i<=100;i++){
		for(int j=i;j<=100;j+=i){
			if(a[j]==0){
				a[j]=1;
			}
			else{
				a[j]=0;
			}
		}
	}
	for(int i=1;i<=100;i++){
		if(a[i]==1){
			cout<<i<<' ';
		}
	}
	return 0;
}
