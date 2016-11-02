#include <iostream>
using namespace std;

const int MOD = 1000000009;

long long f[5001];
long long c[5001][5001];

//catalan array
void init()
{
	f[0] = f[1] = 1;
	for (int i = 2; i <= 5000; i++)
	{
		for (int j = 1; j <= i; j++)
			f[i] = (f[i] + (f[j - 1] * f[i - j]) % MOD) % MOD;
	}
}

void initc()
{
	for (int i = 1; i <= 5000; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 2; i <= 5000; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}

int main()
{
	init();
	initc();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long ret = 0;
		for (int i = 1; i <= n; i++){
			ret = (ret + c[n][i] * f[i]) % MOD;
		}
		cout << ret << endl;
	}
	return 0;
}