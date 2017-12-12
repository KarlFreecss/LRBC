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

const int maxN = 40 + 13;
struct Point {
  double x, y;
  Point(){};
  Point(double x, double y) :x(x), y(y){};
  friend Point operator + (const Point& a, const Point& b) {
    return Point(a.x + b.x , a.y + b.y);
  }
  friend Point operator - (const Point& a, const Point& b) {
    return Point(a.x - b.x , a.y - b.y);
  }
  friend Point operator / (const Point& a, const double& b) {
    return Point(a.x / b , a.y / b);
  }
  double len2() {
    return x*x+y*y;
  }
  double det(const Point b) {
    return x*b.y-y*b.x;
  }
};

Point circumCenter(const Point &a, const Point &b, const Point &c) {
  Point bb = b - a, cc = c - a;
  double db = bb.len2(), dc = cc.len2(), d = 2 * bb.det(cc);
  return a - Point(bb.y * dc - cc.y * db, cc.x * db - bb.x * dc) / d;
}
int N;
Point p[maxN];

bool work() {
  if(scanf("%d",&N) != 1) return 0;
  for(int i = 1; i <= N; i++) 
    p[i].read();

}
int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

