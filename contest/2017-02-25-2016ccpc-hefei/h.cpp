#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXL = 2048;
const int MAXN = 1024;
int l[MAXL];

int N, M;
int a[MAXN];

void work(){
  memset(l, 0xff, sizeof(l));
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < N; ++i) {
    int xorV = 0;
    for (int j = i; j < N; ++j) {
      xorV ^= a[j];
      int len = j - i + 1;
      if (l[xorV] < len) l[xorV] = len;
    }
  }
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    int minV = 0x7fffffff;
    int ans = 0;
    for (int k = 0; k < 2048; ++k) {
      if (l[k] <= 0) continue;
      int v = abs(x - k);
      if (v < minV) {
        minV = v;
        ans = l[k];
      } else if (v == minV){
        ans = max(ans, l[k]);
      }
    }
    printf("%d\n", ans);
  }
  puts("");
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }
  return 0;
}
