#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int LID[MAXN], f[MAXN][MAXN];

void work() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i ++) {
    LID[i] = N + 1;
  }
  int x, y;
  for (int i = 1; i <= M; i ++) {
    scanf("%d%d", &x, &y);
    LID[y] = min(LID[y], x);
  }
  for (int i = N - 1; i >= 1; i --) {
    LID[i] = min(LID[i], LID[i + 1]);
  }
  for (int j = 0; j <= K; j ++) {
    f[0][j] = 0;
  }
  int res = 0;
  for (int i = 1; i <= N; i ++) {
    f[i][0] = f[i - 1][0];
    for (int j = 1; j <= K; j ++) {
      if (LID[i] <= i)
	f[i][j] = max(f[i - 1][j], f[LID[i] - 1][j - 1] + (i - LID[i] + 1));
      else
	f[i][j] = f[i - 1][j];
      res = max(res, f[i][j]);
//      cout << i << " " << j << " " << f[i][j] << endl;
    }
  }
//  cout << LID[100] << endl;
  printf("%d\n", res);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t ++) {
    printf("Case #%d: ", t);
    work();
  }
  return 0;
}
