#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=60000+13;

int N;
double x[maxN],v[maxN];

double cal(double xx) {
  double ret = 0.0;
  rep(i,1,1+N) {
    double tt = abs(xx-x[i]) / v[i];
    if(tt > ret) ret = tt;
  }
  return ret;
}

int main()
{
  scanf("%d", &N);
  rep(i,1,1+N) scanf("%lf",&x[i]);
  rep(i,1,1+N) scanf("%lf",&v[i]);
  double l = 1.0, r = 1e9;
  rep(cas, 1, 300) {
    double mid = (l+r)/2;
    double mid2 = (mid+r) /2;
    double a = cal(mid);
    double a2 = cal(mid2);
    if(a < a2) r = mid2;
    else l=mid;
  }
  printf("%.12lf\n",cal(l));

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

