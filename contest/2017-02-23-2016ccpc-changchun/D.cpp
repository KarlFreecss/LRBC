#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=31;

int T,N,a[maxN];
int b[maxN];
int ans[maxN];
int now=0;

bool check() {
  int ind=0;
  for(int i=1;i<=N;i++)
    if(a[i])
      b[++ind]=i;
  for(int i=3;i<=ind;i++)
    if(b[i]<b[i-1]+b[i-2])
      return false;
  return true;
}

void dfs(int n,int ta)
{
  if(ta>=now) return ;
  if(n==N+1)
  {
    if(ta<now && check())
      now=ta;
    return ;
  }
  dfs(n + 1, ta);
  a[n] = 0;
  dfs(n + 1, ta + 1);
  a[n] = n;
  return ;
}

int main()
{
  for(int i=1;i<=20;i++) {
    N=i;
    now=100;
    for(int j=1;j<=i;j++) 
      a[j] = j;
    dfs(1,0);
    ans[i]=now;
  }
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    scanf("%d",&N);
    printf("Case #%d: %d\n",cas,ans[N]);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

