#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-6;

struct Point{
  double x,y;
  Point(){};
  Point(double x,double y): x(x),y(y){};
  Point operator - (const Point& b) {
    return Point(x-b.x,y-b.y);
  }
  Point operator + (const Point& b) {
    return Point(x+b.x,y+b.y);
  }
  Point operator * (const double& b) {
    return Point(x*b,y*b);
  }
  Point operator / (const double& b) {
    return Point(x/b,y/b);
  }
  double operator * (const Point& b) {
    return x*b.y - y*b.x;
  }
  double operator % (const Point& b) {
    return x*b.x + y*b.y;
  }
  double len() {
    return sqrt(x*x + y*y);
  }
  double len2() {
    return x*x + y*y;
  }
};

typedef vector<Point> vP;

inline int sgn(double x) {
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}

vP getCL(Point c, double r, Point p1, Point p2) {
  vP ret; ret.clear();
  double x = (p1 - c) % (p2 - p1);
  double y = (p2 - p1).len2();
  double d = x*x - y*((p1 - c).len2() - r*r);
  //cout << "x = " << x << endl;
  //cout << "y = " << y << endl;
  //cout << "d = " << d << endl;
  if(d < -eps) return ret;
  //cout << "Wocao!!!!!!!!!!" << endl;
  if(d < 0) d = 0.0;
  Point q1 = p1 - ((p2-p1) * (x/y));
  Point q2 = (p2 - p1) * (sqrt(d) / y);
  ret.pb(q1-q2);
  ret.pb(q2+q1);
  return ret;
}

vP getX(Point c, double r, Point p1, Point p2) {
  //cout << "c = (" << c.x << ',' << c.y << ")" <<endl;
  //cout << "p1 = (" << p1.x << ',' << p1.y << ")" <<endl;
  //cout << "p2 = (" << p2.x << ',' << p2.y << ")" <<endl;

  vP ret; ret.clear();
  vP ta = getCL(c,r,p1,p2);
  //cout << "sizeof(ta) = " << siz(ta) << endl;

  if(siz(ta) == 0) return ret;
  //cout << "ta[0] = (" << ta[0].x << ',' << ta[0].y << ")" <<endl;
  //cout << "ta[1] = (" << ta[1].x << ',' << ta[1].y << ")" <<endl;
  double tt = 1e9; int id = -1;
  rep(i,0,2) {
    double td = (ta[i] - p1).len();
    if(td < tt) {
      tt = td;
      id = i;
    }
  }
  ret.pb(ta[id]);
  return ret;
}

double degs(Point a, Point b) {
  double tt = a*b;
  tt /= a.len()*b.len();
  return tt;
}
double degc(Point a, Point b) {
  double tt = a%b;
  tt /= a.len()*b.len();
  return tt;
}

double ox,oy,r,ax,ay,vx,vy;
double bx,by;
Point O,A,B;

int main() {
  int T;
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    printf("Case #%d: ", cas);
    scanf("%lf%lf%lf", &ox, &oy, &r);
    O = Point(ox, oy);
    scanf("%lf%lf%lf%lf", &ax, &ay, &vx, &vy);
    A = Point(ax, ay);
    scanf("%lf%lf", &bx, &by);
    B = Point(bx, by);
    if(sgn((A-B).len()) == 0) {
      printf("Yes\n");
      continue;
    }
    if(sgn((A-O).len()-r) == 0) {
      ax -= vx;
      ay -= vy;
    }
    if(sgn((B-O).len()-r) < 0) {
      printf("No\n");
      continue;
    }
    vP tp = getX(O, r, A, Point(ax+vx,ay+vy));
    if(siz(tp) == 0) {
      Point av(ax+vx,ay+vy);
      double d1 = degs(av-A,B-A); 
      if(sgn(d1) == 0) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
      continue;
    }
    if(sgn((tp[0]-A) % (Point(ax+vx,ay+vy)-A)) <0) {
      printf("No\n");
      continue;
    }
    if(sgn((B-tp[0]).len()) == 0) {
      printf("Yes\n");
      continue;
    }
    //cout << "tp[0] = (" << tp[0].x << ',' << tp[0].y << ")" <<endl;
    Point av(ax+vx,ay+vy);
    double d1 = degs(av-A,B-A); 
    if(sgn(d1) == 0 && sgn((B-A).len()-(tp[0]-A).len()) <=0) {
      printf("Yes\n");
      continue;
    } 
    double sd1 = degs(A-tp[0],tp[0]-O); 
    double sd2 = degs(tp[0]-O,B-tp[0]); 
    double cd1 = degc(A-tp[0],tp[0]-O); 
    double cd2 = degc(tp[0]-O,B-tp[0]); 
    if(sgn(sd1-sd2) == 0 && sgn(cd1-cd2) == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

