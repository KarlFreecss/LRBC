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

long long fastPow(long long val, long long mi) {
  long long res = 1;
  while (mi > 0) {
    if ((mi & 1) == 1) {
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
  long long res;
  long long N, M, K;
  scanf("%I64d%I64d%I64d", &N, &M, &K);
  res = fastPow(K, N * M);
  long long tmp = 0;
  for (int i = 2; i <= K; i ++) {
    tmp += fastPow(i - 1, (N + M - 2));
    tmp %= MM;
  }
  tmp *= (N * M);
  tmp %= MM;
  tmp *= fastPow(K, (N - 1) * (M - 1));
  tmp %= MM;
  res += tmp;
  res %= MM;
  printf("%I64d\n", res);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
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

