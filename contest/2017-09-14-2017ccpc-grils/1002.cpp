#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 3010;

class classroom {
  public:
    long long x, c;
    classroom(long long iX = 0, long long iC = 0) {
      x = iX;
      c = iC;
    }
};

classroom cr[MAXN];
long long sumDis[MAXN], f[MAXN];
int n;

bool cmp(classroom a, classroom b) {
  return a.x < b.x;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1002.in","r",stdin);
#endif
  long long x, c;
  while (cin >> n) {
    rep(i, 0, n) {
      scanf("%lld%lld", &x, &c);
      cr[i] = classroom(x, c);
    }
    sort(cr, cr + n, cmp);
    per(i, 0, n) {
      cr[i].x -= cr[0].x;
    }
    sumDis[0] = 0;
    rep(i, 1, n) {
      sumDis[i] = sumDis[i - 1] + cr[i].x;
    }
    f[n] = 0;
    rep(i, 0, n)
      f[i] = 1e15;
    per(i, 0, n + 1) {
      per(j, 0, i) {
        long long tmp = cr[j].c + sumDis[i - 1] - sumDis[j] - cr[j].x * (i - 1 - j);
        f[j] = min(f[j], f[i] + tmp);
      }
    }
    printf("%lld\n", f[0]);
  }
  return 0;
}

