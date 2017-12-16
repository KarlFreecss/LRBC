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

const int maxN = 4000 + 13;
const int maxM = maxN * maxN + 13;

struct LogVar {
  int index;
  bool pre;
  LogVar(int index = 0, bool pre = false) : index(index), pre(pre){};
};

struct BinExp {
  LogVar p, q;
  BinExp(LogVar p = LogVar(), LogVar q = LogVar()) : p(p), q(q){};
};

inline int get_value(int sol[maxN], int n, int x) {
  int r = x > n ? x - n : x;
  if(sol[r] == -1) 
    return -1;
  return x > n ? !sol[r] : sol[r];
}

int N, M;
vector<int> adj[maxN], c[maxN];
int low[maxN], dfn[maxN], s[maxN], top, cnt;
int belong[maxN];
int id_cnt;
bool vis[maxN];

void add_edge(int st, int ed) {
  //cout << "edge = " << st << " " << ed << endl;
  adj[st].push_back(ed);
}

stack<int> xx;

void tarjan(int u) {
  low[u] = dfn[u] = ++id_cnt;
  s[top++] = u;
  vis[u] = 1;
  for(auto id : adj[u]) {
    if(!dfn[id]) {
      tarjan(id);
      low[u] = min(low[u], low[id]);
    } else if(vis[id]) 
      low[u] = min(low[u], dfn[id]);
  }
  if(low[u] == dfn[u]) {
    int v = -1;
    cnt++;
    do {
      v = s[--top];
      vis[v] = false;
      belong[v] = cnt;
    }while(v != u);
  }
}

inline bool two_SAT(int n, int m, BinExp a[maxM], int sol[maxN]) {
  for(int i = 1; i <= 2*n; i++) {
    c[i].clear(); vis[i] = false;
    adj[i].clear();
  }
  id_cnt = 0;
  top = 0; cnt = 0;
  memset(vis,0,sizeof(vis));
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  memset(s, 0, sizeof(s));
  memset(belong, 0, sizeof(belong));
  for(int i = 1; i <= n; i++) sol[i] = -1;
  for(int i = 0; i < m; i++) {
    add_edge(a[i].p.index + a[i].p.pre * n, a[i].q.index + !a[i].q.pre * n);
    add_edge(a[i].q.index + a[i].q.pre * n, a[i].p.index + !a[i].p.pre * n);
  }
  for(int i = 1; i <= 2*n; i++) {
    if(!dfn[i]) tarjan(i);
  }
  /*
  for (int i = 1; i <= 2 * n; i ++) {
    cout << i << " dfn " << dfn[i] << endl; 
  }
  for (int i = 1; i <= 2 * n; i ++) {
    cout << i << " low " << low[i] << endl; 
  }
  for (int i = 1; i <= 2 * n; i ++) {
    cout << i << " belongto " << belong[i] << endl; 
  }
  */
  for(int i = 1; i <= n; i++) {
    if(belong[i] == belong[i+n]) return false;
  }
  for(int i = 1; i <= cnt; i++) {
    int val = 1;
    for(int j = 0; j < (int)c[i].size(); j++) {
      int cur = c[i][j];
      if(get_value(sol, n, cur) == 0) 
        val = 0;
      for(auto id : adj[cur]) {
        if(get_value(sol, n, id) == 0) 
          val = 0;
      }
      if(val == 0) break;
    }
    for(int j = 0; j < (int) c[i].size(); j ++) {
      if(c[i][j] > n) 
        sol[c[i][j] - n] = !val;
      else 
        sol[c[i][j]] = val;
    }
  }
  return true;
}

BinExp a[maxM];
int sol[maxN];
vector<int> v[maxN];

int work() {
  //cout << "==================" << endl;
  if(scanf("%d%d", &N, &M) != 2) return 0;
//  cout << N << " " << M << endl;
  for (int i = 1; i <= N; i ++)
    v[i].clear();
  for(int i = 0; i < M; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0 && y < 0) {
      v[abs(x)].push_back(abs(y));
      v[abs(y)].push_back(abs(x));
    }
    a[i] = BinExp(LogVar(abs(x), x>0), LogVar(abs(y), y>0));
  }
  bool satVal = two_SAT(N, M, a, sol);
//  cout << "satVal = " << satVal << endl;
  if (!satVal) {
    printf("0\n");
    return 1;
  }
  int T = M;
  for (int i = 1; i <= N; i ++) {
    for (int j = i; j <= N; j ++) {
      a[T ++] = BinExp(LogVar(i, true), LogVar(j, true));
    }
  }
  satVal = two_SAT(N, T, a, sol);
  if (satVal) {
    printf("-1\n");
    return 1;
  }
  for (int i = 1; i <= N; i ++) {
    a[M] = BinExp(LogVar(i, true), LogVar(i, true));
    satVal = two_SAT(N, M + 1, a, sol);
    if (!satVal) {
      //cout << "i " << i << endl;
      printf("1\n");
      return 1;
    }
  }
  for (int i = 1; i <= N; i ++) {
    if (v[i].size() > 0)
      sort(v[i].begin(), v[i].end());
  }
  /*
  for (int i = 1; i <= N; i ++) {
    if (v[i].size() >= 2) {
      int x = v[i][0], y = v[i][v[i].size() - 1];
      a[M] = BinExp(LogVar(x, true), LogVar(y, true));
      satVal = two_SAT(N, M + 1, a, sol);
      if (!satVal) {
        printf("1\n");
        return 1;
      }
    }
  }
  */
  
  printf("2\n");
  return 1;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  //for(int i = 1; i <= 1; i++) 
  //  work();
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

