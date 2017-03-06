#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=100;

void ll2(long long x,int a[],int& la) {
  while(x) {
    a[la] = x & 1;
    x>>=1;
    la++;
  }
  return ;
}

ll l,r;
int x[maxN],y[maxN];
ll p2[maxN];

int main()
{
  p2[0]=1ll;
  for(int i=1;i<=64;i++)
    p2[i]=p2[i-1]<<1;
  int T;
  scanf("%d",&T);
  while(T--) {
    scanf("%lld%lld",&l,&r);
    if(l==r) {
      printf("%lld\n",l);
      continue;
    }
    int ix=0,iy=0;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    ll2(l,x,ix);
    ll2(r,y,iy);
    ll tl=l,tr=r;
    for(int i=0;i<ix-1;i++) {
      if(x[i] == 1) {
        x[i] = 0;
        tl-=p2[i];
      }
    }
    ll ans=r;
    for(int i=iy-1;i>=0;i--) {
      if(x[i] == 1 && y[i] == 0){
        ans += p2[i];
        continue;
      }
      if(y[i] == 0 && tl+p2[i]<=r){
        tl += p2[i];
        ans += p2[i];
      }
    }
    printf("%lld\n",ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

