#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 13;
const double eps = 1e-8;
double rad[maxN];
double R = 0;
int T,K;
struct Point  
{  
    double x,y;  
    Point(double a = 1.0,double b = 1.0):x(a),y(b){}  
    Point operator + (const Point &a)  
    {  
        return Point(x+a.x,y+a.y);  
    }  
    Point operator - (const Point &a)  
    {  
        return Point(x-a.x,y-a.y);  
    }  
    Point operator * (const double a)  
    {  
        return Point(a*x,a*y);  
    }  
    Point Trans()  
    {  
        return Point(-y,x);  
    }  
    void Input()  
    {  
        scanf("%lf%lf",&x,&y);  
    }  
} ;  

struct Circle {  
    Point o;  
    double r;  
    Circle(Point a = Point(),double b = 1.0):o(a),r(b) {}  
    Point getPoint(double alpha)  
    {  
        return o + Point(r*cos(alpha),r*sin(alpha));  
    }  
    void Input()  
    {  
        o.Input();  
        scanf("%lf",&r);  
    }  
    void Output()  
    {  
        printf("%.8lf %.8lf %.8lf\n",o.x,o.y,r);  
    }  
} ;  
double dist(Point A,Point B)  
{  
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));  
}  
  
Point p(0,0);
Circle Inverse(Circle C)  {  
  Circle T;  
  double t = dist(C.o,p);  
  double x = 1.0 / (t - C.r);  
  double y = 1.0 / (t + C.r);  
  T.r = (x - y) / 2.0;  
  double s = (x + y) / 2.0;  
  T.o = p + (C.o - p) * (s / t);  
  return T;  
}  

double inline sqr(double x) {
  return x*x;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("nn-g.in","r",stdin);
#endif
  scanf("%d", &T);
  scanf("%lf", &R);
  double rR = 1.0/R;
  double g3 = sqrt(3.0);
  double ans = 2 * g3 / 3 * R;
  //cout << ans - R << endl;
  double r2 = 0.5 * (rR/(g3-1) - rR/(g3+1));
  double y2 = rR/(g3-1.0) - r2; ;

  double y0 = 0.0;
  int now = 0;
  //Circle nc(Point(0,y2), rR);
  for(int i = 1; i <= 11; i++) {
    double tr = r2 * 2.0 * i ;
    //double ypr = 1.0 / (y2 + tr + r2);
    //double ypr2 = 1.0 / (y2 + tr - r2);
    //double xx = (ypr2 - ypr) * 0.5;
    ////cout << xx << endl;
    Circle tc(Point(0,y2+tr), r2);
    tc = Inverse(tc);
    rad[i] = tc.r;
  }
  rep(cas , 1 ,T+1) {
    int k; scanf("%d", &k);
    if(k == -1) break;
    printf("%d %d\n", k , (int)(rad[k] + eps));
    //if(cas != T) printf("\n");
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

