#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 200000+13;

struct les {
  int l,r;
};

bool hou(les& a,les& b) {
  return a.l < b.l;
}
bool qian(les& a,les& b) {
  return a.r<b.r;
}

les c[maxN],p[maxN];
int N,M;

int main()
{
  scanf("%d",&N);
  rep(i,1,N+1) {
    scanf("%d%d",&c[i].l,&c[i].r);
  }
  scanf("%d",&M);
  rep(i,1,M+1) {
    scanf("%d%d",&p[i].l,&p[i].r);
  }
  sort(c+1,c+1+N,qian);
  sort(p+1,p+1+M,hou);
  int ans = 0;
  ans = max(ans,p[M].l-c[1].r);
  sort(c+1,c+1+N,hou);
  sort(p+1,p+1+M,qian);
  ans = max(ans,c[N].l-p[1].r);
  printf("%d\n",ans);

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

