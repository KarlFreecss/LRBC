#include<bits/stdc++.h>
using namespace std;

const int MAXL = 10;

int table[] = {1, 9, 41, 109, 205, 325};

void work(){
  int n;
  scanf("%d", &n);
  if (n <= 5) {
    printf("%d\n", table[n]);
    return;
  }
  long long ans = n;
  __int128 N = n;
  N = (N - 4) * 120  + 28 * (N - 4) * (N - 5) / 2 + 205;
  long long ansF = N / 10000000000;
  long long ansL = N % 10000000000;
  if (ansF > 0) {
    printf("%lld", ansF);
    printf("%010lld\n", ansL);
  } else {
    printf("%lld\n", ansL);
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    printf("Case #%d: ", i);
    work(); 
  }
  return 0;
}
