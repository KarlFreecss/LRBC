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
  //freopen(".in","r",stdin);
#endif
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int n;
    cin >> n;
    printf("Case #%d: %d\n", i, 2*n-1);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

