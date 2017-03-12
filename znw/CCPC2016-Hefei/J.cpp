#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define show(a) cout << #a << "=" << (a) << '\t'; 

typedef long long ll;
typedef unsigned long long ull;

const int maxN=666+13;

ll c[maxN][maxN];
ll g[maxN][maxN];
ll f[maxN][maxN];
ll yushu[maxN][maxN];
ll N,M,P;

ll ff(ll x, ll y, ll& c){
  ll ret = 0;
  while(y > 0) {
    ret++;
    int t = x % y;
    x = y;
    y = t;
  }
  c = ret;
  return ret * x * x;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
 // freopen("J.out","w",stdout);
#endif
  for(int i = 1; i <= 666; i++){
    for(int j = 1; j <= 666; j++){
      f[i][j] = ff(i, j, c[i][j]);
      yushu[i][j] = i * j % f[i][j];
      g[i][j] = __gcd(i,j);
    }
  }
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%lld%lld%lld",&N,&M,&P);
    ll ans=0ll;
    //cout << ans << endl;
    for(int j = 1; j <= M; j++) {
      for(int i = 1; i <= j && i <= N; i++) {
        ll tf = f[i][j];
        ll tc = c[i][j];
        ll tg = g[i][j];
        cout<<i<<' '<<j<<endl;
        show(tf);
        show(tc);
        show(tg);
        cout<<endl;
        for(int k=0;k < tc; k++) {
          if(i + k * j > N) break;
          ll tn= (N - (i + k * j)) / (tc * j) + 1;
          ll ta0 = (i + k * j) * j / tf;
          ll gc = tc * j * j / tf;
          ans = ((ans + ta0 * tn) % P + tn* (tn- 1) /2 % P * gc % P) % P;
        }
      }
    }
    printf("%lld\n",ans);
  }

  return 0;
}
