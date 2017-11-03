#include<bits/stdc++.h>
using namespace std;

map<int, int> dic;

int main(){
  for (int i = 0; i < 0x100; ++i) {
    dic[0xff & ((i << 1) ^ i)] = i;
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    printf("%d%c", dic[x], i+1==n?'\n':' ');
  }
  return 0;
}
