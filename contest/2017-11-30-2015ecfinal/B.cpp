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

const int MAXN = 1e5 + 100;

long long v[MAXN], sum[MAXN], maxSum[MAXN];
long long N, G, P;

void work() {
  scanf("%lld%lld%lld", &N, &G, &P);
  long long x = P % N;
  long long y = P / N;
  sum[0] = 0;
  maxSum[0] = 0;
  for (int i = 1; i <= N; i ++) {
    scanf("%lld", &v[i]);
    sum[i] = sum[i - 1] + v[i];
    maxSum[i] = max(maxSum[i - 1], sum[i]);
  }

  long long tmp = 0;
  long long j = P;
  for (int i = 1; i <= N && j > 0; i ++, j --) {
    tmp += v[i];
    tmp = max(tmp, 0ll);
    if (tmp >= G) {
      printf("0\n");
      return;
    }
  }
  long long z = j / N - 1;
//  cout << j << endl;
  if (sum[N] > 0 && z > 0) {
    if (G / sum[N] < z) {
      printf("0\n");
      return;
    }
    tmp += z * sum[N];
    if (tmp >= G) {
      printf("0\n");
      return;
    }
    j -= z * N;
  }
  for (int i = 1; i <= N && j > 0; i ++, j --) {
    tmp += v[i];
    tmp = max(tmp, 0ll);
    if (tmp >= G) {
      printf("0\n");
      return;
    }
  }
  for (int i = 1; i <= N && j > 0; i ++, j --) {
    tmp += v[i];
    tmp = max(tmp, 0ll);
    if (tmp >= G) {
      printf("0\n");
      return;
    }
  }


  long long res = G;
//  cout << "sumN = " << sum[N] << endl;
  if (y == 0) {
    res = min(res, G - maxSum[x]);
  } else {
    if (sum[N] <= 0) {
      res = min(res, G - maxSum[N]);
    } else {
      long long tmp = G;
      if (tmp / sum[N] < y) {
        printf("0\n");
        return;
      }
      tmp -= y * sum[N];
      tmp -= maxSum[x];
      res = min(res, tmp);

      tmp = G;
      if (tmp / sum[N] < y - 1) {
        printf("0\n");
        return;
      }
      tmp -= (y - 1) * sum[N];
      tmp -= maxSum[N];
      res = min(res, tmp);
    }
  }
  res = max(res, 0ll);
  printf("%lld\n", res);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
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

