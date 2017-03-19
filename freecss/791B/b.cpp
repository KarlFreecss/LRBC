#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150100;

typedef vector<int> EDGE;
vector<EDGE> edge(MAXN);
int vis[MAXN];
queue<int> que;

int BFS(int x){
	que.push(x);
	vis[x] = 1;
	long long e = 0;
	long long tot = 1;
//	cout << x << ' ' ;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		e += edge[x].size();
		for (int i = 0; i < edge[x].size(); ++i) {
			int y = edge[x][i];
			if (vis[y]) continue;
			vis[y] = 1;
			que.push(y);
			++tot;
		}
	}
	//cout << e << ' ' << tot << endl;
	return e == (tot-1) * tot;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	int flag = 1;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		if (!BFS(i)) flag = 0;
	}

	if (flag) puts("YES");
	else puts("NO");
	return 0;
} 
