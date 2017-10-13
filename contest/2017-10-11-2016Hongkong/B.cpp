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

const double pi = acos(-1.0);

const double eps = 1e-8;
int cmp(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}

struct point {
  double x, y;
  point() {}
  point(double a, double b) : x(a), y(b) {}
  friend point operator - (const point & a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  double norm(){
    return sqrt(x*x + y*y);
  }
};

double dist(const point &a, const point &b){
  return (a-b).norm();
}

double det(const point & a, const point &b){
  return a.x * b.y - a.y * b.x;
}

double dot(const point &a, const point &b){
  return a.x * b.x + a.y * b.y;
}

double dis_point_segment(const point p, const point s, const point t){
  if (cmp(dot(p-s, t-s)) < 0) return (p-s).norm();
  if (cmp(dot(p-t, s-t)) < 0) return (p-t).norm();
  return fabs(det(s-p, t-p)/dist(s,t));
}

#define debug() cout<< __LINE__ << ' '

int main() {
#ifndef ONLINE_JUDGE
 // freopen("B.in","r",stdin);
#endif
  int R, l, w;
  scanf("%d%d%d", &R, &l, &w);
 int T;
  scanf("%d", &T);
  for (int i = 0 ; i < T; ++i) {
    double r = min((double)R*2, (double)l);
    r = min(r, (double)w);
    double thetaA, thetaB;
    scanf("%lf%lf", &thetaA, &thetaB);
    point lc(0, w);
    point ur(l, w);
    point ul(l - l*cos(thetaA), w + l*sin(thetaA));
    if (thetaA < pi / 2) {
     r = min(r, dis_point_segment(lc, ur, ul));
    }
    point dl(l - l*cos(thetaB), l*sin(thetaB));
    r = min(r, dis_point_segment(dl, ur, ul));
    r = min(r, dis_point_segment(point(l, w), point(l, 0), dl));
    if (thetaB > pi / 2) {
      r = min(r, w - sin(thetaB) * l);
    }
    r = max(0.0, r);
    printf("%.15lf\n", r/2.);
  }
    
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

