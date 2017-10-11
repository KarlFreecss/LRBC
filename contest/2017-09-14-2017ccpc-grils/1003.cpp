#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 10;

int a[MAXN];
int res[MAXN];
int n;

int gcd(int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  if (x == 0)
    return y;
  else 
    return gcd(y % x, x);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1003.in","r",stdin);
#endif
  int T, res1, res2, allGCD, finalRes;
  scanf("%d", &T);
  while (T --) {
    scanf("%d", &n);
    rep(i, 0, n) {
      scanf("%d", &a[i]);
      res[i] = 1;
    }
    res1 = a[0];
    rep(i, 1, n - 1) {
      res1 = gcd(res1, a[i]);
    }
    allGCD = gcd(res1, a[n - 1]);
    rep(i, 0, n) {
      a[i] /= allGCD;
    }
    int k = 2, count, pos;
    while (k * k <= a[n - 1]) {
      while (a[n - 1] % k == 0) {
        a[n - 1] /= k;
        count = 0;
        pos = -1;
        rep(i, 0, n - 1) {
          if (a[i] % k == 0) {
            a[i] /= k;
          } else {
            count ++;
            pos = i;
          }
        }
        if (count == 1) {
          res[pos] *= k;
        }
      }
      k ++;
    }
    k = a[n - 1];
    count = 0;
    pos = -1;
    rep(i, 0, n - 1) {
      if (a[i] % k == 0) {
        a[i] /= k;
      } else {
        count ++;
        pos = i;
      }
    }
    if (count == 1) {
      res[pos] *= k;
    }

    res2 = 1;
    rep(i, 0, n - 1) {
      res2 = max(res2, res[i]);
    }
    finalRes = max(res1, res2 * allGCD);
    printf("%d\n", finalRes);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

