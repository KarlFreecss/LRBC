#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int mo = 1e8 + 7;

const int MAXN = 10100;
char num[MAXN];
int s[MAXN];
int N;

int f[MAXN][3][3];

void clear(int x){
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      f[x][i][j] = 0;
    }
  }
}

void solve(){
  scanf("%s", num);
  int l = strlen(num);
  for (int i = 0; i < l; ++i) {
    s[i+1] = num[i] - '0';
  }
  clear(0);
  clear(1);
  for (int j = 0; j < 3; ++j) {
    if (j > s[1]) break;
    f[1][j][0] = 1;
    if (j == 1) ++f[1][j][0];
  }
  //for (int i = 0; i < 3; ++i) {
  //  printf("%d ", f[1][i][0]);
  //}puts("");


  for (int i = 2; i <= l; ++i) {
    clear(i);
    for (int j = 0; j < 3; ++j) {
      if (s[i] < j) continue;
      for (int k = 0; k < 3; ++k) {
        int l = s[i-1] - j - k;
        if (l > 2 || l < 0) continue;
        int tmp = f[i-1][k][l];
        if (j == 1) tmp += tmp;
        f[i][j][k] = (f[i][j][k] + tmp) % mo;
      } 
    }
  }


  int sum = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (s[l] == i + j) sum += f[l][i][j];
    }
  }
  printf("%d\n", sum % mo);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    solve();
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

