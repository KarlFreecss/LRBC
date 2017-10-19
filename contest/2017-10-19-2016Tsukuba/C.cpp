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

const int MAXN = 2e5 + 100;

class point {
  public:
    int x, y;
    point(int iX = 0, int iY = 0) {
      x = iX;
      y = iY;
    }
};
bool cmp(point a, point b) {
  return a.x < b.x;
}

point query[MAXN], res[MAXN];
int n, m;

point combine(point a, point b) {
  return point(min(a.x, b.x), max(a.y, b.y));
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("C.in","r",stdin);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    res[i] = point(i, i);
  }
  for (int i = 1; i <= m; i ++) {
    scanf("%d%d", &query[i].x, &query[i].y);
  }
  sort(query + 1, query + m + 1, cmp);
  for (int i = 1; i <= m; i ++) {
    int y = query[i].y;
//    cout << y << endl;
    point tmp = combine(res[y], res[y + 1]);
    res[y] = tmp;
    res[y + 1] = tmp;
  }
  for (int i = 1; i <= n; i ++) {
    if (i != 1)
      printf(" ");
    printf("%d", res[i].y - res[i].x + 1);
  }
  printf("\n");
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

