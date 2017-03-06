#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e6 + 100;

long long washCostTime[MAXN], dryerCostTime[MAXN];
long long laundryWash[MAXN], laundryDryer[MAXN];
long long L, N, M;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("B.in","r",stdin);
#endif
  long long T, t, res, time;
  long long l, r, mid, sum, j;
  scanf("%lld", &T);
  rep(t, 1, T + 1) {
    scanf("%lld%lld%lld", &L, &N, &M);
    rep(i, 1, N + 1) {
      scanf("%lld", &washCostTime[i]);
    }
    rep(i, 1, M + 1) {
      scanf("%lld", &dryerCostTime[i]);
    }
    
    l = 0; r = 1e16; res = 1e16;
    while (l <= r) {
      mid = (l + r) / 2;
      sum = 0;
      rep(i, 1, N + 1) {
        sum += mid / washCostTime[i];
        if (sum >= L) break;
      }
      if (sum >= L) {
        r = mid - 1;
        res = mid;
      } else {
        l = mid + 1;
      }
    }
    j = 1;
    rep(i, 1, N + 1) {
      time = washCostTime[i];
      if (time < res) {
        laundryWash[j ++] = time;
        time += washCostTime[i];
      }
    }
    for (;j <= L; j ++)
      laundryWash[j] = res;

    
    l = 0; r = 1e16; res = 1e16;
    while (l <= r) {
      mid = (l + r) / 2;
      sum = 0;
      rep(i, 1, M + 1) {
        sum += mid / dryerCostTime[i];
        if (sum >= L) break;
      }
      if (sum >= L) {
        r = mid - 1;
        res = mid;
      } else {
        l = mid + 1;
      }
    }
    j = 1;
    rep(i, 1, M + 1) {
      time = dryerCostTime[i];
      if (time < res) {
        laundryDryer[j ++] = time;
        time += dryerCostTime[i];
      }
    }
    for (;j <= L; j ++)
      laundryDryer[j] = res;

    sort(laundryWash + 1, laundryWash + L + 1);
    sort(laundryDryer + 1, laundryDryer + L + 1);

    res = 0;
    rep(i, 1, L + 1) {
      res = max(res, laundryWash[i] + laundryDryer[L + 1 - i]);
    }

    printf("Case #%d: %lld\n", t, res);
  }

  return 0;
}

