#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1010;
int sgn(int x){
  if (x > 0) return 1;
  if (x == 0) return 0;
  return -1;
}

struct POINT{
  int x, y;
  POINT() {}
  POINT(double _x, double _y) {
    x = _x; y = _y;
  }
  POINT operator -(const POINT &b) const {
    return POINT(x - b.x, y - b.y);
  }
  double operator ^(const POINT &b) const {
    return x*b.y - y*b.x;
  }
  double operator *(const POINT &b) const {
    return x*b.x + y*b.y;
  }
};

long long dist(const POINT & a, const POINT & b){
  long long x = a.x - b.x, y = a.y - b.y;
  return x * x + y * y;
}
POINT myList[MAXN];
int Stack[MAXN], top;

bool _cmp(const POINT & p1, const POINT & p2) {
  double tmp = (p1-myList[0]) ^ (p2 - myList[0]);
  if (sgn(tmp) > 0) return true;
  else if (sgn(tmp) == 0 && sgn(dist(p1, myList[0]) - dist(p2, myList[0])) <= 0)
    return true;
  else return false;
}

void Graham(int n){
  POINT p0;
  int k = 0;
  p0 = myList[0];
  for (int i = 1; i < n; i++) {
    if ( (p0.y > myList[i].y) || p0.y == myList[i].y && p0.x > myList[i].x) {
      p0 = myList[i];
      k = i;
    }
  }

  swap(myList[k], myList[0]);
  sort(myList+1, myList+n, _cmp);
  if (n == 1) {
    top = 1;
    Stack[0] = 0;
    return ;
  }
  if (n == 2) {
    top = 2;
    Stack[0] = 0;
    Stack[1] = 1;
    return ;
  }

  Stack[0] = 0;
  Stack[1] = 1;
  top = 2;
  for (int i = 2; i < n; ++i) {
    while (top > 1 &&
        sgn((myList[Stack[top-1]]-myList[Stack[top-2]])^
          (myList[i] - myList[Stack[top-2]])) <= 0) 
      top--;
    Stack[top++] = i;
  }
}


int main() {
#ifndef ONLINE_JUDGE
  //freopen("G.in","r",stdin);
#endif
  int T,N;
  scanf("%d", &T);
  rep(cas, 0, T) {
    scanf("%d", &N);
    rep(i,0,N) scanf("%d%d", &myList[i].x,&myList[i].y);
    Graham(N);
    if(top != N) {
      printf("NO\n");
      continue;
    }
    Stack[top] = Stack[0];
    Stack[top+1] = Stack[1];
    bool ok = true;
    ll scos =(myList[Stack[0]]-myList[Stack[1]])
      *(myList[Stack[1]] - myList[Stack[2]]);
    ll ssin=(myList[Stack[0]]-myList[Stack[1]])
      ^(myList[Stack[1]] - myList[Stack[2]]);
    rep(i,1,top) {
      ll tcos =(myList[Stack[i]]-myList[Stack[i+1]])
        *(myList[Stack[i+1]] - myList[Stack[i+2]]);
      ll tsin =(myList[Stack[i]]-myList[Stack[i+1]])
        ^(myList[Stack[i+1]] - myList[Stack[i+2]]);
      if(tcos != scos || tsin!=ssin) {
        ok = false;
        break;
      }
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

