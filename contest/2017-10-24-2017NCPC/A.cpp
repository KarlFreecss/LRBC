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

const int MAXN = 5e5 + 100;

long long d[MAXN], f[MAXN], res[MAXN];
long long l, a, b, t, r, n, coffee_dis;

long long max(long long a, long long b) {
  if (a < b)
    return b;
  else
    return a;
}

long long trans(int x, int y) {
  long long res = max(0, d[y] - d[x] - a * t);
  res = min(res, b * r);
  res = res + f[x];
  return res;
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("A.in","r",stdin);
#endif
  scanf("%I64d%I64d%I64d%I64d%I64d", &l, &a, &b, &t, &r);
  coffee_dis = a * t + b * r;
  scanf("%I64d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%I64d", &d[i]);
    f[i] = 0;
  }
  d[n] = l;
  f[n] = 0;
  f[0] = 0;
  int j = 0;
  for (int i = 1; i <= n; i ++) {
    while ((d[i] - d[j]) > coffee_dis)
      j ++;
    f[i] = trans(j, i);
    res[i] = j;
    if (j != 0) {
      long long tmp = trans(j - 1, i);
      if (tmp > f[i]) {
        f[i] = tmp;
        res[i] = j - 1;
      }
    }
  }
  vector<long long> v;
  long long i = n, resN = 0;
  while (i > 0) {
    i = res[i];
    v.push_back(i);
    resN ++;
  }
  printf("%I64d\n", resN);
  for (int i = v.size() - 1; i >= 0; i --) {
    printf("%I64d", v[i]);
    if (i == 0)
      printf("\n");
    else
      printf(" ");
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

