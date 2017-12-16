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

const int maxN = 50 + 13;
const double eps = 1e-8;
const double pi = acos(-1.0);

inline int sgn(double x) {
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}
inline double sqr(double x) {
  return x*x;
}

inline double angle(double x, double y) {
  double ret = atan2(y,x);
  if(sgn(ret) < 0) ret += 2.0 * pi;
  return ret;
}

struct Point {
  double x, y;
};

struct Circle {
  Point o;
  double r;
  void read() {
    scanf("%lf%lf%lf", &o.x , &o.y, &r);
    r += eps;
  }
  void show() {
//    printf("%.3lf %.3lf %.3lf\n", o.x, o.y, r);
  }
};

Circle c[maxN];

struct Arc {
  double ag;
  int t;
  inline bool operator < (const Arc& b) const {
    return ag == b.ag ? t > b.t : ag < b.ag;
  }
};
Arc a[4 * maxN + 13];
double adjust(double x) {
  if(sgn(x) < 0) x += 2.0 * pi;
  if(sgn(x - 2.0 * pi) >= 0) x -= 2.0 * pi;
  return x;
}

struct AnsArc {
  Point o;
  double r;
  double ag1, ag2;
};

vector<AnsArc> xx;

void circleKunion(Circle c[], int n) {
  xx.clear();
  for(int i = 0; i < n; i++) {
    int m = 0, times = 0;
    for(int j = 0; j < n ; j ++) if(i != j) {
      double dist = hypot(c[i].o.x - c[j].o.x, c[i].o.y - c[j].o.y);
      if(sgn(dist + c[i].r - c[j].r) <= 0) {
        times++;
      } else if(sgn(dist + c[j].r - c[i].r) <= 0) {
        continue;
      } else if(sgn(dist - c[i].r - c[j].r) < 0) {
        double dx = (sqr(c[i].r) - sqr(c[j].r) + sqr(dist)) / 2 /dist;
        double dy = (sqrt(sqr(c[i].r)  - dx * dx));
        double temp = angle(c[j].o.x - c[i].o.x, c[j].o.y - c[i].o.y);
        a[m].ag = adjust(temp - angle(dx, dy));
        a[m++].t = 1;
        a[m].ag = adjust(temp + angle(dx, dy));
        a[m++].t = -1;
        if(sgn(a[m-1].ag - a[m-2].ag) <= 0) {
          a[m].ag = 0;
          a[m].t = 1;
          a[m+1].ag = a[m-1].ag;
          a[m+1].t = -1;
          a[m-1].ag = 2.0 * pi;
          m += 2;
        }
      }
    }
    if(m == 0) {
      if(times == n-1) {
        AnsArc tt;
        tt.o = c[i].o;
        tt.r = c[i].r;
        tt.ag1 = 0.0;
        tt.ag2 = 2.0 * pi - eps;
        xx.push_back(tt);
      }
      continue;
    }
    sort(a, a+m) ;
    a[m].ag = a[0].ag + 2.0 * pi;
    a[m++].t = 1;
    int s = times + a[0].t;
    for(int j = 1; j < m; j++) {
      int t = s; s += a[j].t;
      if(t == n-1) {
        AnsArc tt;
        tt.o = c[i].o;
        tt.r = c[i].r;
        tt.ag1 = min(a[j].ag, a[j-1].ag);
        tt.ag2 = max(a[j].ag, a[j-1].ag);
        //cout << tt.ag1 << ' ' << tt.ag2 << endl;
        xx.push_back(tt);
      }
    }
  }
  return ;
}

int N;
int work() {
  double ans = 0.0;
  if(scanf("%d", &N) != 1) return 0;
  //cout << N << endl;
  for(int i = 0; i < N; i++) {
    c[i].read();
    c[i].show();
  }
  if(N == 1) {
    double ans = hypot(c[0].o.x, c[0].o.y);
    ans += c[0].r;
    printf("%.3lf\n", ans);
    return 1;
  }
  circleKunion(c, N);
  for(auto ta : xx) {
    double l = ta.ag1, r = ta.ag2;
    //cout << "start " << endl;
    //cout << l << ' ' << r << endl;
    for(int i = 1; i <= 50; i++) {
      double tt = (r - l) / 3.0;
      double mid1, mid2;
      mid1 = l + tt;
      mid2 = mid1 + tt;
      double dis1 = hypot(ta.o.x + ta.r*cos(mid1), ta.o.y + ta.r*sin(mid1));
      double dis2 = hypot(ta.o.x + ta.r*cos(mid2), ta.o.y + ta.r*sin(mid2));
      if(dis1 < dis2) {
        l = mid1;
      } else {
        r = mid2;
      }
    }
    double tans = hypot(ta.o.x + ta.r*cos(l), ta.o.y + ta.r*sin(l));
    if(tans > ans) {
      ans = tans;
    }
  }
  printf("%.3lf\n", ans);
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

