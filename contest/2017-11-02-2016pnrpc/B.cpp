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

const int MAXN = 60;
const int MAXVAL = 1e6;

class point {
  public:
    int x, y;
    point(int iX = 0, int iY = 0) {
      x = iX;
      y = iY;
    }
};
class type1 {
  public:
    int x, y, k, val;
    type1(int iX = 0, int iY = 0, int iK = 0, int iVal = 0) {
      x = iX;
      y = iY;
      k = iK;
      val = iVal;
    }
    bool operator < (const type1 & a) const {
      if (val == a.val) {
        if (k == a.k) {
          if (x == a.x) {
            return y < a.y;
          }
          return x < a.x;
        }
        return k < a.k;
      }
      return val < a.val;
    }
};

int n, m, t, len, sX, sY, tX, tY;
char s[MAXN];
int command[MAXN];
char mp[MAXN][MAXN];
int pX[4], pY[4];
int dis[MAXN][MAXN][MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
int flag[MAXN][MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  pX[0] = -1; pY[0] = 0;
  pX[1] = 0; pY[1] = 1;
  pX[2] = 1; pY[2] = 0;
  pX[3] = 0; pY[3] = -1;
  cin >> n >> m;
  for (int i = 0; i <= n + 1; i ++)
    for (int j = 0; j <= m + 1; j ++)
      mp[i][j] = '#';
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      cin >> mp[i][j];
//      cout << mp[i][j] << endl;
      if (mp[i][j] == 'R') {
        sX = i;
        sY = j;
      }
      if (mp[i][j] == 'E') {
        tX = i;
        tY = j;
      }
    }
  }
  cin >> s;
  len = strlen(s);
  for (int i = 1; i <= len; i ++) {
    if (s[i - 1] == 'U')
      command[i] = 0;
    if (s[i - 1] == 'R')
      command[i] = 1;
    if (s[i - 1] == 'D')
      command[i] = 2;
    if (s[i - 1] == 'L')
      command[i] = 3;
  }
  memset(flag, 0, sizeof(flag));
  set<type1> s;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      for (int k = 0; k <= len; k ++) {
        f[i][j][k] = MAXVAL;
        s.insert(type1(i, j, k, MAXVAL));
//  cout << "size = " <<  s.size() << endl;
      }
      for (int x = 1; x <= n; x ++) {
        for (int y = 1; y <= m; y ++) {
          dis[i][j][x][y] = MAXVAL;
        }
      }
    }
  }
//  cout << "size = " <<  s.size() << endl;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      if (mp[i][j] == '#') continue;
      dis[i][j][i][j] = 0;
      queue<point> q;
      q.push(point(i, j));
      while (!q.empty()) {
        point tmp = q.front();
        if (i == 1 && j == 1) {
//          cout << "============" << endl;
//          cout << tmp.x << " " << tmp.y << " " << dis[i][j][tmp.x][tmp.y] << endl;
        }
        q.pop();
        for (int k = 0; k < 4; k ++) {
          int x = tmp.x + pX[k];
          int y = tmp.y + pY[k];
//          cout << x << " " << y << " " << mp[x][y] << " " << dis[i][j][x][y] << endl;
          if (mp[x][y] == '#') continue;
//          cout << "111111111111" << endl;
          if (dis[i][j][x][y] != MAXVAL) continue;
//          cout << "2222222222" << endl;
        if (i == 1 && j == 1) {
//          cout << "--------------" << endl;
//          cout << tmp.x << " " << tmp.y << " " << dis[i][j][tmp.x][tmp.y] << endl;
//          cout << x << " " << y << endl;
        }

          dis[i][j][x][y] = dis[i][j][tmp.x][tmp.y] + 1;
          q.push(point(x, y));
        }
      }
    }
  }
//  cout << dis[1][1][2][2] << endl;
//  cout << "==============" << endl;
  s.erase(s.find(type1(sX, sY, 0, f[sX][sY][0])));
  f[sX][sY][0] = 0;
  s.insert(type1(sX, sY, 0, 0));
  for (int kk = 0; kk < MAXVAL; kk ++) {
 //   cout << kk << endl;
//    if (kk % 100 == 0)
//      cout << kk << endl;
    int x, y, step, minVal = MAXVAL + 1;
    /*
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= m; j ++) {
        for (int k = 0; k <= len; k ++) {
          if (flag[i][j][k] == 1) continue;
          if (f[i][j][k] < minVal) {
            minVal = f[i][j][k];
            x = i;
            y = j;
            step = k;
          }
        }
      }
    }
    */
//    cout << "--------------" << endl;
    type1 typeTmp = *s.begin();
//    cout << typeTmp.x << " " << typeTmp.y << endl;
//    cout << "--------------" << endl;
    s.erase(s.begin());
    x = typeTmp.x;
    y = typeTmp.y;
    step = typeTmp.k;
//    cout << x << " " << y << " " << step << " " << f[x][y][step] << endl;
    if (x == tX && y == tY)
      break;
    flag[x][y][step] = 1;
    for (int k = 0; k < 4; k ++) {
      int i = x + pX[k];
      int j = y + pY[k];
      if (mp[i][j] == '#') continue;
//      cout << i << " " << j << endl;
      if (flag[i][j][step] == 0)
        s.erase(s.find(type1(i, j, step, f[i][j][step])));
      f[i][j][step] = min(f[i][j][step], f[x][y][step] + dis[x][y][i][j]);
      if (flag[i][j][step] == 0)
        s.insert(type1(i, j, step, f[i][j][step]));
    }
    /*
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= m; j ++) {
        f[i][j][step] = min(f[i][j][step], f[x][y][step] + dis[x][y][i][j]);
      }
    }
    */
    int tmp = f[x][y][step];
    for (int i = step + 1; i <= len; i ++) {
      int tmpX = x + pX[command[i]];
      int tmpY = y + pY[command[i]];
      if (mp[tmpX][tmpY] != '#') {
        x = tmpX;
        y = tmpY;
      }
      if (flag[x][y][i] == 0)
        s.erase(s.find(type1(x, y, i, f[x][y][i])));
      f[x][y][i] = min(f[x][y][i], tmp);
      if (flag[x][y][i] == 0)
        s.insert(type1(x, y, i, f[x][y][i]));
    }
  }
//  cout << dis[1][1][2][2] << endl;
//  cout << tX << " " << tY << endl;
  int res = MAXVAL;
  for (int i = 0; i <= len; i ++) {
    res = min(res, f[tX][tY][i]);
  }
  printf("%d\n", res);

  return 0;
}

