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
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    scanf("%lld%lld",&l,&r);
    if(l==r) {
      printf("%lld\n",l);
      continue;
    }
    int ix=0,iy=0;
    ll2(l,x,ix);
    ll2(r,y,iy);
    ll tl=l,tr=r;
    ll ans = 0;
    per(i, 0, iy) {
      if (x[i] == 1 && y[i] == 1)
        ans += p2[i];
      else if (x[i] == 0 && y[i] == 1) {
        ans += p2[i] + p2[i] - 1;
        break;
      }
    }
    printf("%lld\n",ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


