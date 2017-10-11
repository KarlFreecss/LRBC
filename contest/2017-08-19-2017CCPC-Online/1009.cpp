#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;
const double Pi = acos(-1.0);

inline double S(double r) {
  return Pi*r*r;
}
inline double sqr(double x) {
  return x*x;
}
double R,r;
int T,k;

int main() {
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    scanf("%lf%lf%d", &R, &r, &k);
    if(R < r) swap(R,r);
    R*=2;
    r*=2;
    double D=1.*R*R/r;
    double h=D-R;
    int tk = k / 2;
    double w=0;
    double s=sqrt(sqr(R+h*0.5)+sqr(w));
    double tr = 0.5*(R*R/(s-h*0.5)-R*R/(s+h*0.5));
    double ans = 0.0;
    ans += S(tr);
    rep(i, 1, tk+1) {
      w = h * i;
      s=sqrt(sqr(R+h*0.5)+sqr(w));
      tr = 0.5*(R*R/(s-h*0.5)-R*R/(s+h*0.5));
      ans += S(tr) * 2.0;
    }
    if(k & 1) {
    } else {
      ans -= S(tr);
    }
    printf("%.5lf\n", ans);
  }
  return 0;
}

