#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int MAXN = 40;
int m[MAXN][MAXN];
int n;

int check_(int tx, int ty, int dIndex){
    for (int i = -1; i < 2; ++i) {
      int ttx = tx + dx[(dIndex + i + 4) % 4];
      int tty = ty + dy[(dIndex + i + 4) % 4];
      if (ttx < 0 || tty < 0 || ttx >= n || tty >= n) continue;
      if (m[ttx][tty] == 1) return false;  
    }
    return true;
}

void dfs(int m[MAXN][MAXN], int dIndex, int x, int y){
  m[x][y] = 1;
  int count = 0;
  int tx = -1, ty = -1;
  while (true) {
    tx = x + dx[dIndex];
    ty = y + dy[dIndex];
    ++count;
    if (count > 4) return;
    if (tx < 0 || ty < 0 || tx >= n || ty >= n || m[tx][ty]) {
	++dIndex;
	dIndex %= 4;
       continue;
    }
    if (check_(tx, ty, dIndex)) break;
    ++dIndex;
    dIndex %= 4;   
  }
  assert(tx != -1 && ty != -1); 
  dfs(m, dIndex, tx, ty);
}

void work(){
  scanf("%d", &n);

  int dindex = 0;
  memset(m, 0, sizeof(m));
  
  dfs(m, 0, 0, 0);  

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%c", m[i][j]?'#':' ');
    } printf("\n");
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }
}
