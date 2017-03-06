#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=666+13;

ll c[maxN][maxN];
ll gcd[maxN][maxN];
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

ll cal(int n,int rk,int pe)
{
  ll ret=n/pe;
  if(rk<=n%pe) ret++;
  return ret;
}

ll ex_gcd(ll a, ll b,ll& x,ll& y){
  if(a==0 && b==0) return -1;
  if(b==0){x=1;y=0;return a;}
  ll d=ex_gcd(b,a%b,y,x);
  y-=a/b*x;
  return d;
}

ll inv(ll a,ll n)
{
  ll x,y;
  ll d=ex_gcd(a,n,x,y);
  return (x%n+n)%n;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
 // freopen("J.out","w",stdout);
#endif
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%lld%lld%lld",&N,&M,&P);
    ll ans=0ll;
    if(N<M) swap(N,M);
    for(int i=1;i<=M;i++) {
      for(int j=1;j<=3*M;j++) {
        f[i][j]=ff(i,j,c[i][j]);
        yushu[i][j]=i*j%f[i][j];
        if(j<=M) ans+=(i*j)/f[i][j];
      }
    }
    cout<<ans<<endl;
    ans%=P;
    for(int i=1;i<=M;i++) {
      for(int j=i+1;j<=i+i;j++) {
        ll tc=c[i][j];
        ll tf=f[i][j];
        ll tsum=0;
        ll tn=0;
        tn=cal(N-M,j-i,tc);
        tsum=(tsum + tf * tn % P) % P;
        ll gc=yushu[i][j]-yushu[i][j+M]+f[i][j];
        gc%=f[i][j];
        if(gc!=0) {
          tn=cal(tn,tn-1,tc);
          tn = tn* (tn - 1) / 2;
          tsum = ((tsum - gc % P * tn % P) + P) % P;
        }
        ans= (ans+ (tsum * inv(f[i][j], P) % P)) % P;
      }
    }
    printf("%lld\n",ans);
  }
/*
  int ans=0;
  rep(i, 1, 10 + 1){
    cout<<i<<":"<<endl;
    rep(j, 1, i*10 + 1){
      cout<<i<<' '<<j<<'\t';
      ll tc;
      int fij=ff(i,j,tc);
      cout << "c=" << tc<< '\t';
      ll x,y;
      cout << "gcd=" << ex_gcd(i,j,x,y) << '\t';
      cout<<"f(i,j)="<<fij<<'\t';
      cout<<"i*j/f(i,j)="<<i*j/fij<<'\t';
      cout<<"i*j%f(i,j)="<<i*j%fij<<endl; 
      ans+=(i*j)/fij;
    }
    cout<<endl;
    cout<<endl;
  }
  cout<<ans<<endl;
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  */

  return 0;
}
