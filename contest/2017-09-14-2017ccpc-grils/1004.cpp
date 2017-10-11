#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 60;
const int MAXDIS = 1e6;
const long long MM = 1e9 + 7;

int dis[MAXN][MAXN], dis0[MAXN], dis0Count[MAXN];
bool arriv[MAXN];
int n;

int main() {
#ifndef ONLINE_JUDGE
  freopen("1004.in","r",stdin);
#endif

  long long res;
  char c;
  while (cin >> n) {
    rep(i, 0, n) {
      rep(j, 0, n) {
        cin >> c;
        dis[i][j] = c - '0';
      }
    }
    rep(i, 0, n) {
      arriv[i] = false;
      dis0[i] = MAXDIS;
      dis0Count[i] = -1;
    }
    arriv[0] = true;
    dis0[0] = 0;
    rep(i, 0, n) {
      if (dis[0][i] != 0) {
        dis0[i] = dis[0][i];
        dis0Count[i] = 1;
      }
    }
    res = 1;
    int minDis, minID;
    rep(k, 0, n - 1) {
      minDis = MAXDIS;
      minID = -1;
      rep(i, 0, n) {
        if (!arriv[i]) {
          if (minDis > dis0[i]) {
            minDis = dis0[i];
            minID = i;
          }
        }
      }
      if (minID == -1)
        break;
      res *= dis0Count[minID];
      res %= MM;
      arriv[minID] = true;
      rep(i, 0, n) {
        if (!arriv[i] && dis[minID][i] != 0) {
          int tmp = dis0[minID] + dis[minID][i];
          if (tmp == dis0[i]) {
            dis0Count[i] ++;
          } else if (tmp < dis0[i]) {
            dis0[i] = tmp;
            dis0Count[i] = 1;
          }
        }
      }
    }
    if (minID == -1) {
      cout << 0 << endl;
      continue;
    }
    cout << res << endl;
  }

  return 0;
}

