#include<bits/stdc++.h>

#define DEBUF printf("%d", __LINE__)

using namespace std;

int n, m, k;

const int MAXN = 2e5+5;
const int MAXM = 2e5+5;

struct EDGE{
	int to, next;
}edge[MAXM * 2];
int first[MAXN];
int vis[MAXN];
int tot;

int dfn[MAXN * 3];
int dfc;

void init(int n){
	tot = 0;
	dfc = 0;
	for (int i = 1; i <= n; ++i) {
		first[i] = -1;
		vis[i] = 0;
	}
}

void add_edge(int from, int to){
	edge[tot] = EDGE{to, first[from]};
	first[from] = tot++;
}


void dfs(int x){
	dfn[dfc++] = x;
	vis[x] = 1;
	for (int i = first[x]; i != -1; i = edge[i].next) {
		int to = edge[i].to;
		if (vis[to]) continue;
		dfs(to);
		dfn[dfc++] = x;
	}
}

int work(){
	if (scanf("%d%d%d", &n, &m, &k) != 3) return 0;
	init(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}

	dfs(1);

	int num = (2*n-1)/k;
	int tot = dfc;
	int count = 0;
	int offset = dfc - num * k;
	for (int i = 0; i < k; ++i) {
		int nu = num;
		if (i < offset) nu++;
		printf("%d ", nu);
		for (int k = count; k < count + nu; ++k) printf("%d%c", dfn[k], " \n"[k+1 == count + nu]);
		count += nu;
	}
	return 1;
}

int main(){
	while (work());
}
