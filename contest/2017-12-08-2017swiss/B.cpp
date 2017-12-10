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

struct Point {
  double x, y;
  Point(){};
  Point(double x, double y):x(x), y(y){};
  friend Point operator + (const Point& a, const Point& b) {
    return Point(a.x + b.x , a.y + b.y);
  }
  friend Point operator - (const Point& a, const Point& b) {
    return Point(a.x - b.x , a.y - b.y);
  }
  friend Point operator * (const Point& a, double b) {
    return Point(a.x * b, a.y * b);
  }
  double det(const Point& b) {
    return x*b.y - y*b.x;
  }
  double dis() {
    return hypot(x, y);
  }
  void read() {
    scanf("%lf%lf", &x, &y);
  }
  void show() {
    cout << x << ' ' << y << endl;
  }
};

double area(Point p1, Point p2, Point p3) {
  Point a, b;
  a = p3 - p1;
  b = p2 - p1;
  return fabs(a.det(b));
}

void deal(Point a[], Point st, Point ed) {
  double dis = (ed - st).dis();
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    double tt;
    scanf("%lf", &tt);
    if(i == 1) a[1] = st + (ed - st) * (tt / dis);
    if(i == n) a[2] = st + (ed - st) * (tt / dis);
  }
  //a[1].show();
  //a[2].show();
  return ;
}

double check(Point a[], Point b[]) {
  double ret = 0.0;
  ret = max(ret, area(a[1],b[1],b[2]));
  ret = max(ret, area(a[2],b[1],b[2]));
  ret = max(ret, area(b[1],a[1],a[2]));
  ret = max(ret, area(b[2],a[1],a[2]));
  return ret;
}

Point a[13], b[13], c[13];
Point p[13];

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  for(int i = 1; i <= 3; i++) {
    p[i].read();
  }
  p[4] = p[1];
  deal(a,p[1],p[2]); 
  deal(b,p[2],p[3]); 
  deal(c,p[3],p[4]); 
  double ans = 0.0;
  for(int i = 1; i <= 2; i++) {
  //  a[i].show(); b[i].show(); c[i].show();
    ans = max(ans, area(a[i], b[i], c[i]));
  }
  //cout << ans << endl;
  ans = max(ans, check(a, b));
  ans = max(ans, check(a, c));
  ans = max(ans, check(c, b));
  
  printf("%.10lf\n", ans/2.0);

  return 0;
}

