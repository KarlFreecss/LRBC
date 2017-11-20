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

const int maxN = 2500+13;
const double pi = acos(-1.0);
const double eps = 1e-8;

inline int sgn(double x) {
  return x < -eps ? -1 : x > eps;
}
inline double sqr(double x) {
  return x*x;
}

struct P {
  double x, y;
  P(){};
  P(double x, double y) : x(x), y(y){};
  void read() {
    scanf("%lf%lf", &x, &y);
  }
  double len() {
    return hypot(x, y);
  }
  P operator - (const P& a) {
    return P(x-a.x, y-a.y);
  }
};

double cross(const P& a, const P& b, const P& c) {
  return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
double dot(const P& a, const P& b) {
  return a.x * b.x + a.y * b.y ;
}
double dot2(const P& a, const P& b, const P& c) {
  return (a.x - c.x) * (b.x - c.x) + (a.y - c.y) * (b.y - c.y);
}
double dis(const P& a, const P& b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double det(const P& a, const P& b) {
  return a.x * b.y - a.y * b.x;
}

double Asin(double x) {
  if(sgn(x - 1) >= 0) {
    return asin(1.0);
  } else if(sgn(x+1) <= 0) {
    return asin(-1.0);
  } else {
    return asin(x);
  }
}
double Acos(double x){
  if(sgn(x - 1) >= 0) {
    return acos(1.0);
  } else if(sgn(x+1) <= 0) {
    return acos(-1.0);
  } else {
    return acos(x);
  }
}
double areaCT(P pa, P pb, double r) {
  double S = 0, h;
  if(pa.len() < pb.len()) 
    swap(pa, pb);
  if(sgn(pb.len()) == 0) return 0;
  double a = pb.len(), b = pa.len(), c = (pb-pa).len();
  double sinB = fabs(det(pb, pb - pa) / a / c),
         cosB = dot(pb, pb - pa) / a / c,
         sinC = fabs(det(pa, pb) / a / b),
         cosC = dot(pa, pb) / a / b;
  double B = atan2(sinB, cosB), C = atan2(sinC, cosC);
  if(a > r) {
    S = C / 2.0 * r * r;
    h = a * b * sinC / c;
    if( h < r && B < pi / 2.0) {
      S -= (acos(h/r) * r * r - h *sqrt(r*r-h*h));
    }
  } else if(b > r) {
    double theta = pi - B - asin(sinB / r * a);
    S = a * r *sin(theta) / 2.0 + (C - theta) / 2.0 * r * r;
  } else {
    S = sinC * a * b / 2.0;
  }
  return S ;
}
double calcarea(const P& a, const P& b, const P& c, double r) {
  if( fabs(cross(a, b, c) < 1e-8)) return 0.0;
  double A, B, C, x, y, ts;
  A = dis(b,c); B = dis(a, c); C = dis(a,b);
  if(sgn(A - r) < 0 && sgn(B - r) < 0) {
    return cross(a, b, c) / 2.0;
  } else if(sgn(A - r) < 0 && sgn(B - r) >= 0) {
    x = (dot2(a,c,b) + sqrt(fabs(sqr(r)*sqr(C) - sqr(cross(a,c,b))))) / C;
    ts = cross(a,b,c) / 2.0;
    return Asin(ts * (1.0 - x / C) * 2.0 / r / B) * sqr(r) / 2.0 + ts * x /C;
  } else if(sgn(A-r) >= 0 && sgn(B - r) < 0) {
    y = (dot2(b,c,a) + sqrt(fabs(sqr(r)*sqr(C) - sqr(cross(b,c,a))))) / C;
    ts = cross(a,b,c) / 2.0;
    return Asin(ts * (1.0 - y / C) * 2.0 / r / A) * sqr(r) / 2.0 + ts * y /C;
  } else if(sgn(fabs(cross(a,b,c)) - r * C) >= 0 || sgn(dot2(b,c,a)) <= 0 || sgn(dot2(a,c,b)) <= 0) {
    if(sgn(dot2(a,b,c)) < 0) {
      if(sgn(cross(a,b,c)) < 0) {
        return (-Acos(-1.0) - Asin(cross(a,b,c) / A / B)) * sqr(r) / 2.0;
      } else {
        return (Acos(-1.0) - Asin(cross(a,b,c) / A / B)) * sqr(r) / 2.0;
      }
    } else {
      return Asin(cross(a,b,c) / A / B) * sqr(r) / 2.0;
    }
  } else {
    x = (dot2(a,c,b) + sqrt(fabs(sqr(r) * sqr(C) - cross(a,c,b)*cross(a,c,b)))) / C;
    y = (dot2(b,c,a) + sqrt(fabs(sqr(r) * sqr(C) - cross(b,c,a)*cross(b,c,a)))) / C;
    ts = cross(a, b, c) / 2.0;
    return (Asin(ts * (1.0 - x / C) * 2 / r / B) + Asin(ts * (1.0 - y / C) * 2 / r / A)) * r * r / 2.0 + ts * ((y+x) / C - 1.0);
  }
}

P p[maxN], o;
int N;
double k;

int work(int cas) {
  if(scanf("%d %lf", &N, &k) != 2) return 0;
  for(int i = 0; i < N; i++) 
    p[i].read();
  double xa, ya, xb, yb;
  scanf("%lf %lf", &xa, &ya);
  scanf("%lf %lf", &xb, &yb);
  if(N < 3) {
    printf("0.0\n");
    return 1;
  }
  o.x = (xb - k*k*xa) / (1.0 - k*k);
  o.y = (yb - k*k*ya) / (1.0 - k*k);
  double r = (sqr(k*xa) + sqr(k*ya) - sqr(xb) - sqr(yb)) / (1.0 - k*k);
  r += sqr(o.x) + sqr(o.y);
  r = sqrt(r);
  for(int i = 0; i < N; i++) {
    p[i] = p[i] - o;
  }
  double ans = 0.0;
  for(int i = 0; i < N; i++) {
    int ss = sgn(det(p[i], p[(i+1) % N]));
    ans += (double) ss * areaCT(p[i], p[(i+1) % N], r);
  }
  //printf("%.12lf\n", ans);
  printf("Case %d: %.12lf\n", cas, fabs(ans));
  return 1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  int cas = 1;
  while(work(cas)) {
    cas++;
  };
  return 0;

  o.x = o.y = 0;
  double r , total;
  scanf("%lf", &r);
  for(int i = 0; i < 4; i++) {
    p[i].read();
  }
  for(int i = 0; i < 4; i++) {
  //  cout << p[i].x << ' ' << p[i].y << endl;
  //  cout << p[i+1].x << ' ' << p[i+1].y << endl;
    int ss = sgn(det(p[i], p[(i+1) % 4]));
    total += (double) ss * areaCT(p[i], p[(i+1) % 4], r);
   // total2 += (double) calcarea(p[i], p[(i+1) % 4],o, r);
  }
  cout << total << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

