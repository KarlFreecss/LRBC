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

#define DEBUG_INFO(x) //cerr << __LINE__ << " : " #x " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int MAXN = 1e3 + 3;
const int MAXT = 1e3 + 3;


int g[MAXN], d[MAXN];
int f[MAXN][MAXT];

int getValue(const int p, const int t){
  return max(0, g[p] - (t-1) * d[p]);
}

vector<pair<int, int>> edge[MAXN];

int work(){
  int n, m;
  if (scanf("%d%d", &n, &m) != 2) return false;
  for (int i = 0; i < MAXN; ++i) {
    edge[i].clear();
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &g[i], &d[i]);
  }

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
//    if (a == b) continue;
    edge[b].push_back(make_pair(a, c));
    edge[a].push_back(make_pair(b, c));
  }
  memset(f, 128 , sizeof(f));
  int ans = f[1][1] = getValue(1, 1);
  for (int t = 2; t < MAXT; ++t) {
    for (int u = 1; u <= n; ++u) {
      for (int i = 0; i < (int)edge[u].size(); ++i) {
        int ft = t - edge[u][i].second;
        DEBUG_INFO(ft);
        if (ft <= 0) continue;
        int v = edge[u][i].first;
        DEBUG_INFO(u);
        DEBUG_INFO(v);
        DEBUG_INFO(t);
        DEBUG_INFO(f[u][t]);
        f[u][t] = max(f[u][t], f[v][ft] + getValue(u, t));
      }
      ans = max(ans, f[u][t]);
    }
  }
  
  printf("%d\n", ans);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif

  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

