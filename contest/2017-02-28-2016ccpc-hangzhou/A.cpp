#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 100;

long long a[MAXN];
long long n, k, sum, avg, res;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  long long T, t = 0;

  scanf("%lld", &T);
  while (T --) {
    t ++;
    scanf("%lld%lld", &n, &k);
    sum = 0;
    rep(i, 1, n + 1) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    printf("Case #%lld: ", t);
    if (sum % k != 0) {
      printf("-1\n");
      continue;
    }
    avg = sum / k;
    sum = 0;
    res = 0;
    rep(i, 1, n + 1) {
      if (sum != 0)
        res ++;
      sum += a[i];
      while (sum >= avg) {
        if (sum > avg)
          res ++;
        sum -= avg;
      }
    }
    printf("%lld\n", res);
  }

  return 0;
}

