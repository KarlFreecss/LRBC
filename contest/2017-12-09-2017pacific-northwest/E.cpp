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

bool work() {
//  cout << "=============" << endl;
  int N, Len;
  int li, ri;
  double v, vi;
  double sum = 0.0;
  if (scanf("%d%d%lf", &N, &Len, &v) != 3) return false;
//  cout << N << " " << Len << " " << v << endl;
  for (int i = 1; i <= N; i ++) {
    scanf("%d%d%lf", &li, &ri, &vi);
//    cout << li << " " << ri << " " << vi << endl;
    sum += (ri - li) * vi;
  }
//  cout << "sum = " << sum << endl;
  double y = fabs(sum) / Len;
//  cout << y << endl;
  if (y > v - 0.000001) {
    printf("Too hard\n");
    return true;
  }
  double x = sqrt(v * v - y * y);
//  cout << x << " " << v << endl;
  if (x * 2 < v) {
    printf("Too hard\n");
  } else {
    double res = Len / x;
    printf("%.3lf\n", res);
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  while (work());

  return 0;
}

