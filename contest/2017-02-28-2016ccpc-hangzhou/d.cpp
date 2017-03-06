#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 10;
const int MAXK = 10;

int x, K;
int ans;
int table[MAXN][MAXK];

void init(){
  for (int i = 0; i < MAXN; ++i) 
    table[i][0] = 1;
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 1; j < MAXK; ++j) {
      table[i][j] = table[i][j-1] * i;
    } 
  }
}


int num[MAXN];
int tmp[MAXN];

int check(ll y){
  if (y < 0) return 0;
  //if (num[3] != 2) return 0;
 // for (int i = 0; i < MAXN; ++i) {
 //   printf("%d ", num[i]); 
 // }puts("");
 // printf("%lld\n", y);

  memcpy(tmp, num, sizeof(tmp));
 // for (int i = 0; i < MAXN; ++i) {
 //   tmp[i] = num[i];
 // }
  
  //ll tt = y;

  if (y == 0) {
    tmp[0]--;
    for (int i = 0; i < MAXN; ++i) {
      if (tmp[i] != 0) return 0;
    }
    return 1;
  }
  
  while (y != 0) {
    int t = y % 10;
    y /= 10;
    //cout << t << endl;
    tmp[t]--;
  }
//  for (int i = 0; i < MAXN; ++i) {
//    printf("%d ", num[i]); 
//  }puts("");

  for (int i = 0; i < MAXN; ++i) {
    if (tmp[i] != 0) return 0;
  }
  
 // printf("%lld\n", tt);
 // for (int i = 0; i < 10; ++i) {
 //   printf("%d ", num[i]);
 // } 
 // puts("");
  return 1;
}

void search(int n, int l, ll s){
  //cout << n << ' ' << l << ' ' << s << ' ' << s - x << endl;
  //cout << ans << endl;
  if (l == 0) {
   // cout << s << endl;
    if (check(s - x)) {
      ++ans;
    }
    return;
  }
  if (n == 0) {
    num[n] = l;
    //cout << n << ' ' << s << endl;
    if (check(s - x)) {
      ++ans;
    }
    num[n] = 0;
    return;
  }
  if (s + 1ll * l * table[n][K] < x) {
    return ;
  }
  for (int k = 0; k <= l; ++k) {
    num[n] = k;
    //cout << "L " << K << ' ' << n << ' ' << s << ' ' << table[n][K] << endl;
    search(n-1, l-k, s + 1ll*k*table[n][K]);
    num[n] = 0;
  }
}

namespace CHECK{
  int cal(int y, int K){
    if (y == 0) {
      return 0;
    }
    int t = y;
    int s = 0;
    while (t) {
      int k = t % 10;
      s += table[k][K];
      t /= 10;
    }
    return s - y;
  }
  
  int work(int x, int K){
    int res = 0;
    for (int t = 0; t < 1000000; ++t) {
      if (x == cal(t, K)) ++res;
    }
    return res;
  }
}

void work(int id){
 // scanf("%d%d", &x, &K);
  x = rand()%10000000 + 123;
  K = rand()%3 + 1;
  ans = 0;
  for (int dig = K + 7; dig; --dig) {
    //cout << "begin   " << dig << endl;
    search(9, dig, 0);
  }
  if (ans != CHECK::work(x, K)) {
    printf("%d %d\n", x, K);
    while(1);
  }
  printf("Case #%d: %d\n", id, ans);
}

int main()
{
  //srand(time(0));
  int T;
  scanf("%d", &T);
  init();
  //cout << table[9][9] << endl;
  for (int i = 1; i <= T; ++i) {
    work(i);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}




