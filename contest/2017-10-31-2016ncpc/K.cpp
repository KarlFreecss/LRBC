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

const int MAXN = 1e5 + 100;

class line {
  public:
  double x, y, px, py, T;
  line(double lastX = 0, double lastY = 0, double nowX = 0, double nowY = 0) {
    x = lastX;
    y = lastY;
    T = sqrt(pow(nowX - lastX, 2) + pow(nowY - lastY, 2));
    px = (nowX - lastX) / T;
    py = (nowY - lastY) / T;
  }
};

line a[MAXN], b[MAXN];
int n, m;

double calDis(line a, line b, double T) {
//  cout << "===============" << endl;
//  cout << a.x << " " << a.y << " " << a.px << " " << a.py << endl;
//  cout << b.x << " " << b.y << " " << b.px << " " << b.py << endl;
  double b1 = b.x - a.x;
  double a1 = b.px - a.px;
  double b2 = b.y - a.y;
  double a2 = b.py - a.py;
  double tA = pow(a1, 2) + pow(a2, 2);
  double tB = 2 * a1 * b1 + 2 * a2 * b2;
  double tC = pow(b1, 2) + pow(b2, 2);
//  cout << tA << " " << tB << " " << tC << endl;
  double res = min(tC, tA * T * T + tB * T + tC);
//  cout << res << endl;
  if (tA != 0) {
    double mid = -1 * tB / (2 * tA);
    if (0 <= mid && mid <= T)
      res = min(res, tA * mid * mid + tB * mid + tC);
  }
  return res;
}

void work() {
  int lastX, lastY, nowX, nowY;
  double res = 1e8;
  scanf("%d", &n);
  scanf("%d%d", &lastX, &lastY);
  for (int i = 1; i < n; i ++) {
    scanf("%d%d", &nowX, &nowY);
    a[i] = line(lastX, lastY, nowX, nowY);
    lastX = nowX;
    lastY = nowY;
  }
  scanf("%d", &m);
  scanf("%d%d", &lastX, &lastY);
  for (int i = 1; i < m; i ++) {
    scanf("%d%d", &nowX, &nowY);
    b[i] = line(lastX, lastY, nowX, nowY);
    lastX = nowX;
    lastY = nowY;
  }
  int i = 1, j = 1;
  while (i < n && j < m) {
    double cT = min(a[i].T, b[j].T);
    double minDis = calDis(a[i], b[j], cT);
//    cout << cT << " " << minDis << endl;
    res = min(res, minDis);
    if (a[i].T < b[j].T) {
      i ++;
      b[j].T -= cT;
      b[j].x += cT * b[j].px;
      b[j].y += cT * b[j].py;
    } else {
      j ++;
      a[i].T -= cT;
      a[i].x += cT * a[i].px;
      a[i].y += cT * a[i].py;
    }
  }
  res = sqrt(res);
  printf("%.12lf\n", res);
  return;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("K.in","r",stdin);
#endif
  work();
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

