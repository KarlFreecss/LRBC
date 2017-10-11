#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 2000+13;

int p[maxN],v[maxN];
int N,M,Q;
int main() {
#ifndef ONLINE_JUDGE
  freopen("bj001.in","r",stdin);
#endif
  while(scanf("%d%d", &N ,&M) != EOF) {
    rep(i , 1 , N+1) scanf("%d", &p[i]);
    memset(v,0,sizeof(v));
    scanf("%d", &Q);
    rep(i , 1 , Q+1) {
      int tt ;
      scanf("%d", &tt);
      v[tt+1] = 1;
    }
    int ans = maxN * maxN;
    int ans1, ans2;
    for(int i = 1; i <= N; i++) {
      if(v[i]) continue;
      int ta = p[i];
      int tt = 1;
      int tmin = maxN;
      int ti = -1;
      for(int j = i+1; j <= N; j++) {
        if(v[j]) continue;
        tt++;
        if(tt > M) break;
        if(p[j] < tmin) {
          tmin = p[j];
          ti = j;
        }
      }
      if(ti == -1) continue;
      if(tt < M) break;
      ta += tmin;
      if(ta < ans) {
        ans = ta;
        ans1 = i;
        ans2 = ti;
      }
    }
    printf("%d %d\n", ans1-1, ans2-1);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

