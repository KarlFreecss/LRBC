#include <bits/stdc++.h>

using namespace std;

const int MAXN = 7e3 + 7;

int n;
vector<int> k[2];
int f[MAXN][2];
int vis[MAXN][2];
int updated[MAXN][2];
queue<pair<int, int> > que;

void work(){
	memset(f, 0xff, sizeof(f));
	f[0][0] = 0;
	f[0][1] = 0;
	vis[0][0] = 1;
	vis[0][1] = 1;
	updated[0][0] = k[0].size();
	updated[0][1] = k[1].size();
	que.push(make_pair(0, 1));
	que.push(make_pair(0, 0));

	while (!que.empty()){
		auto node = que.front();
		que.pop();
		int x = node.first;
		int w = node.second;
		//printf("f[%d][%d] = %d\n", x, w, f[x][w]);
		
		for (int i = 0; i < k[w^1].size(); ++i) {
			int y = (x - k[w^1][i]);
			if (y < 0) y += n;
			if (vis[y][w^1]) continue;

			
			if (f[x][w] == 0) {
				f[y][w^1] = 1;
				vis[y][w^1] = 1;
				que.push(make_pair(y, w^1));
				continue;
			}

			updated[y][w^1]++;
			if (!vis[y][w^1] && updated[y][w^1] == k[w^1].size()) {
				vis[y][w^1] = 1;
				f[y][w^1] = 0;
				que.push(make_pair(y, w^1));
				continue;
			}
		}	
	}

}

int main(){
	cin >> n;
	
	int m;
	for (int l = 0; l < 2; ++l) {
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int x;
			cin >> x;
			k[l].push_back(x);
		}
	}

	work();
	const char loop[] = "Loop";
	const char lose[] = "Lose";
	const char win[] = "Win";

	for (int i = 1; i < n; ++i) {
		printf("%s%c", f[i][0] == -1 ? loop : f[i][0] == 0 ? lose : win, " \n"[i+1 == n]);
	}
	for (int i = 1; i < n; ++i) {
		printf("%s%c", f[i][1] == -1 ? loop : f[i][1] == 0 ? lose : win, " \n"[i+1 == n]);
	}
	
	return 0;
} 
