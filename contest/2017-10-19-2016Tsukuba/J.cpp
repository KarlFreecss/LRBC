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

const int maxN = 13;
const double Pi = acos(-1.0);
const double eps = 1e-8;

inline double sqr(double x) {
  return x*x;
}

struct point {
  double x,y;
  point(){};
  point(double x, double y) : x(x), y(y){};
  void input() {
    scanf("%lf%lf", &x, &y);
    //output();
  }
  void output() {
    printf("x = %.4lf  y = %.4lf\n", x, y);
  }
  friend point operator + (const point& a,const point& b) {
    return point(a.x+b.x, a.y+b.y);
  }
  friend point operator - (const point& a,const point& b) {
    return point(a.x-b.x, a.y-b.y);
  }
  friend point operator * (const point& a,const double& b) {
    return point(a.x*b, a.y*b);
  }
  friend point operator / (const point& a,const double& b) {
    return point(a.x/b, a.y/b);
  }
};

inline int dcmp(double x) {
  return x < -eps ? -1 : x > eps ? 1 : 0;
}

double dot(const point& a, const point& b) {
  return a.x*b.x + a.y*b.y;
}
double det(const point& a, const point& b) {
  return a.x * b.y - a.y * b.x;
}
double cross(const point& a, const point& b) {
  return a.x * b.y - a.y * b.x; 
}

double abs(const point& x) {
  return sqrt(dot(x,x));
}

point crosspt(const point& a, const point& b, const point& p, const point& q) {
  double a1 = cross(b-a, p-a);
  double a2 = cross(b-a, q-a);
  return (p * a2 - q*a1) / (a2 - a1);
}

point res[maxN];
double r;
int n;


void circle_cross_line(point a, point b, point o, double r, point ret[],int &num) {
  double x0 = o.x , y0 = o.y;
  double x1 = a.x , y1 = a.y;
  double x2 = b.x , y2 = b.y;
  double dx = x2 - x1, dy = y2 - y1;
  double A = sqr(dx) + sqr(dy);
  double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
  double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
  double delta = sqr(B) - 4.0 * A * C;
  num = 0;
  if(dcmp(delta) >= 0) {
    double t1 = (-B - sqrt(delta)) / (2.0 * A);
    double t2 = (-B + sqrt(delta)) / (2.0 * A);
    if( dcmp(t1 - 1) <= 0 && dcmp(t2) >= 0) {
      ret[num++] = point(x1 + t1*dx, y1 + t1*dy);
    }
    if( dcmp(t2 - 1) <= 0 && dcmp(t2) >= 0) {
      ret[num++] = point(x1 + t2*dx, y1 + t2*dy);
    }
  }
  return ;
}

double sector_area(const point& a, const point& b) {
  double theta = atan2(a.y, a.x) - atan2(b.y, b.x);
  while(theta <= 0) theta += Pi * 2.0;
  while(theta > 2.0*Pi) theta -= Pi * 2.0;
  theta = min(theta, Pi * 2.0 - theta);
  return r * r * theta/2.0;
}

double calc_area_for2(const point& a, const point& b) {
  point p[2];
  int num = 0;
  int ina = dcmp(abs(a) - r) < 0;
  int inb = dcmp(abs(b) - r) < 0;
  if(ina) {
    if(inb) {
      return fabs(cross(a,b)) / 2.0;
    } else {
      circle_cross_line(a,b,point(0,0),r,p,num);
      return sector_area(b,p[0]) + fabs(cross(a,p[0])) / 2.0;
    } 
  } else {
    if(inb) {
      circle_cross_line(a,b,point(0,0),r,p,num);
      return sector_area(p[0],a) + fabs(cross(p[0],b)) / 2.0;
    } else {
      circle_cross_line(a,b,point(0,0),r,p,num);
      if(num == 2) {
        return sector_area(a,p[0]) + sector_area(p[1],b) + fabs(cross(p[0], p[1])) / 2.0;
      } else {
        //return 0;
        return sector_area(a,b);
      }
    }
  }
}
double calc_area(const point& o) {
  double ret = 0;
  rep(i, 0, n+1) res[i] = res[i] - o;
  //rep(i,0,n+1) res[i].output();
  for(int i = 0; i < n; i++) {
    int sgn = dcmp(cross(res[i], res[i+1]));
    if(sgn != 0) {
      double tt = calc_area_for2(res[i], res[i+1]);
      //cout << tt << endl;
      ret += sgn * tt;
    }
  }
  rep(i, 0, n+1) res[i] = res[i] + o;
  return ret;
}

const double dx[8] = {-1,-1,-1,0,0,1,1,1};
const double dy[8] = {-1,0,1,-1,1,-1,0,1};

bool PointOnSeg(const point p, const point s, const point t) {
  return dcmp(det(p-s, t-s)) == 0 && dcmp(dot(p-s,p-t)) <= 0;
}

int inconvex(const point x) {
  int num = 0;
  for(int i = 0; i < n; i++) {
    if(PointOnSeg(x, res[i], res[i+1])) return 2;
    int k = dcmp(det(res[i+1]-res[i], x-res[i]));
    int d1 = dcmp(res[i].y - x.y);
    int d2 = dcmp(res[i+1].y - x.y);
    if(k > 0 && d1 <= 0 && d2 > 0) num++;
    if(k < 0 && d2 <= 0 && d1 > 0) num--;
  }
  return num!=0;
}

double calc() {
  double sx, sy;
  rep(i, 0, n) {
    sx += res[i].x;
    sy += res[i].y;
  }
  //cout << sx << ' ' << sy << endl;
  sx /= n; sy /= n;
  cout << sx << ' ' << sy << endl;
  double ret = calc_area(point(sx, sy));
  cout << ret << endl;
  double ans = ret;
  double step = 50;
  double rr = 0.993;
  int ind = 0;
  //ind = 100000000;
  while(ind < 100000) {
    ind ++;
    rep(i, 0, 8) {
      double tx,ty;
      tx = sx + dx[i] * step;
      ty = sy + dy[i] * step;
      if(inconvex(point(tx,ty)) != 1) continue;
      double ta = calc_area(point(tx,ty));
      if(ta > ans) {
        if(ta > ret) ret = ta;
        ans = ta;
        sx = tx; sy = ty;
        cout << ans << endl;
        cout << sx << ' ' << sy << endl;
      } else {
        int tt = rand() % 1000;
        if(tt < 93) {
          ans = ta;
          sx = tx; sy = ty;
        }
      }
    }
    step *= rr;
    //cout << ind << ' ' << step << endl;
  }
  //cout << sx << ' ' << sy << endl;
  //cout << calc_area(point(sx,sy)) << endl;
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  srand(time(0));
  scanf("%d%lf", &n, &r);
  rep(i, 0, n) res[i].input();
  res[n] = res[0];
  printf("%.10lf\n", calc());
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
  point p1(10,3), p2(-10,3);
  r = 5;
  point ans[10]; int num;
  circle_cross_line(p1,p2,point(0,0),r,ans,num);
  cout << num << endl;
  rep(i,0,num) ans[i].output();

  return 0;
}

