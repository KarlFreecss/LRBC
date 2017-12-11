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

const int maxN = 40 + 13;
const double eps = 1e-6;
inline int sgn(double x) {
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}

struct Point {
  double x, y;
  Point(){};
  Point(double x, double y) :x(x), y(y){};
  friend Point operator + (const Point& a, const Point& b) {
    return Point(a.x + b.x , a.y + b.y);
  }
  friend Point operator - (const Point& a, const Point& b) {
    return Point(a.x - b.x , a.y - b.y);
  }
  friend Point operator / (const Point& a, const double& b) {
    return Point(a.x / b , a.y / b);
  }
  friend Point operator * (const Point& a, const double& b) {
    return Point(a.x * b , a.y * b);
  }
  double len2() {
    return x*x+y*y;
  }
  double det(const Point b) {
    return x*b.y-y*b.x;
  }
  void read() {
    scanf("%lf%lf", &x, &y);
  }
  Point rot90() {
    return Point(-y, x);
  }
};

struct Line{
  Point a,b;
};

Line make_line(Point a, Point b) {
  Line ret;
  ret.a = (a+b)/2;
  ret.b = ret.a + (a-b).rot90();
  return ret;
}

int N;
Point p[maxN];

Point isLL(const Line &l1, const Line &l2) {
  double s1 = (l2.b - l2.a).det(l1.a - l2.a),
         s2 = -(l2.b - l2.a).det(l1.b - l2.a);
  if(sgn(s1+s2) == 0) return p[1];
  return (l1.a * s2 + l1.b * s1) / (s1 + s2);
}

int calc(Point o) {
  int ret = 0;
  vector<double> xx;
  xx.push_back(-1.0);
  for(int i = 1; i <= N; i++) 
    xx.push_back((p[i]-o).len2());
  sort(all(xx));
  for(int i = 1; i <= N; i++) {
    if(sgn(xx[i] - xx[i-1]) != 0) ret++;
  }
  return ret;
}

bool work() {
  if(scanf("%d",&N) != 1) return 0;
  for(int i = 1; i <= N; i++) 
    p[i].read();
  int ans = N;
  for(int i = 1; i <= N; i++) {
    ans = min(calc(p[i]), ans);
    for(int j = i + 1; j <= N; j++) {
      ans = min(calc((p[i]+p[j])/2.0), ans);
    }
  }
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      Line l1 = make_line(p[i], p[j]);
      for(int i2 = 1; i2 <= N; i2++) {
        for(int j2 = i2+1; j2 <= N; j2++) {
          Line l2 = make_line(p[i2], p[j2]);
          Point tp = isLL(l1, l2);
          ans = min(ans, calc(tp));
        }
      }
    }
  }
  printf("%d\n", ans);
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

