#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i ++)
#define per(i,a,b) for (int i = b-1; i >= a; i --)

const int MAXN = 1e5 + 100;
const long long MAXDIS = 1e16;

class Road {
  public:
    long long x, y, dis;
    Road(long long iX = 0, long long iY = 0, long long iDis = 0) {
      x = iX;
      y = iY;
      dis = iDis;
    }
};

vector<Road> roads[MAXN];
long long x[MAXN], y[MAXN], dis[MAXN];
long long w[MAXN];
bool vis[MAXN];
long long N, M, res;

int main() {
  freopen("F.in", "r", stdin);

  long long T, nx, ny, nDis;
  scanf("%lld", &T);
  
  rep(t, 1, T + 1) {
    scanf("%lld%lld", &M, &N);
    rep(i, 0, M)
      scanf("%lld", &x[i]);
    rep(i, 0, M)
      scanf("%lld", &y[i]);
    rep(i, 0, M)
      scanf("%lld", &dis[i]);
    rep(i, 1, N + 1) {
      scanf("%lld", &w[i]);
      roads[i].clear();
    }
    rep(i, 0, M) {
      roads[y[i]].push_back(Road(y[i], x[i], dis[i]));
    }

    queue<int> q;
    memset(vis, 0, sizeof(vis));
    rep(i, 1, N + 1) {
      if (w[i] == 0) {
        dis[i] = 0;
        q.push(i);
        vis[i] = true;  
      }
      else dis[i] = MAXDIS;
    }

    while (!q.empty()) {
      nx = q.front();
      q.pop();
      vis[nx] = false;

      rep(i, 0, roads[nx].size()) {
        ny = roads[nx][i].y;
        nDis = roads[nx][i].dis;
        if (dis[ny] > dis[nx] + nDis) {
          dis[ny] = dis[nx] + nDis;
          if (!vis[ny]) {
            q.push(ny);
            vis[ny] = true;
          }
        }
      }
    }

    res = 0;
    rep(i, 1, N + 1) {
      if (w[i] == 2 && res < MAXDIS) {
        res += dis[i];
      }
    }

    if (res >= MAXDIS)
      printf("Case #%d: -1\n", t);
    else printf("Case #%d: %lld\n", t, res);
  }

  return 0;
}
