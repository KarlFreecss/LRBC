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

const long long MAXS = 1e5 + 100;
const long long MAXG = 1e4 + 100;
const long long MM = 342307123;

struct CountType {
  public:
    long long x0, x1;
    CountType(long long iX0 = 0, long long iX1 = 0) {
      x0 = iX0;
      x1 = iX1;
    }
};
CountType Add(CountType a, CountType b) {
  return (CountType((a.x0 + b.x0) % MM, (a.x1 + b.x1) % MM));
}
CountType Sub(CountType a, CountType b) {
  CountType res;
  res.x0 = a.x0 - b.x0;
  if (res.x0 < 0)
    res.x0 += MM;
  res.x1 = a.x1 - b.x1;
  if (res.x1 < 0)
    res.x1 += MM;
  return res;
}

char s[MAXS], sX[MAXG], sY[MAXG];
int a[MAXS];
long long G, posX, posY, len, lenX, lenY;
CountType f[MAXG][2][2];

CountType cal(long long posLeft, long long posRight, char move[], int flag = 0) {
  CountType res;
  long long x, y, tmp, len;
  rep(i, posLeft + 1, posRight) {
    res = Add(res, f[G - 1][a[i]][a[i + 1]]);
  }
  x = a[posLeft], y = a[posLeft + 1];
  len = G - 1;
  rep(i, 0, len) {
    tmp = x ^ y;
    if (move[i] == 'D') {
      res = Add(res, f[G - 1 - i - 1][tmp][y]);
      y = tmp;
    } else {
      x = tmp;
    }
  }
  if (flag == 1) {
    if (x == 0)
      res = Add(res, CountType(1, 0));
    else
      res = Add(res, CountType(0, 1));
  }
  return res;
}

void work(int t) {
  CountType countX, countY, res;
  scanf("%s%d", &s, &G);
  len = strlen(s);
  rep(i, 0, len)
    a[i] = s[i] - '0';
  a[len] = 0;
  if (G > 1)
    scanf("%d%s", &posX, &sX);
  else
    scanf("%d", &posX);
  lenX = strlen(sX);
  if (G > 1)
    scanf("%d%s", &posY, &sY);
  else
    scanf("%d", &posY);
  lenY = strlen(sY);
//  cout << s << endl;
//  cout << sX << endl;
//  cout << sY << endl;
  int posRight = max(posX, posY) + 1;

  countX = cal(posX, posRight, sX, 1);
//  cout << countX.x0 << " " << countX.x1 << endl;
  countY = cal(posY, posRight, sY, 0);
//  cout << countY.x0 << " " << countY.x1 << endl;
  res = Sub(countX, countY);
  printf("Case %d: %d %d\n", t, res.x0, res.x1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  int T;
  f[0][0][0] = CountType(1, 0);
  f[0][0][1] = CountType(1, 0);
  f[0][1][0] = CountType(0, 1);
  f[0][1][1] = CountType(0, 1);
  rep(i, 1, MAXG) {
    rep(j, 0, 2) {
      rep(k, 0, 2) {
        long long tmp = j ^ k;
        f[i][j][k] = Add(f[i-1][j][tmp], f[i-1][tmp][k]);
      }
    }
  }
  scanf("%d", &T);
  rep(t, 1, T + 1) {
    work(t);
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

