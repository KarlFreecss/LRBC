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

const int MAXN = 3e5 + 100;

class center {
  public:
    long long a, b;
    center(long long iA = 0, long long iB = 0) {
      a = iA;
      b = iB;
    }
};
class pathway {
  public:
    long long a, b, c;
    pathway(long long iA = 0, long long iB = 0, long long iC = 0) {
      a = iA;
      b = iB;
      c = iC;
    }
};
bool cmp(pathway a, pathway b) {
  return a.c < b.c;
}

center c[MAXN];
pathway p[MAXN];
long long fa[MAXN], maxPeople[MAXN], minCost[MAXN], minAllCost[MAXN];
long long n, m;

int getFa(int x) {
  if (fa[x] == x)
    return x;
  fa[x] = getFa(fa[x]);
  return fa[x];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  long long res = 0, finalRes;
  scanf("%I64d%I64d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    scanf("%I64d%I64d", &c[i].a, &c[i].b);
    fa[i] = i;
    maxPeople[i] = c[i].a;
    minCost[i] = c[i].b;
    minAllCost[i] = c[i].a * c[i].b;
    res += c[i].a * c[i].b;
  }
  finalRes = res;
  for (int i = 0; i < m; i ++) {
    scanf("%I64d%I64d%I64d", &p[i].a, &p[i].b, &p[i].c);
  }
  sort(p, p + m, cmp);
  for (int i = 0; i < m; i ++) {
//    cout << "=============" << endl;
//    cout << res << endl;
//    cout << p[i].a << " " << p[i].b << " " << p[i].c << endl;
    int x = getFa(p[i].a);
    int y = getFa(p[i].b);
    if (x != y) {
      res -= minAllCost[x];
      res -= minAllCost[y];
      fa[y] = x;
      minAllCost[x] += minAllCost[y];
      maxPeople[x] = max(maxPeople[x], maxPeople[y]);
      maxPeople[x] = max(maxPeople[x], p[i].c);
      minCost[x] = min(minCost[x], minCost[y]);
      minAllCost[x] = min(minAllCost[x], maxPeople[x] * minCost[x]);
      res += minAllCost[x];
      finalRes = min(res, finalRes);
    }
  }
//  cout << res << endl;
  printf("%I64d\n", finalRes);

  return 0;
}

