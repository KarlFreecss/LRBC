#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=10000+13;

int T,N,K;
int a[maxN];
int res[maxN];

int main()
{

  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++) {
    scanf("%d%d",&N,&K);
    rep(i,1,1+N) a[i]=0;
    rep(i,1,1+K) {
      int tt = 2 * K - (i - 1) * 2;
      res[i] = tt;
      a[tt] = 1; 
    }
    int ind=K;
    rep(i,1,N+1) 
      if(a[i]==0)
       res[++ind]=i;
    printf("Case #%d: ",cas);
    rep(i,1,N)
      printf("%d ", res[i]);
    printf("%d\n", res[N]);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

