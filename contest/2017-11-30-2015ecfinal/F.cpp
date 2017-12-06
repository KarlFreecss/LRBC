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

const long long MM = 1e9 + 7;
const int MAXN = 1e6 + 100;

long long f[MAXN], sum[MAXN];
long long N, K;

bool ifOK(long long i, long long j) {
  return (j * (j - 1) / 2) < ((i + j) * (i - j + 1) / 2);
}
long long fastPow(long long val, long long mi) {
  long long res = 1;
  while (mi > 0) {
    if ((mi & 1)) {
      res *= val;
      res %= MM;
    }
    val *= val;
    val %= MM;
    mi >>= 1;
  }
  return res;
}
void work() {
  scanf("%lld%lld", &N, &K);
  if (K == 1) {
    printf("0\n");
    return;
  }
  for (int i = 0; i < K; i ++)
    sum[i] = f[i] = 0;
  long long j = 2, i = K;
  while (ifOK(i, j) && j <= i)
    j ++;
  j --;
  sum[K] = f[K] = fastPow(2, j - 1);
  for (long long i = K + 1; i <= N; i ++) {
    while (ifOK(i, j) && j < i)
      j ++;
//    cout << j << " " << i << endl;
    f[i] = sum[i - 1] - sum[j - 2];
    f[i] += MM;
    f[i] %= MM;
    sum[i] = sum[i - 1] + f[i];
    sum[i] %= MM;
  }
  long long res = f[N] * 2;
  res %= MM;
  printf("%lld\n", res);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t ++) {
    printf("Case #%d: ", t);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

