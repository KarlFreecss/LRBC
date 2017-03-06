#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 200+13;
const int maxM = 10000+13;
const int inf = 0x7f7f7f7f;

struct syn{
  int n;
  vector<int> num;
  vector<int> type;
};

int N,M,K;
int m[maxN],v[maxN],p[maxN];
int f[maxM];
vector<syn> xx[maxN];
vector<int> e[maxN];
queue<int> q;

inline void add_edge(int st, int ed) {
  e[st].push_back(ed);
}

void spfa() {
  while(!q.empty()) q.pop();
  rep(i, 1, N+1) {
    q.push(i);
    v[i] = 1;
  }
  while(!q.empty()) {
    int id = q.front(); q.pop(); v[id] = 0;
    bool change = false;
    ll tm = 0ll;
    for(auto ts: xx[id]) {
      tm = 0ll;
      rep(i, 0, ts.n) {
        tm += (ll) m[ts.type[i]]*ts.num[i];
      }
      if(tm < m[id]) {
        m[id] = tm;
        change = true;
      }
    }
    if(change) {
      for(auto tt: e[id]) {
        if(!v[tt]) {
          q.push(tt);
          v[tt] = 1;
        }
      }
    }
  }
  return ;
}

void init() {
  rep(i, 1, 1+N) e[i].clear();
  rep(i, 1, 1+N) xx[i].clear();
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif

  int T;
  scanf("%d",&T);
  for(int cas = 1; cas <= T; cas++) {
    scanf("%d%d%d",&M,&N,&K);
    init();
    rep(i, 1, 1+N) {
      int tc;
      scanf("%d",&tc);
      if(tc == 0) m[i] = inf;
      else  scanf("%d",&m[i]);
      scanf("%d",&p[i]);
    }
    rep(i, 1, 1+K) {
      int tx,ty;
      scanf("%d%d",&tx,&ty);
      syn tt; 
      tt.n = ty;
      rep(j, 1, ty+1) {
        int u,v;
        scanf("%d%d", &u, &v);
        tt.type.push_back(u);
        tt.num.push_back(v);
        add_edge(u,tx);
      }
      xx[tx].push_back(tt);
    }
    spfa();
    rep(i, 1, 1+M) f[i] = -1;
    f[0] = 0;
    rep(i, 1, 1+N) {
      rep(j, 0, 1+M-m[i]) if(f[j] >= 0) {
        f[j+m[i]] =max(f[j]+p[i], f[j+m[i]]);
      }
    }
    int ans = 0;
    rep(i, 1, 1+M) {
      if(ans < f[i]) ans = f[i];
    }
    printf("Case #%d: %d\n", cas, ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

