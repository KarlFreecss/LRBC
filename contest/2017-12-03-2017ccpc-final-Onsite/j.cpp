#include<bits/stdc++.h>
using namespace std;

const int maxN = 2000 + 13;
const int inf = 0x7f7f7f7f;

vector<pair<int, int> > adj[maxN];

queue<int> q;
long long dis[maxN];
int cnt[maxN];
int v[maxN];
int minus_cycle;
int N, M, X;

void add_edge(int st, int ed, int x) {
  //cout << st << ' ' << ed << ' ' << x << endl;
  adj[st].push_back(make_pair(ed,x));
}
bool spfa() {
  memset(cnt, 0, sizeof(cnt));
  memset(v, 0, sizeof(v));
  memset(dis, 0, sizeof(dis));
  //cout << dis[0] << endl;
  while(!q.empty()) q.pop();
  q.push(1); cnt[1] =1; dis[1] = 0;
  v[1] = 1;
  while(!q.empty()) {
    int id = q.front(); v[id] = 0;
    q.pop();
    for(int i = 0; i < (int)adj[id].size(); i++) {
      int dest, cost;
      dest = adj[id][i].first; 
      cost = adj[id][i].second;
      long long temp = dis[id] + cost;
      if(temp > dis[dest]) {
	dis[dest] = temp;
	if(!v[dest]) {
	  cnt[dest] ++;
	  q.push(dest);
	  v[dest] = 1;
	  if(cnt[dest] >= minus_cycle) {
	    return false;
	  }
	}
      }
    }
  }
  return true;
}

void work() {
  scanf("%d%d%d", &N, &M, &X);
  minus_cycle = N;
  for(int i = 0; i <= N; i++) {
    adj[i].clear();
  }
  for(int i = 1; i <= M; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a == b && c == d) {
      add_edge(a, c, X);
      add_edge(c, a, -X);
      continue;
    }
    if(a == c && b == d) {
      add_edge(a, b, X+1);
      continue;
    }
    if(b <= c) {
      add_edge(a, d, X+1);
      add_edge(c, b, 1-X);
    }
  }
  for(int i = 2; i <= N; i++) {
    add_edge(i-1, i, 1);
  }
  if(spfa()) {
    printf("%d", (int)(dis[2] - dis[1]));
    for(int i = 3; i <= N; i++) {
      printf(" %d", (int)(dis[i] - dis[i-1]));
    }
    printf("\n");
  } else {
    printf("IMPOSSIBLE\n");
  }
  /*
  for(int i = 1; i <= N; i++) {
    cout << dis[i] << ' ';
  }
  cout << end;
  */
  return ;
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    printf("Case #%d: ", i);
    work();
  }
  return 0;
}
