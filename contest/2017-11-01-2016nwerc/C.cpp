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

const int maxN = 1000 + 13;

inline int sgn(int x) {
  if(x < 0) return -1;
  if(x > 0) return 1;
  return 0;
}
struct Point {
  int x, y;
  Point(){};
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
  void input() {
    scanf("%d%d", &x, &y);
  }
  void out() {
    printf("%d %d\n", x, y);
  }
  friend Point operator - (const Point & a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
  }
  friend int operator ^ (const Point & a, const Point& b) {
    return a.x * b.y - a.y * b.x;
  }
  friend bool operator == (const Point & a, const Point& b) {
    return (a.x == b.x) && (a.y == b.y);
  }
};

struct Line {
  Point s,e;
  Line(){};
  Line(Point _s, Point _e) {
    s = _s; e = _e;
  }
};

bool interl(Line l1, Line l2) {
  return 
    max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && 
    min(l1.s.x, l1.e.x) <= max(l2.s.x, l2.e.x) && 
    max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && 
    min(l1.s.y, l1.e.y) <= max(l2.s.y, l2.e.y) && 
    sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 && 
    sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;

}

int W, P;
Point w[maxN], p[maxN];
Line l[maxN];
int v[maxN];
int tv[maxN];

bool dfs(int id, int c) {
  //cout << "dfs : " ;
  //cout << id << ' ' << c << endl;
  v[id] = c;
  for(int i = 1; i <= P; i++) {
    if(i == id) continue;
    if(interl(l[id], l[i]) == false) continue;
    if(l[id].s == l[i].s) continue;
    //cout << "inter : " << id << ' ' << i << endl;
    //cout << "id.s : " ; l[id].s.out();
    //cout << "i.s : " ; l[i].s.out();
    if(v[i] == c) return false;
    if(v[i] == -c) continue;
    if(false == dfs(i, -c)) return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  scanf("%d%d", &W, &P);
  for(int i = 1; i <= W; i++) w[i].input();
  for(int j = 1; j <= P; j++) {
    int wid;
    scanf("%d", &wid);
    p[j].input();
    l[j] = Line(w[wid], p[j]);
  }
  bool ok = true;
  memset(v,0,sizeof(v));
  memset(tv,0,sizeof(tv));
  for(int i = 1; i <= P; i++) {
    if(v[i] == 0) {
      if(dfs(i, 1)) {
        continue;
      } else {
        ok = false;
        break;
      }
    }
  }
  if(ok) {
    printf("possible\n");
  } else {
    printf("impossible\n");
  }
  //cout << interl(l[1], l[2]) << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

