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

const int MAXN = 1e5 + 13;
const long long MM = 1e9 + 7;

long long F[MAXN], G[MAXN];
long long a[4];
long long N;

long long C2(long long x) {
  long long res = x * (x - 1) / 2;
  res %= MM;
  return res;
}
long long C3(long long x) {
  long long res;
  a[1] = x; a[2] = x - 1; a[3] = x - 2;
  for (int i = 2; i <= 3; i ++) {
    for (int j = 1; j <= 3; j ++) {
      if (a[j] % i == 0) {
        a[j] /= i;
        break;
      }
    }
  }
  res = a[1] * a[2];
  res %= MM;
  res = res * a[3];
  res %= MM;
  return res;
}

void pre() {
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < MAXN; i ++) {
    F[i] = C2(F[i - 1] + 1) + F[i - 1] + 1;
    F[i] %= MM;
  }
  for (int i = 1; i < MAXN; i ++) {
    G[i] = F[i] - F[i - 1];
    if (G[i] < 0)
      G[i] += MM;
  }
}
void work(long long N) {
  if (N == 1) {
    printf("1\n");
    return;
  }
  long long res = 0;
  if ((N & 1) == 0) {
    N /= 2;
    res = C2(G[N]) + G[N];
    res %= MM;
  } else {
    N /= 2;
    res = C2(G[N]) + G[N];
    res %= MM;
    res = res * (F[N - 1] + 1);
    res %= MM;
    long long tmp = G[N] * (G[N] - 1);
    tmp %= MM;
    res += G[N] + tmp + C3(G[N]);
    res %= MM;
  }
  res %= MM;
  printf("%lld\n", res);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  pre();
  while (scanf("%lld\n", &N)) {
    if (N == 0)
      break;
    work(N);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

