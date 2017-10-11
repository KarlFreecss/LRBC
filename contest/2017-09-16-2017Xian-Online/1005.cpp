#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const ll Mod = 1000000007;
const ll MO = 1000000007;
ll exp(ll b, ll r){
  if (r == 0) return 1;
  if (r == 1) return b;
  ll tmp = exp(b, r / 2);
  tmp = (tmp * tmp) % MO;
  if (r % 2) tmp *= b;
  return tmp % MO;
}

inline ll reverse(ll x){
  return exp(x, MO - 2) % MO;
}

ll N; 
ll ans;

inline ll calc(ll n , ll id) {
  n++;
  ll tk = 1ll << (id + 1) ;
  ll ret = 0;
  ret = n / tk * (tk / 2) ;
  if(n % tk > tk / 2)
    ret = ret + (n % tk) - (tk / 2);
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1005.in","r",stdin);
#endif
  while(scanf("%lld", &N) !=EOF) {
    N -- ;
    ll tt = 1ll;
    while(tt <= N) {
      tt <<= 1 ;
    }
    if(tt != N) tt >>= 1;
    ll k2 = tt; k2--;
    tt %= Mod;
    ans = 0ll;
    ans = tt * (tt - 1) % Mod;
    ans = (ans + Mod) % Mod;
    ans = ans * reverse(2) % Mod;
    ans = (ans + N) % Mod;
    //cout << calc(10 , 0) << endl;
    for(int i = 0; i < 63; i++) {
      ll tk = 1ll << i;
      if(tk >= N) break;
      if(tk & N) {
        ll ta = calc(N-1, i) - calc(k2, i);
        //cout << calc(N-1, i) << ' ' << calc(k2, i) << endl;
        ta = (N - 1 - k2) - ta;
        ta %= Mod;
        tk %= Mod;
        ans = (ans + ta * tk % Mod) % Mod;
        //cout << 1 << ' ' << tk << ' ' << ta << endl;
      } else {
        ll ta = calc(N-1, i) - calc(k2, i);
        //cout << calc(N-1, i) << ' ' << calc(k2, i) << endl;
        ta %= Mod;
        tk %= Mod;
        ans = (ans + ta * tk % Mod) % Mod;
        //cout << 0 << ' '  << tk << ' ' << ta << endl;
      }
      /*
      ll tk = 1ll<<i;
      ll tk2 = tk<<1;
      if(tk + k2 > N) break;
      if(tk  & N) {
        ll ta = (N-1)/tk2 - k2/tk2;
        ta = (N-1 - k2) - ta;
        ans = (ans + ta * tk2 % Mod) % Mod;
        cout << tk << ' ' << ta << endl;
      } else {
        ll ta = (N-1)/tk2 - k2/tk2;
        ans = (ans + ta * tk2 % Mod) % Mod;
        cout << tk << ' ' << ta << endl;
      }
      */
    }
    printf("%lld\n", ans);
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

