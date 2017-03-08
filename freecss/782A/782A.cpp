#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int vis[MAXN];
int tot;

int work(){
	int ans = 0;
	if (scanf("%d", &n) != 1) return 0;
	for (int i = 1; i <= n; ++i) vis[i] = 0;
	tot = 0;
	for (int i = 0; i < n+n; ++i) {
		int x;
		scanf("%d", &x);
		if (vis[x]) {
			--tot;
		} else {
			vis[x] = 1;
			++tot;
			if (tot > ans) ans = tot;
		}
	}
	printf("%d\n", ans);
	return 1;
}

int main(){
	while (work());
	return 0;
}
