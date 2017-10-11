#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1);
const double esp = 1e-9;
const double MAXDIS = 1e6;
const int MAXN = 1e4 + 100;

int x[MAXN], y[MAXN];
double dis[MAXN];
int n;
double A, B, C;

double calDis(int x1, int y1, int x2, int y2) {
  double res;
  res = pow(y2 - y1, 2) + pow(x2 - x1, 2);
  res = sqrt(res);
  return res;
}
double calX(double A, double B, double C, double x) {
  double res = A * x * x + B * x + C;
  return res;
}

int main() {
  double l, r, sum;
  int flag;
  int T;
  scanf("%d", &T);
  while (T --) {
    scanf("%d", &n);
    rep(i, 1, n + 1) {
      scanf("%d%d", &x[i], &y[i]);
    }
    rep(i, 1, n) {
      dis[i] = calDis(x[i], y[i], x[i + 1], y[i + 1]);
    }
    dis[n] = calDis(x[n], y[n], x[1], y[1]);
    l = 0; r = MAXDIS;
    A = B = C = 0.0;
    A += 1.0;
    flag = 1;
    sum = 0.0;
    rep(i, 1, n) {
      sum += flag * dis[i];
      if (flag > 0) {
        r = min(r, sum);
      } else {
        l = max(l, sum);
      }
      A += 1.0;
      B += -2 * sum;
      C += sum * sum;
      flag *= -1;
    }
//    cout << A << " " << B << " " << C << endl;
//    cout << l << " " << r << endl;
    sum += flag * dis[n];
//    cout << sum << endl;
    double x, res;
    if (n % 2 == 0) {
      if (sum != 0 || l > r + esp) {
        printf("IMPOSSIBLE\n");
      } else {
        x = -1 * B / (2 * A);
//        cout << "x= " << x << endl;
        if (l < x && x < r) {
          res = calX(A, B, C, x);
        } else if (x <= l) {
          res = calX(A, B, C, l);
          x = l;
        } else if (x >= r) {
          res = calX(A, B, C, r);
          x = r;
        }
        //res = max(calX(A, B, C, l), calX(A, B, C, r));
        printf("%.2lf\n", res * pi);
        printf("%.2lf\n", x);
        flag = 1;
        sum = x;
        rep(i, 1, n) {
          sum = dis[i] - sum;
          printf("%.2lf\n", sum);
        }
      }
    } else {
      x = sum / 2;
      if (l <= x + esp && x - esp <= r) {
        //res = max(calX(A, B, C, l), calX(A, B, C, r));
        res = calX(A, B, C, x);
        printf("%.2lf\n", res * pi);
        printf("%.2lf\n", x);
        flag = 1;
        sum = x;
        rep(i, 1, n) {
          sum = dis[i] - sum;
          printf("%.2lf\n", sum);
        }
      } else {
        printf("IMPOSSIBLE\n");
      }
    }
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

