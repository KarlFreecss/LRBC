#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back
#define fi first 
#define se second 
#define mk(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const long long MAXN = 2e5 + 100;
const long long MAX_MI = 20;

long long dp[MAXN][MAX_MI];
long long mm[MAXN];
long long a[MAXN];
long long n, q;
long long v, l, r;

void initRMQ(long long n) {
  mm[0] = -1;
  for (int i = 1; i <= n; i ++) {
    mm[i] = ((i&(i-1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
    dp[i][0] = a[i];
//    cout << i << " " << 0 << " " << dp[i][0] << endl;
  }
  for (int j = 1; j <= mm[n]; j ++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
//      cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }
}
long long rmq(long long x, long long y)
{
  long long k = mm[y - x + 1];
  return min(dp[x][k], dp[y - (1 << k) + 1][k]);
}
long long find(long long v, long long l, long long r) {
//  cout << "--------------" << endl;
//  cout << v << " " << l << " " << r << endl;
  long long mid, tmp;
  tmp = rmq(l, r);
//  cout << tmp << endl;
  if (tmp > v)
    return -1;
  while (l < r) {
    mid = (l + r) / 2;
    tmp = rmq(l, mid);
//    cout << l << " " << mid << " " << l << " " << tmp << endl;
    if (tmp <= v) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  scanf("%I64d%I64d", &n, &q);
  for (int i = 1; i <= n; i ++)
    scanf("%I64d", &a[i]);
  initRMQ(n);
  for (int i = 0; i < q; i ++) {
//    cout << "================" << endl;
    scanf("%I64d%I64d%I64d", &v, &l, &r);
    while (v > 0 && l <= r) {
      long long tmp = find(v, l, r);
//      cout << tmp << " " << v << endl;
      if (tmp == -1)
        break;
      v %= a[tmp];
      l = tmp + 1;
    }
    printf("%I64d\n", v);
  }


//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

