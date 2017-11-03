#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back
#define fi first 
#define se second 
#define mk(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int N, P;

int main() {
#ifndef ONLINE_JUDGE
  //freopen("F.in","r",stdin);
#endif
  scanf("%d%d", &N, &P);
  int ansk = -1;
  double ans = 1.0;

  ans *= (double) P;
  ans /= (double) (N+1);

  //cout << ans << endl;
  for(int i = 2; ; i++) {
    ll fz = (ll)i * (ll)(N + i - P);
    ll fm = (ll) (i-1) * (ll)(N+i);
    if(fz > fm) {
      ansk = i;
    } else break;
    ans *= fz;
    ans /= fm;
  }
  printf("%.11lf\n", ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

