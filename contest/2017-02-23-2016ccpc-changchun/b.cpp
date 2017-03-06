#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;
const int MAXN = 9;

LL gcd(LL a, LL b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

int n;
int a[MAXN], b[MAXN];

void work(int ID){
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }

  LL son = b[n], mother = a[n];
  for (int i = n-1; i >= 1; --i) {
    son += a[i] * mother;
    LL tmp = son;
    son = mother * b[i];
    mother = tmp;
    tmp = gcd(son, mother);
    son /= tmp;
    mother /= tmp;
  }
  LL tmp = gcd(son, mother);
  son /= tmp;
  mother /= tmp;
 
  printf("Case #%d: %lld %lld\n", ID, son, mother); 
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    work(i);
  }
  return 0;
}
