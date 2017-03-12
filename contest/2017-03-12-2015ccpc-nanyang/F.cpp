#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 1e5+13;

vector<int> e[maxN];
vector<int> e2[maxN];
int N,M;
int x[maxN],y[maxN],c[maxN],w[maxN];
int low[maxN],dfn[maxN],s[maxN],belong[maxN];
int index,top,scc,instack[maxN];
int num[maxN];

void tarjan(int u) {
  low[u] = dfn[u] = ++index;
  s[top++] = u;
  instack[u] = true;
  for(auto v:e[u]) {
    if(!dfn[v]) {
      tarjan(v);
      if(low[v] < low[u]) low[u] = low[v];
    }
  }
  if(low[u] == dfn[u]) {
    scc++;
    int tt=-1;
    do {
      tt = s[--top];
      instack[tt] = false;
      belong[tt] = scc;
      num[scc]++;
    }while(tt!=u);
  }
}

void slove() {
  memset(dfn, 0, sizeof(dfn));
  memset(instack, 0, sizeof(instack));
  memset(num, 0, sizeof(num));
  index = scc = top = 0;
  rep(i, 1, 1+M) {
    if(!dfn[i]) tarjan(i);
  }
}

void init() {
  rep(i,1,M+1) e[i].clear();
  rep(i,1,M+1) e2[i].clear();
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  for(int cas = 1; cas <= T; cas++) {
    scanf("%d%d", &N, &M);
    init();
    rep(i,1,N+1) scanf("%d", &x[i]);
    rep(i,1,N+1) scanf("%d", &y[i]);
    rep(i,1,N+1) scanf("%d", &c[i]);
    rep(i,1,M+1) scanf("%d", &x[i]);
    rep(i,1,N+1) {
      if(w[y[i]]>0)
        e[x[i]].push_back(y[i]);
    }
    slove();
    rep(i,1,M+1) {
      cout<<belong[i]<<' ';
    }
    cout<<endl;
    bool ok = true;
    rep(i,1,M+1) {
      if(w[i]==2 && num[belong[i]]>1) {
        ok = false;
        break;
      }
    }
    rep(i,1,N+1) {
      if(w[y[i]]>0)
        e2[x[i]].push_back(y[i]);
    }
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

