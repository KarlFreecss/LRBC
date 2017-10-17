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

ll f[11][100][1024];
ll g[11][100][1024];// no leading 0
//  base len state isleading0

int B, Q;
ll L, R;
int dig[100];

ll solve(int B, ll xx) {
  if(xx == 0ll) return 0;
  int len = 0;
  int ans_state = 0;
  //cout << "xx = " << xx << endl;
  while(xx) {
    len ++;
    dig[len] = xx%B;
    xx /= B;
  }
  //cout << "dig : " << endl;
  //per(i, 1, len+1) cout << dig[i] << ' ';
  //cout << endl;
  ll ret = 0ll;
  int state = 0;
  rep(i , 0 , len) {
  //  cout << " f[B][i][0] = " << B << ' ' << i << ' ' << g[B][i][0] << endl;
    ret += g[B][i][0];
  }
  //cout << "init ret = " << ret << endl;
  for(int i = len; i >= 1; i--) {
  //  cout << "i = " << i << ' ' << dig[i] << endl;
    for(int j = (i==len); j < dig[i]; j++) {
  //    cout << i << ' ' << j << endl;
      int ts = state ^ (1<<j);
  //    cout << "ts = " << ts << endl;
      ret += f[B][i-1][ts];
  //    cout << "add: " << f[B][i-1][ts] << endl;
    }
    state ^= (1<<dig[i]);
  }
  if(state == 0) ret ++;
  //cout << "ret: " << ret << endl;
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-855E.in","r",stdin);
#endif
  for(int b = 2; b <= 10; b++) {
    int len = 0;
    ll temp = 1ll;while(temp <= 1e18) {temp *= b;len++;}
    f[b][0][0] = 1ll;
    for(int i = 0; i <= len; i++) {
      for(int state = 0; state < 1024; state++) {
        if(f[b][i][state] == 0) continue;
        rep(j, 0, b) {
          int ts = state ^ (1<<j);
          f[b][i+1][ts] += f[b][i][state];
          if(j != 0) 
            g[b][i+1][ts] += f[b][i][state];
        }
      }
    }
  }
  //cout << f[2][3][1] << endl;
  scanf("%d",&Q);
  rep(cas, 1, Q+1) {
    scanf("%d%I64d%I64d", &B, &L, &R);
    ll ans = solve(B, R);
    ans -= solve(B, L - 1);
    printf("%I64d\n", ans);
  //  cout << endl;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

