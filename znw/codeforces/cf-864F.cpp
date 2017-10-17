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

const int maxN = 3000+13;
const int maxP = 16;
const int maxQ = 4e5 + 13;

struct query {
  int st,k,id;
};

vector<int> e[maxN];
vector<int> re[maxN];
vector<query> q[maxN];
int N,M,Q;
int f[maxN][maxP];
int v[maxN];
int ans[maxQ];

void dfs(int id) {
  v[id] = 1;
  for(auto tt:re[id]) 
    if(!v[tt]) dfs(tt);
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-864F.in","r",stdin);
#endif
  scanf("%d%d%d", &N, &M, &Q);
  int P = log(N)/log(2) + 1;
  rep(i , 1, M+1) {
    int a, b ;
    scanf("%d%d", &a, &b);
    e[a].pb(b);
    re[b].pb(a);
  }
  rep(i, 1, Q+1) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    q[b].pb({a,c,i});
  }
  rep(ed, 1, N+1) {
    if(q[ed].size() == 0) continue;
    memset(v,0,sizeof(v));
    memset(f,0,sizeof(f));
    dfs(ed);
    f[N+1][0] = N+1;
    f[ed][0] = N+1;
    rep(i, 1, N+1) {
      if(i == ed) continue;
      f[i][0] = 0;
      if(v[i]) {
        int k = N+1;
        for(auto tt:e[i]) 
          if(v[tt] && k > tt) k = tt;
        f[i][0] = k;
      }
    }
    rep(k, 1, P+1) 
      rep(i, 1, N+2) 
        f[i][k] = f[f[i][k-1]][k-1];
    for(auto tt:q[ed]) {
      int st = tt.st, k = tt.k, id = tt.id;
      ans[id] = -1;
      if(f[st][P] == N+1) {
        k--;
        rep(i, 0, P+1) {
          if(k == 0) break;
          if(k&1) st = f[st][i];
          k >>=1;
        }
        if(st != N+1) ans[id] = st;
      }
    }
  }
  rep(i, 1, Q+1) printf("%d\n", ans[i]);

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

