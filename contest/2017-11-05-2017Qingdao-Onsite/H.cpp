#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;


using namespace std;

const int MAXN = 100 + 5;
const double eps = 1e-6;
const double pi = acos(-1.0);

inline int cmp(double a) {
  return a < -eps ? -1 : a > eps;
}

inline double sqr(double a) {
  return a*a;
}

inline double isqrt(double a) {
  return a<=0 ? 0 : sqrt(a);
}
struct Point3 {
  double x, y, z;
  Point3(){};
  Point3(double x, double y, double z) : x(x), y(y), z(z){};
  double Length() {
    return isqrt(sqr(x) + sqr(y) + sqr(z));
  }
  Point3 operator - (const Point3 & a) {
    return Point3(x-a.x , y - a.y, z - a.z);
  }
  Point3 operator + (const Point3 & a) {
    return Point3(x+a.x , y + a.y, z + a.z);
  }
  Point3 operator * (const double& a) {
    return Point3(x*a , y*a, z*a);
  }
  void out() {
    printf("%lf %lf %lf\n", x, y, z);
  }
};
Point3 Det(const Point3& a, const Point3& b) {
  return Point3(a.y*b.z - a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

double ryz, rxz,rxy;
Point3 rotate(Point3 a, Point3 b, double alpha) {
  Point3 ret;
  return ret;
}

double getDis(Point3 p1, Point3 p2, Point3 o) {
  Point3 a = p2 - p1;
  double l = 0, r = 1.0;
  double ret = (p1-o).Length();
  for(int i = 1; i <= 20; i++) {
    double mid1 = (l+r) / 3.0;
    double mid2 = 2.0 * (l+r) / 3.0;
    Point3 tt1 = p1 + a*mid1 - o;
    Point3 tt2 = p1 + a*mid2 - o;
    if(tt1.Length() < tt2.Length()) {
      r = mid2;
    } else {
      l = mid1;
    }
  }
  ret = (a*l+p1-o).Length();
  return ret;
}

void work(){
  Point3 st; st.read();
  Point3 o; o.read();
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    double d, al; char s[3];
    scanf("%lf%s%lf", &d, s, &al);
    Point3 ed;
    double big = 
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }
  /*
  Point3 x(0,0,1);
  x = rotate(x, pi/2.0);
  x.out();
  x = rotate(x, pi/2.0);
  x.out();
  x = rotate(x, pi/2.0);
  x.out();
  x = rotate(x, pi/2.0);
  x.out();
  */
  return 0;
}
