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

const ll Mod = 1e9 + 7;
const ll maxN = 2e5 + 13;

int T, N, M;
bool notprime[maxN];
ll p[maxN];
int indp = 0;
void initP () {
  memset(notprime, 0, sizeof(notprime));
  notprime[0] = notprime[1] = true;
  rep(i, 2, maxN) {
    if(!notprime[i]) {
      if(i > maxN/i) continue;
      for(ll j = i*i; j < maxN; j+=i) 
        notprime[j] = true;
    }
  }
  rep(i, 2, maxN) {
    if(notprime[i]) continue;
    p[++indp] = i;
  }
  return ;
}

ll r3, r2;

ll qp(ll a, ll b) {
  ll ret = 1ll;
  while(b) {
    if(b&1) ret = (ret * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  r2 = qp(2, Mod-2);
  r3 = qp(3, Mod-2);
  //cout << r2 << ' ' << r3 << endl;
  scanf("%d", &T);
  initP();
  rep(cas, 1, T+1) {
    scanf("%d%d", &N, &M);
    ll ans = 0ll;
    ll ln = (ll) N, lm = (ll)M;
    ans = ln;
//    cout << "2: " << endl;
    if(M >= 2) {
      rep(i, 1, indp + 1) {
        if(p[i] + 1 > N) break;
        ll ta = (lm - 1) * (ln - p[i]) % Mod;;
//        cout << p[i] << ' ' << ta << endl;
        ans = (ans + ta) % Mod;
      }
    }
//    cout << "3: " << endl;
    if(M >= 3) {
      rep(i, 2, indp + 1) {
        if(p[i] + 3 > N) break;
        if(notprime[p[i]+2]) continue;
        ll ta = (lm - 1) * (lm - 2) % Mod;;
        ta = (ta * (ln - p[i] - 2) ) % Mod;;
        ans = (ans + ta) % Mod;
  //      cout << p[i] << ' ' << ta << endl;
      }
    }
    //cout << ans << endl;
    if(M >= 4) {
      rep(i, 2, indp + 1) {
        if(p[i] + 5 > N) break;
        if(notprime[p[i]+4] || notprime[p[i]+2]) continue;
        ll ta = (lm - 1) * (lm - 2) % Mod;;
        ta = (ta * (lm - 3)) % Mod;
        ta = (ta * r2) % Mod;
        ta = (ta * r3) % Mod;
        ta = (ta * (ln - p[i] - 4) ) % Mod;;
        ans = (ans + ta) % Mod;
  //      cout << p[i] << ' ' << ta << endl;
      }
    }
    //cout << ans << endl;
    //printf("Case %d: ", cas);
    //printf("%lld\n", ans);
    cout << "Case " << cas << ": " << ans << endl;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

