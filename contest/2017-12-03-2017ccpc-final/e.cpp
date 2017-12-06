#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int table[MAXN];

int getFuck(int i){
  for (int k = 0; k < 10000; ++k) {
    if (i * 11 <= k * 10) return k;
  }
  return 0;
}

int work(){
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ans = ans + getFuck(a);//(int)ceil(a * 1.1);
  }
  return ans;
}

int main(){
 // for (int i = 0; i <= 100; ++i) {
 //   table[i] = getFuck(i);
 //   printf("%f %d\n", i * 1.1, table[i]);
 // }
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    printf("Case #%d: %d\n", i, work()); 
  }
  return 0;
}
