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

const int maxN = 1000000+13;

ll s[maxN];
int N,R;

void work() {
  scanf("%d", &R);
  memset(s,0,sizeof(s));
  scanf("%d", &N);
  ll alls = 0ll;
  for(int i = 1; i <= N; i++) {
    int t, l, w, h;
    scanf("%d%d%d%d", &l, &t, &w, &h);
    ll r = min(l + w, R);
    ll d = max(t - h, 0);
    alls += (ll)(r - l) * (t - d);
    s[l] += (ll)(t - d);
    s[r] -= (ll)(t - d);
  }
  if(alls == 0ll) {
    printf("%d\n", R);
    return ;
  }
  for(int i = 1; i <= R; i++) {
    s[i] = s[i-1] + s[i];
  }
  ll ta = 0ll;
  int ans = R;
  ll diff = (ll)R*R;
  for(int i = 1; i <= R; i++) {
    ta += s[i-1];
    if(ta >= alls - ta) {
      ll td = ta * 2 - alls;
      if(td >= 0 && td <= diff) {
        ans = i;
        diff = td;
      }
    }
  }
  printf("%d\n", ans);
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
  //freopen("A.out","w",stdout);
#endif
  int T; scanf("%d", &T);
  for(int i = 1; i <= T; i++) 
    work();

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

