#include <bits/stdc++.h>

using namespace std;

const int MAXN_ = 1e5+5;
const int MAXM_ = 1e5+5;

const int MAXN = MAXN_ * 11;
const int MAXM = MAXM_ * 11;

long long dist[MAXN];
int dic[MAXN];

struct EDGE{
	int to, next, w;
}edge[MAXM * 4];

const int mulf = 5;

int first[MAXN];
int tot;

void add_edge(const int from, const int to, const int w){
	edge[tot] = (EDGE){to, first[from], w};
	first[from] = tot++;
}

void buildGraph(const int l, const int r, const int index){
	if (l == r) {
		dic[l] = index;
		add_edge(index, index + MAXN_ * mulf, 0);
		add_edge(index + MAXN_ * mulf, index, 0);
		return ;	
	}
	add_edge(index, index<<1, 0);
	add_edge(index, index<<1|1, 0);
	
	add_edge((index<<1) + MAXN_ * mulf, index + MAXN_ * mulf, 0);
	add_edge((index<<1|1) + MAXN_ * mulf, index + MAXN_ * mulf, 0);
	int mid = (l + r) >> 1;
	buildGraph(l, mid, index<<1);
	buildGraph(mid+1, r, index<<1|1);
}

void insert(const int vIndex, const int L, const int R,
		const int l, const int r, const int index, const int value, const int type){
	
	if (r < L || R < l) return;
	if (L <= l && r <= R) {
		if (type <= 2) add_edge(vIndex, index, value);
		else if (type == 3) add_edge(index + MAXN_ * mulf, vIndex, value);
		return ;
	}

	int mid = (l + r) >> 1;
	insert(vIndex, L, R, l, mid, index<<1, value, type);
	insert(vIndex, L, R, mid+1, r, index<<1|1, value, type);
}

int n, q, s;

struct node{
	long long d;
	int	v;
	bool operator < (const node &T)const{
		return d > T.d;
	}
};

int vis[MAXN];

void dijkstra(const int S){
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<node> que;
	
	dist[S] = 0;
	que.push((node){0, S});
	while (!que.empty()){
		int x = que.top().v;
		que.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		
		for (int i = first[x]; i != -1; i = edge[i].next) {
			int to = edge[i].to;
			if (dist[to] > dist[x] + edge[i].w) {
				dist[to] = dist[x] + edge[i].w;
				que.push((node){dist[to], to});
			}
		}

	}
}

int main(){
	memset(first, 0xff, sizeof(first));
	tot = 0;
	scanf("%d%d%d", &n, &q, &s);
	buildGraph(1, n, 1);
	for (int i = 0; i < q; ++i) {
		int type, u, v, w, l, r;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d%d%d", &v, &u, &w);
			insert(dic[v], u, u, 1, n, 1, w, type);
		} else {
			scanf("%d%d%d%d", &v, &l, &r, &w);
			insert(dic[v], l, r, 1, n, 1, w, type);
		}
	}

	dijkstra(dic[s]);

	for (int i = 1; i <= n; ++i) {
		printf("%I64d%c", dist[dic[i]] != dist[0]?dist[dic[i]]:-1, " \n"[i==n]);
	}

	return 0;
} 
