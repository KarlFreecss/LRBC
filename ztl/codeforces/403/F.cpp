#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i ++)
#define per(i,a,b) for (int i = b-1; i >= a; i --)

const long long MAXANS = 1e18;
const int MAXPOW = 62;
const int MAXN = 501;

bitset<MAXN> f[MAXPOW][MAXN], g[MAXPOW][MAXN];
bitset<MAXN> reached;
long long mi2[MAXPOW];
int n, m;

bitset<MAXN> toReach(bitset<MAXN> last, int i, bool pedestrianOrBike) {
  bitset<MAXN> res;
  res.reset();
  rep(j, 1, n + 1)
    if (last[j]) {
      if (pedestrianOrBike) {
        res |= f[i][j];
      } else {
        res |= g[i][j];
      }
    }
  return res;
}
bool whetherReach(bitset<MAXN> last, int i, bool pedestrianOrBike) {
  bitset<MAXN> res;
  res = toReach(last, i, pedestrianOrBike);
  rep(j, 1, n + 1)
    if (res[j])
      return true;
  return false;
}

int main() {
//  freopen("F.in", "r", stdin);
  int x, y, t;
  long long ans;

  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  
  mi2[0] = 1;
  rep(i, 1, MAXPOW)
    mi2[i] = mi2[i - 1] * 2;

  scanf("%d%d", &n, &m);
  rep(i, 0, m) {
    scanf("%d%d%d", &x, &y, &t);
    if (t == 0) {
      f[0][x][y] = 1;
    } else {
      g[0][x][y] = 1;
    }
  }

  rep(i, 1, MAXPOW) {
    rep(j, 1, n + 1) {
      rep(k, 1, n + 1) {
        if (f[i - 1][j][k])
          f[i][j] |= g[i - 1][k];
        if (g[i - 1][j][k])
          g[i][j] |= f[i - 1][k];
      }
    }
  }
  
  rep(i, 1, n + 1)
    rep(j, 1, n + 1)
      if (f[MAXPOW - 1][i][j]) {
        printf("-1\n");
        return 0;
      }

  ans = 0;
  reached.set();
  bool pedestrianOrBike = true;
  while (whetherReach(reached, 0, pedestrianOrBike)) {
    int i;
    for (i = 1; i < MAXPOW; i ++) 
      if (!whetherReach(reached, i, pedestrianOrBike))
        break;
    reached = toReach(reached, i - 1, pedestrianOrBike);
    ans += mi2[i - 1];
    pedestrianOrBike = !pedestrianOrBike;
  }

  if (ans > 1e18) {
    printf("-1\n");
  } else {
    printf("%I64d\n", ans);
  }
  return 0;
}
