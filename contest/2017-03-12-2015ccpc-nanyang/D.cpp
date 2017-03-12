#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1010;
const int MAXL = 2010;

class Stick {
  public:
    long long len, val;
    Stick(long long iLen = 0, long long iVal = 0) {
      len = iLen;
      val = iVal;
    }
};

long long f[MAXN][MAXL], g[MAXN][MAXL];
Stick sticks[MAXN];
long long N, L, res;
bool cmp(Stick a, Stick b) {
  return a.len < b.len;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  long long T, len, val, sumLen, sumVal;
  scanf("%lld", &T);
  rep(t, 1, T + 1) {
    scanf("%lld%lld", &N, &L);
    res = 0;
    rep(i, 1, N + 1) {
      scanf("%lld%lld", &len, &val);
      res = max(res, val);
      sticks[i] = Stick(len, val);
    }
    sort(sticks + 1, sticks + N + 1, cmp);
    rep(i, 0, N + 2)
      rep(j, 0, L + 1) {
        f[i][j] = g[i][j] = 0;
      }
    g[N][sticks[N].len] = sticks[N].val;
    rep(j, 1, L + 1)
      g[N][j] = max(g[N][j], g[N][j - 1]);
    per(i, 1, N) {
      rep(j, 1, L + 1) {
        g[i][j] = g[i + 1][j];
      }
      rep(j, i + 1, N + 1) {
        sumLen = sticks[i].len + sticks[j].len;
        sumLen = (sumLen + 1) / 2;
        sumVal = sticks[i].val + sticks[j].val;
        g[i][sumLen] = max(g[i][sumLen], sumVal);
      }
      rep(j, 1, L + 1)
        g[i][j] = max(g[i][j], g[i][j - 1]);
    }

    rep(i, 1, N + 1) {
      len = sticks[i].len;
      val = sticks[i].val;
      rep(j, 0, L + 1)
        f[i][j] = f[i - 1][j];
      per(j, len, L + 1) {
        f[i][j] = max(f[i][j], f[i][j - len] + val);
      }
      rep(j, 1, L + 1)
        f[i][j] = max(f[i][j], f[i][j - 1]);
    }

    rep(i, 0, N + 1) {
      rep(j, 0, L + 1) {
        res = max(res, f[i][j] + g[i + 1][L - j]);
/*        cout << "==============" << endl;
        cout << res << endl;
        cout << i << " " << j << " " << f[i][j] << endl;
        cout << i + 1 << " " << L - j << " " << g[i + 1][L - j] << endl;
*/      }
    }
    printf("Case #%d: %lld\n", t, res);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

