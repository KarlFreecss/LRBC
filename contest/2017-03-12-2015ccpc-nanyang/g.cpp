#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 11;

char smap[MAXN][MAXN];
char use[MAXN][MAXN];
int vis[MAXN][MAXN];
int clear[MAXN][MAXN];

int qx[MAXN*MAXN];
int qy[MAXN*MAXN];
int head = 0, tail = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void print(char c[MAXN][MAXN]){
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      cout << c[i][j];
    }cout << endl;
  }
}

int BFS(char smap[MAXN][MAXN], int x, int y, char chess = 'o'){
  tail = 1;
  head = 0;
  qx[0] = x;
  qy[0] = y;
  vis[x][y] = 1;
  clear[x][y] = 1;
  int tot = 0;
  while (head < tail) {
    int x = qx[head];
    int y = qy[head++];
    for (int i = 0; i < 4; ++i) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      //cout << smap[tx][ty] << ' ';
      if (smap[tx][ty] == '.') ++tot;
      if (smap[tx][ty] == chess && !vis[tx][ty]) {
        qx[tail] = tx;
        qy[tail] = ty;
        vis[tx][ty] = 1;
        clear[tx][ty] = 1;
        tail++;
      }
    }
  }
  return tot == 0;
}


int check(char smap[MAXN][MAXN]){
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (vis[i][j] || smap[i][j] != 'o') continue;
      //cout << i << ' ' << j << endl;
      if (BFS(smap, i, j)) return 1;
    }   
  }
  return 0;
}


void clearChess(char smap[MAXN][MAXN], char chess) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (vis[i][j] || smap[i][j] != chess) continue;
      memset(clear, 0, sizeof(clear));
      if (BFS(smap, i, j, chess)) {
        for (int x = 1; x <= 9; ++x) {
          for (int y = 1; y <= 9; ++y) {
            if (clear[x][y]) smap[x][y] = '.';
          }
        } 
      };
    }
  }
}

void work(int cas){
  int ans = 0;
  memset(smap, ' ', sizeof(smap));
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      char c = getchar();
      if (c != '.' && c != 'x' && c != 'o') {
        --j;
        continue;
      }
      smap[i][j] = c;
    }
  }
  clearChess(smap, 'x');
  clearChess(smap, 'o');
  //print(smap);
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (smap[i][j] != '.') continue;
      memcpy(use, smap, sizeof(smap));
      use[i][j] = 'x';
    //cout << endl;
     // print(use);
      if (check(use)) {
        ++ans;
     //   cout << i << ' ' << j << endl;
     //   print(use);
      }
    }
  }

//  print(smap);
  //printf("%d\n", ans);
  int empty = 0;
  if (ans > 0) printf("Case #%d: %s\n", cas, "Can kill in one move!!!");
  else printf("Case #%d: %s\n", cas, "Can not kill in one move!!!");
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("g.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    work(i);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

