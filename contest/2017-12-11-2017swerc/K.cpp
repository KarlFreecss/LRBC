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

const int maxN = 200000+13;
const long double eps = 1e-15;

struct Point {
  long long x, y;
  Point(){};
  Point(ll x, ll y) : x(x), y(y){};
  Point operator - (const Point& b) const {
    return Point(x - b.x, y - b.y);
  }
  ll operator ^ (const Point& b) const {
    return x*b.y - y * b.x;
  }
  ll operator * (const Point& b) const {
    return x*b.x + y*b.y;
  }
  void read() {
    scanf("%lld %lld", &x, &y);
  }
  long double dis() {
    return hypot((long double)x, (long double)y);
  }
};

ll dis2(const Point& a, const Point& b) {
  return (a - b) * (a - b);
}
Point p[maxN];
Point tp[maxN];

int Stack[maxN], top;
double R;

bool cmp(const Point p1, const Point p2) {
  ll temp = (p1 - p[0]) ^ (p2 - p[0]);
  if(temp > 0) return true;
  if(temp == 0 && dis2(p1, p[0]) <= dis2(p2, p[0])) {
      return true;
  }
  return false;
}

void graham(int n) {
  Point p0;
  int k = 0;
  p0 = p[0];
  for(int i = 1; i < n; i++) 
    if(p0.y > p[i].y || (p0.y == p[i].y && p0.x > p[i].x)) {
      p0 = p[i];
      k = i;
    }
  swap(p[k], p[0]);
  sort(p+1, p+n, cmp);
  //for(int i = 0; i < n; i++) {
  //  cout << p[i].x << ' ' << p[i].y << endl;
  //}
  if(n == 1) {
    top = 1;
    Stack[0] = 0;
    return ;
  }
  top = 2;
  Stack[0] = 0;
  Stack[1] = 1;
  if(n == 2) return ;
  for(int i = 2; i < n; i++) {
    while(top > 1 && ((p[Stack[top-1]]-p[Stack[top-2]])^(p[i]-p[Stack[top-2]])) <= 0) top--;
    Stack[top++] = i;
  }
  return ;
}

long double rotating_calipers(int n) {
  if(n == 2) return 0.0;
  long double ret = (long double) R * 2.0;
  Point v;
  int cur = 1;
  for(int i = 0; i < n; i++) {
    v = p[i] - p[(i+1)%n];
    while((v^(p[(cur+1)%n] - p[cur])) < 0) 
      cur = (cur+1) % n;
    long double temp = max(
        fabs((long double)((p[(i+1)%n]-p[cur])^(p[i]-p[cur])))/(p[(i+1)%n]-p[i]).dis(),
        fabs((long double)((p[(i+1)%n]-p[(cur+1)%n])^(p[i]-p[(cur+1)%n])))/(p[(i+1)%n]-p[i]).dis());
    ret = min(ret, temp);
  }
  return ret;
}

int work() {
  int N;
  if(scanf("%d", &N) != 1) return 0;
  scanf("%lf", &R);
  for(int i = 0; i < N; i++) p[i].read();
  graham(N);
//  cout << top<< endl;
  for(int i = 0; i < top; i++) tp[i] = p[Stack[i]];
  for(int i = 0; i < top; i++) p[i] = tp[i];
  long double ans = rotating_calipers(top);
  if(ans < eps) ans = 0.0;
  printf("%.15Lf\n", ans);
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

