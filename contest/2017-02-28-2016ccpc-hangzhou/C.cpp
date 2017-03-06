#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=1e5+13;

ll a[maxN],ans[maxN];
ll cal(ll a,ll b) {
  if(a%b==0) return a/b;
  return a/b+1ll;
}

int main()
{
  int T,N;
  int cas=1;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&N);
    rep(i,1,N+1) {
      scanf("%lld",&a[i]);
    }
    a[0]=0ll;
    ans[N]=1ll;
    for(int i=N-1;i>=1;i--) {
      ans[i]=cal(ans[i+1]*(a[i]-a[i-1]),a[i+1]-a[i]);
    }
    ll sum=0ll;
    rep(i,1,N+1) 
      sum+=ans[i];
    printf("Case #%d: ",cas);
    printf("%lld\n",sum);
    cas++;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

