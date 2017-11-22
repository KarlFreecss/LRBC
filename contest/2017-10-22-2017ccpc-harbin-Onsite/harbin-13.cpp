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

const int maxN = 100000+13;
const double eps = 1e-3;

inline int sgn ( double x) {
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}

struct point {
  double x, y;
  point(){};
  point(double x, double y) : x(x), y(y){};
  void input() {
    scanf("%lf%lf", &x, &y);
  }
};

point p[maxN];
int n;
inline double sqr(double x) {
  return x*x;
}

inline double dis(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

bool waixin(point a, point b, point c, point & ret) {
  double a1 = b.x - a.x;
  double b1 = b.y - a.y;
  double c1 = (sqr(a1) + sqr(b1)) / 2;
  double a2 = c.x - a.x;
  double b2 = c.y - a.y;
  double c2 = (sqr(a2) + sqr(b2)) / 2;
  double d = a1*b2 - a2*b1; 
  if(sgn(d) == 0) return false;
  ret.x = a.x + (c1*b2-c2*b1) / d;
  ret.y = a.y + (a1*c2-a2*c1) / d;
  return true;
}

bool check(point a, point b, point c, point& ans, double& R) {
  R = -1.0;
  if(sgn(dis(a,b)) == 0) return false;
  if(sgn(dis(c,b)) == 0) return false;
  if(sgn(dis(c,a)) == 0) return false;
  point o;
  if(waixin(a, b, c, o)) {
    int count = 0;
    double stddis = dis(o,a);
    if(sgn(stddis) == 0) return false;
    if(fabs(stddis) > 1e9) return false;
    for(int i = 0; i < n; i++) {
      if(sgn(dis(o,p[i]) - stddis) != 0) {
        count ++;
      }
      if(count > n/2) return false;
    }
    ans = o;
    R = stddis;
    return true;
  } else {
    return false;
  }
}
void work() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) p[i].input();
  if(n <= 2) {
    printf("%.5lf %.5lf %.5lf\n", p[0].x, p[0].y-1.0, 1.0);
    return ;
  }
  if(n <= 4) {
    point ans;
    ans.x = (p[0].x+p[1].x)/2.0;
    ans.y = (p[0].y+p[1].y)/2.0;
    double R = dis(p[0], p[1]) / 2.0;
    printf("%.5lf %.5lf %.5lf\n", ans.x, ans.y, R);
    return ;
  }
  while(1) {
    int r[3];
    for(int j = 0; j < 3; j++) {
      r[j] = rand() % n;
    }
    point ans; double R;
    if(check(p[r[0]], p[r[1]], p[r[2]], ans, R)) {
      printf("%.5lf %.5lf %.5lf\n", ans.x, ans.y, R);
      return ;
    }
  }
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("harbin-13.in","r",stdin);
#endif
  12 8 22 18 18 22 17 24
  19 23 9 13 13 9 14 7

  int T;
  scanf("%d", &T);
  for(int i = 0; i < T; i++) 
    work();

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

