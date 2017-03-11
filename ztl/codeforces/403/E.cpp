#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i ++)
#define per(i,a,b) for (int i = b-1; i >= a; i --)

const int MAXN = 2e5 + 100;

int n, m, k, maxstep, stepN;
vector<int> v[MAXN];
int step[MAXN * 2];
bool visited[MAXN];

void dfs(int x, int faX) {
  int y;
  visited[x] = true;
  step[stepN ++] = x;
  rep(i, 0, v[x].size()) {
    y = v[x][i];
    if (!visited[y]) {
      dfs(y, x);
      step[stepN ++] = x;
    }
  }
  return;
}
int main() {
  memset(visited, 0, sizeof(visited));
  int x, y, res, nowStep;
//  freopen("E.in", "r", stdin);
  scanf("%d%d%d", &n, &m, &k);
  maxstep = (2 * n - 1) / k + 1;
  rep(i, 0, m) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  stepN = 1;
  dfs(1, 1);
  nowStep = 1;
  rep(i, 0, k) {
    res = min(stepN - nowStep, maxstep);
    if (res != 0) {
      printf("%d", res);
      rep(i, 0, res) {
        printf(" %d", step[nowStep]);
        nowStep ++;
      }
      printf("\n");
    } else {
      printf("1 1\n"); 
    }
  }
  return 0;
}
