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

const int MAXN = 1e6 + 100;

long long f[MAXN];
long long n, a, b;

long long num[100];

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif

  scanf("%I64d%I64d%I64d", &n, &a, &b);
  long long res = 1e18;
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i < 25; i ++) {
    for (int j = 0; j < i; j ++)
      num[j] = 1;
    long long count = 1;
    for (int j = 1; j <= n; j ++) {
      long long tmp = (j - 1) % i;
      count /= num[tmp];
      num[tmp] ++;
      count *= num[tmp];
      if (count >= n) {
        long long tmpRes = a * i + b * j;
        res = min(res, tmpRes);
        break;
      }
    }
  }
  printf("%I64d\n", res);

  return 0;
}

