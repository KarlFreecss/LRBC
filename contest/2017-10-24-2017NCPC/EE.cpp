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

const int MAXN = 505;
const int MAXM = 505;

int h, w, x, y;

int level[MAXN][MAXM];
int high[MAXN][MAXM];
int vis[MAXN][MAXM];

struct NODE{
  int x, y, level;
  bool operator < (const NODE & T){
    return level < T.level;
  }
};

long long dijkstra(int sx, int sy){
  priority_queue<NODE> que;
  vis[sx][sy] = 1;
  que.push((NODE){sx, sy, level[sx][sy]});
  long long ans = 0;
  int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
  int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
  int dNum = sizeof(dx) / sizeof(int);

  while (!que.empty()) {
    NODE t = que.top();
    que.pop();
    if (vis[t.x][t.y]) continue;
    ans += max(0, 0 - t.level);
    for (int i = 0; i < dNum; ++i) {
      int tx = t.x + dx[i];
      int ty = t.y + dy[i];
      if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
      if (vis[tx][ty]) continue;
      vis[tx][ty] = 1;
      que.push((NODE){tx, ty, max(level[tx][ty], t.level)});
    }
  }
  return ans;
}

void work(){
  scanf("%d%d", &h, &w);
  for (int i = 1; i <= h; ++i){
    for (int j = 1; j <= w; ++j) {
      scanf("%d%d", level[i][j]);
    }
  }
  scanf("%d%d", &x, &y);
  
  cout << dijkstra(x, y) << endl;

}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif

  work();

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

