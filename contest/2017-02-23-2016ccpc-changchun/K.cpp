#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MM = 1e9 + 7;

long long a[100], aValue[100][100];
long long mi2Value[300];
long long n, m;

long long mi2(int h) {
  long long res = 1;
  if (h < 0) return 0;
  return mi2Value[h];
}
long long toNum(long long a[], int x, int y) {
  if (aValue[x][y] != -1)
    return aValue[x][y];
  long long res = 0;
  per(i, x, y) {
    res *= 2;
    res += a[i];
  }
  res %= MM;
  aValue[x][y] = res;
  return res;
}
int main()
{
#ifndef ONLINE_JUDGE
#endif
  long long T, t = 0, ans, x, y, last, preNum, lastNum;
  vector<long long> v;
  scanf("%d", &T);
  mi2Value[0] = 1;
  rep(i, 1, 300)
    mi2Value[i] = (mi2Value[i - 1] * 2) % MM;
  while (T --) {
    t ++;
    scanf("%lld", &n);
    ans = m = 0;
    v.clear();
    while (n > 0) {
      a[m] = n % 2;
      if (a[m] == 1) v.push_back(m);
      m ++;
      n /= 2;
    }
    rep(i, 0, m)
      rep(j, 0, m)
        aValue[i][j] = -1;
    rep(i, 0, v.size()) {
      x = v[i];
      //a[x] == 0 && b[x] == 0
      rep(y, 0, x) {
        ans += mi2(2 * y + (x - y - 1)) + 2 * y * mi2(2 * y - 1 + (x - y - 1));
        ans %= MM;
      }
      //a[x] == 1 && b[x] == 0
      last = toNum(a, 0, x);
      ans += (last + 1) * mi2(x);
      ans %= MM;
      ans += (x * (last + 1) % MM) * mi2(x - 1);
      ans %= MM;
      rep(y, 0, x) {
        preNum = toNum(a, y + 1, x);
        lastNum = toNum(a, 0, y);
        if (a[y] == 1) {
          ans += preNum * mi2(y + x);
          ans %= MM;
          ans += (lastNum + 1) * mi2(x);
          ans %= MM;
        } else {
          ans += preNum * mi2(y + x);
          ans %= MM;
        }
      }
    }
    printf("Case #%lld: %lld\n", t, ans);
  }

  return 0;
}

