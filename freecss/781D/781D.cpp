#include<bits/stdc++.h>

using namespace std;
using LL = long long;


#define rep(i,a,b) for(int i = a; i < b; i++)
#define per(i,a,b) for(int i=b-1; i >=a; i++)

const int MAXK = 61;
const int MAXN = 505;

LL ans[MAXK][2][MAXN];
bitset<MAXN> f[MAXK][2][MAXN];

int n, m;

int work(){
	if (scanf("%d%d", &n, &m) != 2) return 0;

	rep(i, 0, MAXK) 
		rep(j, 0, n){
			ans[i][0][j] = 0;
			ans[i][1][j] = 0;
			f[i][0][j] = 0;
			f[i][1][j] = 0;
		}

	rep(i, 0, m) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		ans[0][t][u-1] = 1;
		f[0][t][u-1][v-1] = 1;
	}

	rep(k, 1, MAXK){
		rep(t, 0, 2) {
			rep(u, 0, n) {
				ans[k][t][u] = ans[k-1][t][u];
				rep(v, 0, n) {
					if (f[k-1][t][u][v]) {
						ans[k][t][u] = max(ans[k][t][u], (1LL << (k-1)) + ans[k - 1][t ^ 1][v]);
						f[k][t][u] |= f[k-1][t^1][v];
					}
				}
			}
		}
	}

	if (ans[MAXK-1][0][0] > 1e18) {
		cout << -1 << endl;
	} else {
		cout << ans[MAXK-1][0][0] << endl;
	}

	return 1;
}

int main(){
	while (work());
	return 0;
}
