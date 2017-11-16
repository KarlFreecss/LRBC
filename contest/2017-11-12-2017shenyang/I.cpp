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

const ll Mod = 1e8;

__int128 ans;
int T;

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif
  cin >> T;
  for(int i = 0; i < T; i++) {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ans = (__int128)a;
    ans += (__int128)b;
    ans += (__int128)c;
    ans += (__int128)d;
    ll ans1 = ans / Mod;
    ll ans2 = ans % Mod;
    if(ans1 > 0) {
      printf("%lld%08lld\n", ans1, ans2);
    } else {
      printf("%lld\n", ans2);
    }
  }

  
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

