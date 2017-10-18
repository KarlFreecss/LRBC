#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back
#define fi first 
#define se second 
#define mk(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline int readChar() {
  int c = getchar();
  while(c <= 32) c = getchar();
  return c;
}
inline double readDouble() {
  int c = readChar();
  double x = 0;
  while('0' <= c && c <= '9') 
    x = x*10 + c - '0', c = getchar();
  if(c == '.') {
    c = getchar();
    double coef = 1;
    while('0' <= c && c <= '9') 
      x += (c - '0') * (coef *= 1e-1), c = getchar();
  }
  return x;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("G.in","r",stdin);
#endif

  double money = readDouble();
  int n;
  scanf("%d", &n);
  double last = readDouble();
  double minC = last;
  double profit = -9999999999999;
  for (int i = 1; i < n; ++i) {
    double curr = readDouble();
    profit = max({profit, (curr - last) * money / last, money / minC * curr - money});
    last = curr;
    minC = min(minC, curr);
  }
  printf("%.2lf\n", profit);
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

