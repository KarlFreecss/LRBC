#include<bits/stdc++.h>
#define DEBUG printf("%d\n", __LINE__)

using namespace std;

const int MAXN = 2e5+5;

int n;

struct EDGE{
	int to, next;
}edge[MAXN * 2];
int first[MAXN];
int d[MAXN];
int col[MAXN];
int tot;
int ans;

void add_edge(int from, int to){
	edge[tot] = (EDGE){to, first[from]};
	first[from] = tot++;
}

void dfs(int u, int fa){
	int pCol = 1;
	ans = max(d[u]+1, ans);
	for (int i = first[u]; i != -1; i = edge[i].next){
		while (col[u] == pCol || col[fa] == pCol) ++pCol;
		int v = edge[i].to;
		if (v == fa) continue;
		col[v] = pCol++;
		dfs(v, u);
	}
}

int work(){
	if (scanf("%d", &n) != 1) return 0;
	for (int i = 1; i <= n; ++i) {
		first[i] = -1;
		d[i] = 0;
	}
	tot = 0;
	ans = 0;
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
		d[x]++;
		d[y]++;
	}
	col[1] = 1;
	dfs(1, 0);
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", col[i], " \n"[i==n]);
	}

	return 1;
}

int main(){
	while (work());
	return 0;
}
