#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

int ans = 0;

void dfs(int x, int y){
  if (x < y) swap(x, y);
  if (x % (y+1) == 0) {
    ++ans;
    dfs(x/(y+1), y);
  }
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen(".in","r",stdin);
#endif

  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int x, y;
    ans = 1;
    cin >> x >> y;
    int z = gcd(x, y);
    x /= z;
    y /= z;

    dfs(x, y);
    printf("Case #%d: %d\n", i, ans);
  }

  return 0;
}

