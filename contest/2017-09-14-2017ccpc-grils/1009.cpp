#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+5;
const int MAXN = 2e5+5;
const int MAXD = 20;

struct EDGE{
  int to, next;
} edge[MAXM];
int first[MAXN];
int tot;

void add_edge(int from, int to){
  edge[tot] = (EDGE){to, first[from]};
  first[from] = tot++;
}

int f[MAXN][MAXD];

void dfs(int u, int fa){
  f[u][0] = fa;
  for (int i = first[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u);
  }
}

void recognise_ancestry_and_go_home(int n){
  dfs(1, 1);
  for (int i = 1; i < MAXD; ++i) {
    for (int j = 1; j < n; ++i) {
      f[j][i] = f[f[j][i-1][i-1]];
    }
  }
}

void party_always_exist(int id){
  memset(f, 0, sizeof(f));
  memset(first, 0xff, sizeof(first));
  tot = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int s, t;
    scanf("%d%d", &s, &t);
    add_edge(s, t);
    add_edge(t, s);
  }

  recognise_ancestry_and_go_home(n);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(".in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    party_always_exist(i);
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

