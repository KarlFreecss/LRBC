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

const int MAXN = 1e5 + 5;

int calc(int a, int b, const int l, const int an){
  a = abs(a);
  b = abs(b);
  if (l == 1 && a != an) return MAXN * 2;
  int aNeedNumMin = ((a - l * an) - 1) / (l - 1) + 1;
  if (l == 1) return b;
  int bNeedNumMin = ((a - (l - 1) * an) - 1) / l + 1;
  return max(aNeedNumMin, bNeedNumMin);
}

void fixedXY(const int a, const int b, const int x, const int y,
    int &ex, int &ey, int &bx, int &by) {
  
}

void work(){
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  int minAns = MAXN;
  int aAxis = 0, bAxis = 0;
  for (int i = 0; i < MAXN; ++i) {
    int ta = i;
    int tb = calc(abs(a), abs(b), n, ta);
    if (ta + tb < minAns) {
      minAns = ta + tb;
      aAxis = ta;
      bAxis = tb;
    } else if (ta + tb == minAns) {
      if (abs(a) > abs(b)) {
        if (ta > aAxis) {
          aAxis = ta;
          bAxis = tb;
        }
      } else {
        if (tb > bAxis) {
          aAxis = ta;
          bAxis = tb;
        }
      }
    }
  }
  cout << minAns << ' ' << aAxis << ' ' << bAxis << endl;

  int putNum = 0;
  printf("%d\n", minAns);
  int da = 1, db = 1;
  int curX = 0, curY = 0;
  if (a < 0) da = -1;
  if (b < 0) db = -1; 
  for (int i = 0; i < aAxis; ++i) {
    int bx = curX + 1 * da;
    int by = curY + 0 * db;
    int ex = curX + n * da;
    int ey = curY + n - 1 * db;
    if (putNum + 1 == aAxis + bAxis){
      fixedXY(curX, curY, a, b, bx, by, ex, ey);
    }
  }

}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

