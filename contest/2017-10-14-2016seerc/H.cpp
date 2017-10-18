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
const int maxN = 5000 + 13;

inline int sgn(double x) {
  if(fabs(x) < eps) return 0;
  if(x < 0 ) return -1;
  return 1;
}

struct Point {
  int x,y;
  int id;
  Point(){};
  Point(int x, int y) : x(x), y(y) {};
  Point operator - (const Point& b) const {
    return Point(x - b.x , y - b.y);
  }
  double operator ^ (const Point& b) const {
    return x*b.y - y*b.x;
  }
};

Point List[maxN];
int Stack[maxN], top;

inline double dist(Point p1, Point p2) {
  return hypot(p1.x - p2.x , p1.y - p2.y);
}
bool _cmp(Point p1, Point p2) {
  double tmp = (p1 - List[0])^(p2 - List[0]);
  if(sgn(tmp) > 0) return true;
  if(sgn(tmp) == 0 && sgn(dist(p1,List[0]) - dist(p2, List[0])) <= 0) 
    return true;
  return false;
}

vector<int> ans;
int v[maxN];

inline int nextI(int id, int n) {
  for(int i = id + 1; i < n; i++) 
    if(!v[i]) return i;
  for(int i = 0; i < id; i++) 
    if(!v[i]) return i;
  return -1;
}
void Graham(int n) {
  Point p0;
  int k = 0;
  p0 = List[0];
  for(int i = 1; i < n; i++) {
    if( (p0.y > List[i].y) || (p0.y == List[i].y && p0.x > List[i].x)) {
      p0 = List[i];
      k = i;
    }
  }
  swap(List[k], List[0]);
  sort(List+1, List+n, _cmp);
  if(n == 1) {
    top = 1;
    Stack[0] = 0;
    return ;
  }
  if(n == 2) {
    top = 2;
    Stack[0] = 0;
    Stack[1] = 1;
    return ;
  }
  Stack[0] = 0;
  Stack[1] = 1;
  top = 2;
  int used = 0;
  //while(used < n) {
    for(int i = 2; i != -1; i=nextI(i, n)) {
      cout << i << endl;
      while(top > 1 && sgn((List[Stack[top-1]]-List[Stack[top-2]])^(List[i]-List[Stack[top-2]])) <= 0) {
        v[Stack[top - 1]] = 0;
        top --;
      }
      Stack[top++] = i;
      v[i] = 1;
      //if(top == n) return ;
    }
    /*
    for(int i = 0; i < top; i++) {
      ans.push_back(List[Stack[i]].id);
      v[Stack[i]] = 1;
      used++;
    }
    if(top > 2) {
      Stack[0] = Stack[top - 2];
      Stack[1] = Stack[top - 1];
      top = 2;
    }
    */
  //}
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  int N;
  scanf("%d", &N);
  rep(i ,0 ,N) {
    scanf("%d%d", &List[i].x, &List[i].y);
    List[i].id = i+1;
  }
  Graham(N);
  printf("%d\n", N);
  rep(i, 0, N-1) 
    printf("%d ", List[Stack[i]].id);
  printf("%d\n", List[Stack[N-1]].id);

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

