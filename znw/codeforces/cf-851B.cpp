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

ll sqr(ll x) {
  return x*x;
}

ll x[10], y[10];
ll dis(int a, int b) {
  ll ret = sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
  return ret
}

bool check() {
  ll dx1 = x[0] - x[1];
  ll dy1 = y[0] - y[1];
  ll dx2 = x[2] - x[1];
  ll dy2 = y[2] - y[1];
  return (dx1 * dy2 - dx2 * dy1) == 0ll;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-851B.in","r",stdin);
#endif
  rep(i, 0, 3) cin >> x[i] >> y[i];
  if((dis(1,2) == dis(0,1)) && !check()) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

