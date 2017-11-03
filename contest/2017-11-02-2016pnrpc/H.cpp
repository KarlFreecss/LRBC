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

const int MAXK = 2e5 + 100;

class painter {
  public:
  long long a, b;
  painter(long long iA = 0, long long iB = 0) {
    a = iA;
    b = iB;
  }
};
painter p[MAXK];
long long f[MAXK];
long long n, k;

bool cmp(painter a, painter b) {
  return a.b < b.b;
}
long long find(long long x) {
  long long l = 0, r = x - 1, mid;
  long long val = p[x].a, res = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (p[mid].b < val) {
      res = max(res, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return res;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  scanf("%I64d%I64d", &n, &k);
  p[0] = painter(0, 0);
  for (int i = 1; i < k + 1; i ++) {
    scanf("%I64d%I64d", &p[i].a, &p[i].b);
  }
  sort(p, p + k + 1, cmp);
  f[0] = 0;
  for (int i = 1; i < k + 1; i ++) {
    f[i] = f[i - 1] + (p[i].b - p[i - 1].b);
    long long j = find(i);
    f[i] = min(f[i], f[j] + (p[i].a - p[j].b - 1));
  }
  printf("%I64d\n", f[k] + (n - p[k].b));

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

