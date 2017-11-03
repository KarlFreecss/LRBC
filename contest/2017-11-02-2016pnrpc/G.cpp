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

const int MAXN = 50;
const int MAXM = 50;

char wMap[MAXN][MAXM];
int n, m;
int vis[MAXN][MAXM];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int dNum = sizeof(dx) / sizeof(int);

int isNearLand(char wMap[MAXN][MAXM], int x, int y){
  for (int i = 0; i < dNum; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    //if (tx <= 0 || tx > n || ty <= 0 || ty > m) continue;
    if (wMap[tx][ty] == 'L') return 1;
  }
  return 0;
}

int BFS(char wMap[MAXN][MAXM]){
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (wMap[i][j] != 'L') continue;
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        queue<int> qx;
        queue<int> qy;
        qx.push(i);
        qy.push(j);
        ++ans;

        while (!qx.empty()) {
          int x = qx.front();
          int y = qy.front();
          qx.pop();
          qy.pop();
          for (int k = 0; k < 4; ++k) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (wMap[tx][ty] != 'L') continue;
            if (vis[tx][ty]) continue;
            vis[tx][ty] = 1;
            qx.push(tx);
            qy.push(ty);
          }
        }

      }
    }
    return ans;
}

vector<int> net[MAXN * MAXM];
int linker[MAXN * MAXM];
int used[MAXN * MAXM];

int find(int x){
  for (int i = 0; i < net[x].size(); ++i) {
    int y = net[x][i];
    if (!used[y]) {
      used[y] = 1;
      if (linker[y] == -1 || find(linker[y])) {
        linker[y] = x;
  //      cout << x << " => " << y << endl;
        return true;
      }
    }
  }
  return false;
}

int work(){
  if (scanf("%d%d", &n, &m) != 2) return 0;
  memset(wMap, 'W', sizeof(wMap));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      c = getchar();
      if (c != 'W' && c != 'L' && c != 'C') {
        --j;
        continue;
      }
      wMap[i][j] = c;
   }
  }
  int ans = BFS(wMap);
  int uncertainCloud = 0;
  queue<int> cloud;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (wMap[i][j] != 'C') continue;
      if (isNearLand(wMap, i, j)) continue;
      uncertainCloud++;
      if ((i ^ j)&1) cloud.push(i * MAXM + j);
      for (int k = 0; k < 4; ++k) {
        int tx = i + dx[k];
        int ty = j + dy[k];
        if (wMap[tx][ty] != 'C') continue;
        if (isNearLand(wMap, tx, ty)) continue;
        net[i * MAXM + j].push_back(tx * MAXM + ty);
       // cout << i << ' ' << j << " => " << tx << ' ' << ty << endl;
      }
    }
  }
  int findCound = 0;
  memset(linker, 0xff, sizeof(linker));
  while (!cloud.empty()){
    int x = cloud.front();
    cloud.pop();
   // cout << " x = " << x << endl;
    memset(used, 0, sizeof(used));
    if (find(x)) {
      findCound++;
    }
  }
  cout << ans + uncertainCloud - findCound << endl;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

