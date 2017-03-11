#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i ++)
#define per(i,a,b) for (int i = b-1; i >= a; i --)

const int MAXN = 666 + 10;

long long c[MAXN][MAXN], gcdValue[MAXN][MAXN];
long long n, m, MM, res;

long long gcd(long long x, long long y) {
  long long t, a = x, b = y;
  c[a][b] = 0;
  while (y > 0) {
    c[a][b] ++;
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
void preprocess() {
  rep(i, 1, MAXN) {
    rep(j, 1, MAXN) {
      gcdValue[i][j] = gcd(i, j);
    }
  }
  return;
}
void cal(long long a, long long b) {
  long long loop = c[b][a];
  long long den = loop * gcdValue[b][a] * gcdValue[b][a];
  long long maxK = (n - b) / a;
  long long loopN = (maxK + 1) / loop;
  long long loopSum1, loopSum2, deltaLoop;
  long long temp = 0;
  loopSum1 = loopSum2 = 0;
  rep(i, 0, loop)
    loopSum1 += ( a * (b + a * i) ) / den;

  rep(i, loop, loop * 2)
    loopSum2 += ( a * (b + a * i) ) / den;

  deltaLoop = loopSum2 - loopSum1;
  deltaLoop %= MM;
  long long i, loopValue = loopSum1 % MM;
  temp = (loopN - 1) * loopN / 2;
  temp %= MM;
  temp *= deltaLoop;
  temp %= MM;
  res += temp;
  res %= MM;
  res += (loopValue * loopN) % MM;
  res %= MM;
  for (i = loop * loopN; i <= maxK; i ++) {
    res += ( a * (b + a * i) ) / den;
    res %= MM;
  }

}
int main() {
//  freopen("K.in", "r", stdin);
  int T, t, temp;

  preprocess();
  scanf("%d", &T);
  rep(t, 0, T) {
    scanf("%lld%lld%lld", &n, &m, &MM);
    res = 0;
    if (n <= m) {
      rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
          res += 1ll * i * j / (c[i][j] * gcdValue[i][j] * gcdValue[i][j]);
          res %= MM;
        }
      }
    } else {
      rep(i, 1, m + 1) {
        rep(j, 1, i + 1) {
          cal(i, j);
        }
      }
    }
    printf("%lld\n", res);
  }

  return 0;
}
