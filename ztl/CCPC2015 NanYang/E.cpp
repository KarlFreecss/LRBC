#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i ++)
#define per(i,a,b) for (int i = b-1; i >= a; i --)

const int MAXN = 1e5 + 100;
const int MAXPOW = 60;

class Road {
  public:
    long long x, y, val;
    Road(long long iX = 0, long long iY = 0, long long iVal = 0) {
      x = iX;
      y = iY;
      val = iVal;
    }
};

long long mi2[MAXPOW];
vector<Road> roads[MAXN];
long long f[MAXN];
long long loop[MAXN * 2];
long long N, M, K, res;

void dfs(long long x, long long faX, long long roadVal) {
  long long y, val;
  f[x] = roadVal;
  rep(i, 0, roads[x].size()) {
    y = roads[x][i].y;
    val = roads[x][i].val;
    if (y != faX) {
      if (f[y] == -1) {
        dfs(y, x, roadVal ^ val);
      } else {
        loop[K ++] = f[x] ^ f[y] ^ val;
      }
    }
  }
}
int main() {
  freopen("E.in", "r", stdin);
  long long T, x, y, val, chose;
  
  mi2[0] = 1;
  rep(i, 1, MAXPOW)
    mi2[i] = mi2[i - 1] * 2;
  scanf("%lld", &T);
  rep(cas, 1, T + 1) {
    res = 0;
    scanf("%lld%lld", &N, &M);
    rep(i, 1, N + 1) {
      roads[i].clear();
      f[i] = -1;
    }
    rep(i, 0, M) {
      scanf("%lld%lld%lld", &x, &y, &val);
      roads[x].push_back(Road(x, y, val));
      roads[y].push_back(Road(y, x, val));
    }
    K = 0;
    dfs(1, -1, 0);
    per(i, 0, MAXPOW) {
      chose = -1;
      rep(j, 0, K)
        if ((loop[j] & mi2[i]) != 0) {
          chose = loop[j];
          break;
        }
      if ((res & mi2[i]) == 0) {
        if (chose != -1)
          res ^= chose;
      }
      rep(j, 0, K)
        if ((loop[j] & mi2[i]) != 0)
          loop[j] ^= chose;
    }
    printf("Case #%d: %lld\n", cas, res);
  }
  return 0;
}
