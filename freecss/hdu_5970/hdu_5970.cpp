#include<bits/stdc++.h>

using namespace std;


const int MAXN = 700;
using LL = long long;

int f(int x, int y, int &c){
	c = 0;
	while (y > 0) {
		c += 1;
		int t = x % y;
		x = y;
		y = t;
	}
	return x;
}

int c[MAXN][MAXN];
int gcd[MAXN][MAXN];

int n, m, p;
int work(){
	if (scanf("%d%d%d", &n, &m, &p) != 3) return 0;
	int ans = 0;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= j; ++i) {
			for (int k = 0; k < c[j][i]; ++k) {
				if (i + k * j > n) break;
				LL maxP = (n-i-k*j) / (j * c[j][i]);
				LL x = gcd[j][i];
				LL A = j * (i + j * k) / (c[j][i] * x * x);
				LL B = j * j / (x * x);
				ans = (ans + A * maxP + A + ((maxP + 1) * maxP) / 2 % p * B) % p;
			}
		}
	}
	printf("%d\n", ans);
	return 1;
}

int main(){
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; j <= i; ++j) {
			gcd[i][j] = f(j, i, c[i][j]);
			gcd[j][i] = gcd[i][j];
			c[j][i] = c[i][j];
		}
	}
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; ++i) {
		work();
	}
	return 0;
}
