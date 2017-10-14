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

const int MAXN = 60;

int f[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif
  f[1][1] = 1;
 // cout << "1:" << '\t'  << endl;
  rep(i, 2, MAXN) {
    f[i][1] = f[i][i] = 1;
    rep(j, 2, i) {
      f[i][j] = f[i - 1][j - 1] ^ f[i - 1][j];
    }
    cout << i << ':' << '\t';
    rep(k, 1, MAXN-i) cout << " ";
    rep(j, 1, i + 1)
      cout << f[i][j] << " ";
    cout << endl;
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

