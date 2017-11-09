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

const int maxN = 100+13;

struct Point {
  long double x, y;
  Point(){};
  Point(long double x, long double y) : x(x), y(y){};
  friend Point operator - (const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
  }
  friend long double operator * (const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
  }
};

inline long double sqr(long double x) {
  return x*x;
}
long double dist(const Point& a, const Point& b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

long double cross(const Point& o, const Point& a, const Point& b) {
  return (a-o) * (b-o);
}

struct Line {
  Point a, b;
  Line(){};
  Line(Point a, Point b) : a(a), b(b) {};
  friend long double distoLine(const Point& p, const Line& l) {
    return cross(p, l.a, l.b) / dist(l.a, l.b);
  }
};

int N;
Point p[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> p[i].x >> p[i].y;
  }
  long double ans = 1e6;
  for(int i = 1; i <= N; i++) {
    for(int j = i+1; j <= N; j++) {
      Line li = Line(p[i], p[j]);
      long double dmin = 1e6;
      long double dmax = -1e6;
      for(int k = 1; k <= N; k++) {
        long double tt = distoLine(p[k], li);
        //cout << i << ' ' << j << ' ' << k << endl;
        //cout << tt << endl;
        dmin = min(dmin, tt);
        dmax = max(dmax, tt);
      }
      long double ta = dmax - dmin;
      ans = min(ans, ta);
    }
  }
  //cout << distoLine(p[1], Line(p[2] , p[3])) << endl;
  printf("%.15Lf\n", ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

