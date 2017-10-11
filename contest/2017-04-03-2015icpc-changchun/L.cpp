#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 55;
int c[MAXN][MAXN];
int n, m, res;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("L.in","r",stdin);
#endif
  int T, t;
  scanf("%d", &T);
  while (T --) {
    memset(c, 0, sizeof(c));
    scanf("%d%d", &n, &m);
    res = 0;
    rep(i, 1, n + 1)
      rep(j, 1, m + 1) {
        scanf("%d", &c[i][j]);
        if (c[i][j] > 0)
          res ++;
      }
    rep(i, 1, n + 1)
      rep(j, 1, m + 1) {
        if (c[i][j] > c[i + 1][j])
          res += (c[i][j] - c[i + 1][j]);
        if (c[i][j] > c[i - 1][j])
          res += (c[i][j] - c[i - 1][j]);
        if (c[i][j] > c[i][j + 1])
          res += (c[i][j] - c[i][j + 1]);
        if (c[i][j] > c[i][j - 1])
          res += (c[i][j] - c[i][j - 1]);
      }
    printf("%d\n", res);
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

