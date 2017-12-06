#include<bits/stdc++.h>
using namespace std;

double work(){
  int n;
  scanf("%d", &n);
  return n - 1.;
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    printf("Case #%d: %.15f\n", i, work()); 
  }
  return 0;
}
