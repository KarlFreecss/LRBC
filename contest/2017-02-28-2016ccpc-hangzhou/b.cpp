#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+3;
const int MAXM = MAXN * MAXN;

typedef long long ll;
typedef unsigned long long ull;

int n;

int x[MAXN], y[MAXN], r[MAXN], c[MAXN];

struct EDGE{
  int to, next;
};

struct TARJAN{
  EDGE edge[MAXM];
  int first[MAXN];
  int tot;

  int head[MAXN];
  int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
  int Index, top;
  int scc;
  bool Instack[MAXN];
  int num[MAXN];

  void init(int n){
    tot = -1;
    for (int i = 0; i <= n; ++i) {
      first[i] = -1;
    }
  }

  void add_edge(const int from, const int to) {
    edge[tot] = (EDGE){to, first[from]};
    first[from] = tot++;   
  }

  void Tarjan(int u){
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for (int i = first[u]; i != -1; i = edge[i].next) {
      v = edge[i].to;
      if (!DFN[v]) {
        Tarjan(v);
        if (Low[u] > Low[v]) Low[u] = Low[v];
      } else if (Instack[v] && Low[u] > DFN[v]) {
        Low[u] = DFN[v];
      }
    }
    if (Low[u] == DFN[u]) {
      scc++;
      do {
        v = Stack[--top];
        Instack[v] = false;
        Belong[v] = scc;
        num[scc]++;
      } while (v != u);
    }
  }

  void solve(int N){

    for (int i = 0; i <= N; ++i) {
      DFN[i] = 0;
      Instack[i] = 0;
      num[i] = 0;
    }
    Index = scc = top = 0;
    for (int i = 1; i <= N; i++){
      if (!DFN[i])
        Tarjan(i);
    }
  } 

}tarjan;

inline
ll dist(int x, int y){
  return 1ll * x * x + 1ll * y * y;
}

struct MINCOST{
  int d[MAXN];
  int cost[MAXN];
  void init(const int N){
    for (int i = 0; i <= N; ++i) {
      cost[i] = 0x7fffffff;
      d[i] = 0;
    }
  }
  
  int ans(int N){
    int res = 0;
    for (int i = 1; i <= N; ++i) {
      if (d[i] == 0 && cost[i] < 1e5) res += cost[i];
    }
    return res;
  }

}minCost;

void solve(const int id){
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &x[i], &y[i], &r[i], &c[i]);
  }
  tarjan.init(n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dist(x[i] - x[j], y[i] - y[j]) <= 1ll * r[i] * r[i]) {
        tarjan.add_edge(i, j);
      }     
    }
  }
  tarjan.solve(n);
  minCost.init(n);
  for (int v = 1; v <= n; ++v) {
    minCost.cost[tarjan.Belong[v]] = min(minCost.cost[tarjan.Belong[v]],
       c[v]); 
    for (int i = tarjan.first[v]; i != -1; i = tarjan.edge[i].next) {
      if (tarjan.Belong[tarjan.edge[i].to] == tarjan.Belong[v]) continue;
      ++minCost.d[tarjan.Belong[tarjan.edge[i].to]];
    }
  }
  printf("Case #%d: %d\n", id, minCost.ans(n));
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

