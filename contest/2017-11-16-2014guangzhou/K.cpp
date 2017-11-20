#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back
#define fi first 
#define se second 
#define mk(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxN = 100 + 13;
const int maxE = 40000 + 13;
const int inf = 0x7f7f7f7f;

struct Arc {
  int dest, cost;
};

vector<vector<Arc>> e;

inline void add_edge(int st, int ed, int c) {
  e[st].push_back(Arc{ed,c});

 // cout << st << " => " << ed << " (" << c << ")" << endl;
}

int v[maxN], dis[maxN];
queue<int> q;

void spfa(int S) {
  while(!q.empty()) q.pop();
  memset(v,0,sizeof(v));
  memset(dis,inf,sizeof(dis));
  q.push(S); dis[S] = 0; v[S] = 1;
  while(!q.empty()) {
    int id = q.front(); q.pop();
    v[id] = 0;
    for(int i = 0; i < (int)e[id].size(); i++) {
      int j = e[id][i].dest; int tc = e[id][i].cost;
      int temp = dis[id] + tc;
      if(temp < dis[j]) {
        dis[j] = temp;
        if(!v[j]) {
          q.push(j);
          v[j] = 1;
        }
      }
    }
  }
  return ;
}
void init(int n) {
  e.resize(n+1);
  for(int i = 0; i <= n; i++) e[i].clear();
}

int work() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n + m == 0) return 0;

  vector<pair<int, pair<int, int>>> rel;
  for (int i = 0; i < m; ++i) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    rel.push_back(make_pair(A, make_pair(B, C)));
  }

  int ans = 0;
  for (int i = 2; i < n; ++i) {
    init(n);
    for (int j = 0; j < (int)rel.size(); ++j) {
      int A = rel[j].first;
      int B = rel[j].second.first;
      int C = rel[j].second.second;
      if (A == i) continue;
      if (B == i) continue;
      add_edge(A, B, C);
      add_edge(B, A, C);
    }
    spfa(1);
    ans = max(ans, dis[n]);
  }
  if (ans > 0x3f3f3f3f) {
    puts("Inf");
  } else {
    printf("%d\n", ans);
  }

  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("K.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

