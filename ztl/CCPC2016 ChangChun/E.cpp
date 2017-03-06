#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i ++)
#define per(i,a,b) for (int i = b-1; i >= a; i --)

const int MAXN = 100;
const int MAXDIGIT = 10;

class Equations {
  public:
    int a, b, c, limit;
    Equations(int iA = 0, int iB = 0, int iC = 0, int iLimit = 0) {
      a = iA;
      b = iB;
      c = iC;
      limit = iLimit;
    }
};

Equations equations[MAXN];
int sumEquations[MAXN];
int digitNum[MAXDIGIT];
int sum[MAXN];
int n, res;

void dfs(int t, int num) {
//  cout << t << " " << num << endl;
  res = max(res, num);
  if (t >= n)
    return;
  int a, b, c, limit;
  a = equations[t].a;
  b = equations[t].b;
  c = equations[t].c;
  limit = equations[t].limit;
//  cout << a << " " << b << " " << c << " " << limit << endl;
  int nextMax = (sum[MAXDIGIT - 1] - sum[a - 1]) / 3;
  if (t == 0) {
    nextMax = min(nextMax, sumEquations[n - 1]);
  } else {
    nextMax = min(nextMax, sumEquations[n - 1] - sumEquations[t - 1]);
  }
  if (res >= num + nextMax) {
    return;
  }
//  cout << "--------" << endl;
  per(i, 0, limit + 1) {
    digitNum[a] -= i;
    digitNum[b] -= i;
    digitNum[c] -= i;
    if (digitNum[a] >= 0 && digitNum[b] >= 0 && digitNum[c] >= 0) {
      dfs(t + 1, num + i);
    }
    digitNum[a] += i;
    digitNum[b] += i;
    digitNum[c] += i;
  }
  return;
}

int main() {
//  freopen("E.in", "r", stdin);

  n = 0;
  rep(i, 1, MAXDIGIT) {
    rep(j, i, MAXDIGIT) 
      if (i + j <= 9) {
        if (i == j) {
          equations[n ++] = Equations(i, j, i + j, 1);
        } else {
          equations[n ++] = Equations(i, j, i + j, 2);
        }
      }
  }
  sumEquations[0] = equations[0].limit;
  rep(i, 1, n)
    sumEquations[i] = sumEquations[i - 1] + equations[i].limit;

  int t, T;
  scanf("%d", &T);
  rep(t, 1, T + 1) {
//    cout << "=========" << endl;
    sum[0] = 0;
    rep(i, 1, MAXDIGIT) {
      scanf("%d", &digitNum[i]);
      sum[i] = sum[i - 1] + digitNum[i];
    }
    res = 0;
    dfs(0, 0);
    printf("Case #%d: %d\n", t, res);
  }
  

  return 0;
}
