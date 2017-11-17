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

const int maxN = 200+13;
const double pi = acos(-1.0);
const double eps = 1e-8;

inline double sgn(double x) {
  return x < -eps ? -1 : x > eps;
}

inline double sqr(double x) {return x*x;}
inline double angle(double x, double y) {
  double ret = atan2(y,x);
  if(sgn(ret) < 0) ret += 2.0 * pi;
  return ret;
}

struct P {
  double x, y;
};
struct circle {
  P o;
  double r;
}c[maxN];

struct DEVICE{
  P pos;
  double z;
} device[maxN];

struct arc {
  double ag;
  int t;
  inline bool operator < (const arc& a) const {
    return ag == a.ag ? t > a.t : ag < a.ag;
  }
}a[4*maxN + 13];

double adjust(double x) {
  if(sgn(x) < 0) x += 2.0 * pi;
  if(sgn(x - 2.0 * pi) >= 0) x -= 2.0 * pi;
  return x;
}

double ans[maxN];
void circleKunion(circle c[], int n) {
  for(int i = 0; i <= n; i++) ans[i] = 0.0;
  /*
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(sgn(c[i].o.x - c[j].o.x) == 0 && sgn(c[i].o
    }
  }
  */
  for(int i = 0; i < n; i++) {
    int m = 0, times = 0;
    for(int j = 0; j < n; j++) if(i!=j) {
      double dis = hypot(c[i].o.x - c[j].o.x, c[i].o.y - c[j].o.y);
      if(sgn(dis + c[i].r - c[j].r) <= 0) {
        times ++;
      } else if(sgn(dis + c[j].r - c[i].r) <= 0) {
        continue;
      } else if(sgn(dis - c[i].r - c[j].r) < 0) {
        double dx = (sqr(c[i].r) - sqr(c[j].r) + sqr(dis)) / 2.0 / dis;
        double dy = (sqrt(sqr(c[i].r) - sqr(dx)));
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
          m+=2;
        }
      }
    }
    if(m == 0) {
      ans[times] += pi * sqr(c[i].r);
      continue;
    }
    sort(a, a+m);
    a[m].ag = a[0].ag + 2.0 * pi;
    a[m++].t = 1;
    int s = times + a[0].t;
    for(int j = 1; j < m; j++) {
      int t = s; s += a[j].t;
      double dx = adjust(a[j].ag - a[j-1].ag);
      ans[t] += sqr(c[i].r) / 2.0 * (dx - sin(dx));
      double x1 = c[i].o.x + c[i].r * cos(a[j-1].ag);
      double y1 = c[i].o.y + c[i].r * sin(a[j-1].ag);
      double x2 = c[i].o.x + c[i].r * cos(a[j].ag);
      double y2 = c[i].o.y + c[i].r * sin(a[j].ag);
      ans[t] += (x1 * y2 - x2 * y1) / 2.0;
    }
  }
  return ;
}

double calcS(double h, DEVICE dev[], const int n, const int W, const int K){
  for (int i = 0; i < n; ++i) {
    c[i].o = device[i].pos;
    double x = device[i].pos.x, y = device[i].pos.y;
    double dist = sqrt(h * h + x * x + y * y);
    c[i].r = W * 1. / (dist * device[i].z);
    //cout << W << ' ' << device[i].z << endl;
    //printf("x = %.4f, y = %.4f, r = %.4f\n", x, y, c[i].r);
  }
  circleKunion(c, n);
  double totS = 0;
  //for (int i = K-1; i <= n; ++i) {
  //  totS += ans[i];
  //}
  totS = ans[K-1];
  //cout << h << ' ' << totS << endl;
  return totS;
}

void work(){
  int n, W, K, S;
  scanf("%d%d%d%d", &n, &W, &K, &S);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf%lf", &device[i].pos.x, &device[i].pos.y, &device[i].z);
  }
  if (K == 0) {
    puts("Oops!");
    return ;
  }
  double low = 0, high = 501;
  while (fabs(high - low) > 1e-6){
    double mid = (high + low ) / 2;
    double s = calcS(mid, device, n, W, K);
    if (s >= S) {
      low = mid;
    } else high = mid;
  }
  double checkS = calcS(low, device, n, W, K);
  //checkS = calcS(307.0016, device, n, W, K);
  if (checkS >= S) {
    if (low > 500) {
      puts("Oops!");
    } else {
      printf("%.4f\n", low);
    }
  } else {
    puts("No solution!");
  }
}

int main() {
//  c[0] = (circle){3, 4, 5};
//  c[1] = (circle){4, 5, 6};
//  c[2] = (circle){5, 6, 7};
//  c[3] = (circle){16, 9, 3};
//  c[4] = (circle){16, 5, 5};
//  circleKunion(c, 5);
//  for (int i = 0; i < 5; ++i) {
//    ans[i] -= ans[i+1];
//    printf("[%d] = %.4lf\n", i + 1, ans[i]);
//  }
//  return 0;
//#ifndef ONLINE_JUDGE
//  freopen("H.in","r",stdin);
//#endif

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

