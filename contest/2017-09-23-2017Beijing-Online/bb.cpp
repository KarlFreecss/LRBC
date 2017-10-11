#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100010;


int a[MAXN];
int ranky[MAXN];
int f[MAXN][26];
int g[26];
int n;

int work(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		ranky[a[i]] = i + 1;
	}
	ranky[n+1] = 0;
	for (int i = 0; i < 26; ++i) {
		f[0][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			f[i][j] = 0;
			g[j] = f[i-1][j];
			if (j > 0) {
				g[j] += g[j-1];
			}
		}
		if (ranky[a[i]+1] > ranky[a[i-1]+1]) {
			for (int j = 0; j < 26; ++j) {
				f[i][j] = g[j];
			}
		} else {
			for (int j = 1; j < 26; ++j) {
				f[i][j] = g[j-1];
			}
		}
	}
	int tot = 0;
	for (int i = 0; i < 26; ++i) {
		tot += f[n-1][i];
		printf("%d ", f[n-1][i]);
	}
	return tot;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		printf("%d\n", work());
	}

	return 0;
}
