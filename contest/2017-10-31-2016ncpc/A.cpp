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

const int MAXN = 1e3+3;
const int MAXM = 1e3+3;
const int MAXP = 1e4+5;

int colMap[MAXN][MAXM];
int f[MAXN * MAXM];

struct OPT{
  int x1, y1, x2, y2;
}opt[MAXP];

int n, m, q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int dNum = sizeof(dx) / sizeof(int);

void color(int x, int y, int colMap[MAXN][MAXM], const int mark){
  queue<int> qx;
  queue<int> qy;
  qx.push(x);
  qy.push(y);
  colMap[x][y] = mark;
  while (!qx.empty()){
    int x = qx.front();
    int y = qy.front();
    qx.pop();
    qy.pop();
    for (int i = 0; i < dNum; ++i){
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
      if (colMap[tx][ty]) continue;
      colMap[tx][ty] = mark;
      qx.push(tx);
      qy.push(ty);
    }
  }
}

void show(){
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (colMap[i][j] > 0) 
        printf(" ");
      else printf("*"); 
    }puts("");
  }
}

int find(int x){
  if (f[x] != x) return f[x] = find(f[x]);
  return x;
}

int ans[MAXP];

int work(){
  if (scanf("%d%d%d", &n, &m, &q) != 3) return 0;

  memset(colMap, 0, sizeof(colMap));
  for (int i = 1; i <= q; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (y1 > y2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    opt[i] = (OPT){x1, y1, x2, y2};
    for (int x = x1; x <= x2; ++x) {
      for (int y = y1; y <= y2; ++y) {
        if (colMap[x][y] == 0) colMap[x][y] = -i;
      }
    }
  }
  int blockNum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (colMap[i][j] == 0) {
        ++blockNum;
        color(i, j, colMap, blockNum);
      }
    }
  }
 // cout << n << ' ' << m << ' ' << q << ' ' << blockNum << endl;
  
  for (int i = 1; i <= n * m; ++i) {
    f[i] = i;
  }
  
  int colId = blockNum;
  for (int i = q; i > 0; --i) {
    //show(); puts("");
    ans[i] = blockNum;
    int x1 = opt[i].x1;
    int y1 = opt[i].y1;
    int x2 = opt[i].x2;
    int y2 = opt[i].y2;
    for (int x = x1; x <= x2; ++x) {
      for (int y = y1; y <= y2; ++y) {
        if (colMap[x][y] == -i) {
          ++colId;
          ++blockNum;
          colMap[x][y] = colId;
          for (int k = 0; k < dNum; ++k) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if (colMap[tx][ty] < 0) continue;
            int fa = find(colMap[tx][ty]);
            int fb = find(colMap[x][y]);
            if (fa != fb) {
              --blockNum;
              f[fa] = fb;
            }  
          }
        }
      }
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << endl;
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("A.in","r",stdin);
#endif

  while (work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

