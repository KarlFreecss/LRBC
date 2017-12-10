#include<bits/stdc++.h>
using namespace std;

void work() {
  int X, Y, K;
  scanf("%d%d%d", &X, &Y, &K);
  if (X > Y) {
    printf("%d\n", K);
  } else {
    int L = 0, R = K, res = 0;
    while (L <= R) {
      int win = (L + R) / 2;
      int lose = K - win;
      int tmp = X * 11 * lose - Y * 11 * win + X * 9 * win;
      if (tmp >= 0) {
	L = win + 1;
	res = max(res, win);
      } else {
	R = win - 1;
      }
    }
    printf("%d\n", res);
  }
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
