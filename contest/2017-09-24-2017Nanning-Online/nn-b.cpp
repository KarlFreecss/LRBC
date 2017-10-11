#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100+13;

int N;
int xx[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("nn-b.in","r",stdin);
#endif
  while(scanf("%d", &N) != EOF) {
    if(N == 0) break;
    memset(xx,0,sizeof(xx));
    int st, ed, k;
    rep(i, 1, N+1) {
      scanf("%d%d%d", &st, &ed ,&k);
      xx[st] += k; xx[ed] -= k;
    }
    int ta = 0,ans = 0 ;
    for(int i = 1; i < maxN; i++) {
      ta += xx[i];
      ans = max(ans, ta);
    }
    printf("%d\n",ans);
  }
  printf("*\n");

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

