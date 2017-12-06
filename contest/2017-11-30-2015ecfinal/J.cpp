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

const int maxN = 100000+13;
const long double eps = 1e-12;

inline int sgn (long double x) {
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}

inline long double sqr(long double x) {
  return x * x;
}
struct Block {
  double a, b;
  long double dis;
  void read() {
    scanf("%lf%lf", &a, &b);
    //a = b = 100000;
    dis = (long double)sqr((long double)a)+sqr((long double)b/2.0);
    dis = min(dis, (long double)sqr((long double)b)+sqr((long double)a/2.0));
  }
  friend bool operator < (const Block& x, const Block& y) {
    return x.dis < y.dis;
  }
};

long double s[maxN];
int N;
Block b[maxN];

bool check(long double r) {
  //cout << "check : " << N << endl;
  for(int i = 1; i <= N; i++) {
    if(r * r < b[i].dis) return false;
    s[i] = sqrt(r * r - b[i].dis);
    if(sgn(s[i] - 0.5) < 0) return false;
  }
  long double r1 = r, r2 = r;
  for(int i = 1; i <= N; i++){
    if(sgn(r1-0.5) < -1) return false;
    if(sgn(r1 - s[i]) >= 0) {
      r1 = s[i] - 1.0;
    } else {
      r1 = r1-1.0;
    }
    if(sgn(r2 - r1) > 0) swap(r1, r2);
    //cout << "deal : " << s[i] << endl;
    //cout << r1 << ' ' << r2 << endl;
  } 
  //if(sgn(r1 - s[N]) < 0 || sgn(r2 - s[N]) < 0) return false;
  if(sgn(r1+r2) >= 0) return true;
  return false;
}

double work() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) 
    b[i].read();
  sort(b + 1, b + 1 + N);
  long double l = 0.0, r = (1e5) * 3.0; 
  for(int k = 1; k <= 70; k++) {
    long double mid = (l + r) / 2.0;
    if(check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return (double)r;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: %.10lf\n", cas, work());
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

