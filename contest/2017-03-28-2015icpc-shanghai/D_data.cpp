#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
 // freopen(".in","r",stdin);
#endif
  srand(time(0));

  int T = 5;
  cout << T << endl;
  for (int i = 1; i <= T; ++i){ 
  int n = rand()%10 + 1;
  int m = rand()%10 + 1;
  cout << n << ' ' << m << endl;

  for (int i = 1; i < n; ++i) {
    cout << rand()%10 + 1 << ' ';
  }cout << endl;

  for (int i = 1; i <= m; ++i) {
    int x = rand()%n + 1;
    int y = rand()%15 + 1;
    int z = rand()%2;
    cout << x << ' ' << y << ' '<< z <<  endl;
  }
  }

  return 0;
}

