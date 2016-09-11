#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define SIZE(A) (int((A).size()))
#define pb(A) push_back(A)
#define mp(A,B) make_pair(A,B)

const int fx[] = {0, 1, 0, -1}, fy[] = {1, 0, -1, 0};

int n, m;
int col;
int p[2000][2000];
char w[2000][2000];
char s[2000][2000];

void dfs(int x, int y) {
	w[x][y]=col;
	for (int i = 0; i < 4; i++) {
		int xx = x+fx[i], yy = y+fy[i];

		if (xx<0||yy<0||xx>=n||yy>=m||w[xx][yy]==col||s[xx][yy]=='X') continue;

		p[xx][yy] = (i+2)&3;
		dfs(xx, yy);
	}
}

int solve(int x, int y) {
	w[x][y] = ++col;
	for (int i = x, j = y; s[i][j]!='M';) {
		int v = p[i][j];
		i += fx[v]; j += fy[v];
		w[i][j] = col;
	}

	int amo=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j]==col) {
				if (s[i][j]=='*') continue;
				
				int add=0;

				for (int k = 0; k < 4; k++) {
					int xx = i+fx[k], yy=j+fy[k];
					if (xx<0||yy<0||xx>=n||yy>=m||w[xx][yy]==col||s[xx][yy]=='X') continue;
					add=1;
				}

				amo+=add;
			}
		}
	}
	return amo;
}

int main() {
	int t;
	cin >> t;
	for (; t--;) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);
		}
		int k;
		cin >> k;

		col++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'M') {
					dfs(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '*') {
					k -= solve(i, j);
				}
			}
		}
		puts(!k?"Impressed":"Oops!");
	}

    return 0;
}

