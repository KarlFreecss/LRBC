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

const double eps = 1e-8;
struct Point {
  ll x, y;
  int h;
  double alpha;
  Point(){};
  Point(ll x, ll y) : x(x), y(y){};
  friend ll operator * (const Point& a, const Point& b) {
    return a.x*b.y - a.y*b.x;
  }
  friend Point operator - (const Point& a, const Point& b) {
    return Point(a.x - b.x , a.y - b.y);
  }
  void read() {
    scanf("%I64d %I64d", &x, &y);
  }
  void write() {
    printf("%I64d %I64d\n", x, y);
  }
  void calc_alpha() {
    alpha = atan2(x,y);
  }
  ll dis2() const{
    return x*x+y*y;
  }
};

inline int sgn( double x) {
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}
bool cmp (const Point &a, const Point& b) {
  if(sgn(a.alpha - b.alpha) == 0) {
    return a.dis2() < b.dis2();
  }
  return a.alpha < b.alpha;
}

const int maxN = 1000000+13;

Point T, p[maxN];
int N;

bool work() {
  T.read();
 // printf("%.10lf\n", atan2(2000000,0)) ;
 // printf("%.10lf\n", atan2(2000000,1)) ;
  if(scanf("%d", &N) != 1) return false;
  for(int i = 1; i <= N; i++) {
    p[i].read();
    p[i] = p[i] - T;
    scanf("%d", &p[i].h);
    p[i].calc_alpha();
  }
  sort(p+1, p+1+N,cmp);
  //for(int i = 1; i <= N; i++) {
    //p[i].write();
    //cout << p[i].h << endl;
    //cout << p[i].alpha << endl;
  //}
  p[0].alpha = p[1].alpha;
  vector<int> a; a.clear();
  int ans = 0;
  for(int i = 1; i <= N+1; i++) {
    if(sgn(p[i].alpha - p[i-1].alpha) != 0 || i == N+1) {
      //cout << "break at " << i <<  endl;
      ans += a.size();
      //cout << "ans add " << a.size() << endl;
      a.clear();
      if(i == N+1) break;
      a.push_back(p[i].h);
    } else {
      int th = p[i].h;
      if(a.size() == 0 || th > a.back()) a.push_back(th);
      else {
        *lower_bound(all(a),th) = th;
      }
    }
  }
  printf("%d\n", ans);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("L.in","r",stdin);
#endif
  work();
  //while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

