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

const int maxN = 300000+13;

int a[maxN], N;
ll f[maxN][40];

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-853C.in","r",stdin);
#endif
  scanf("%d", &N);
  rep(i, 1, N+1) scanf("%d", &a[i]);
  memset(f, 0x3f, sizeof(f));
  //cout << f[0][0] << endl;
  f[0][0] = 0;
  rep(i, 1, N+1) {
    int ta = a[i] / 1000;
    rep(j, 0, 40) {
      f[i][j+ta] = min(f[i][j+ta], f[i-1][j] + a[i]);
      if(j >= ta * 10) 
        f[i][j-ta * 10] = min(f[i][j-ta * 10], f[i-1][j]);
      else 
        f[i][0] = min(f[i][0], f[i-1][j] + (a[i] - j * 100));
    }
  }
  ll ans = f[N+1][0];
  rep(i, 0, 40) {
    //cout << i << ' ' << f[N][i] << endl;
    if(ans > f[N][i]) ans = f[N][i];
  }
  cout << ans <<endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

