#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxS=100+13;

int T,N;
char s[maxS];
ll num[maxS][maxS];

int main()
{

  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++) {
    scanf("%s",s+1);
    N=strlen(s+1);
    for(int i=1;i<=N;i++) {
      num[i][i]=s[i]-'0';
      for(int j=i+1;j<=N;j++) {
        num[i][j]=num[i][j-1]*10 + s[j]-'0';
      }
    }
    ll ans=-2e18;
    for(int jianhao=2;jianhao<=N-3;jianhao++) {
      ll qianbu=0ll;
      qianbu=max(num[1][1]+num[2][jianhao],num[1][jianhao-1]+num[jianhao][jianhao]);
      ll houbu=2e18;
      if(N-jianhao>=5) houbu=0ll;
      for(int chenghao=jianhao+1;chenghao<=N-2;chenghao++) {
        for(int chuhao=chenghao+1;chuhao<=N-1;chuhao++){
          ll tt;
          tt=num[jianhao+1][chenghao]*num[chenghao+1][chuhao]/num[chuhao+1][N];
          if(tt<houbu) houbu=tt;
        }
      }
      if(ans<qianbu-houbu) ans=qianbu-houbu;
    }
    printf("Case #%d: ",cas);
    printf("%lld\n",ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

