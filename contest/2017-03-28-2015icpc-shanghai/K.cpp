#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100000+13;

inline ll sqr(ll x) {
  return x*x;
}
char s[maxN];
ll c[maxN];
ll ans = 0;



int main() {
  int T;
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    printf("Case #%d: ", cas);
    scanf("%s", s);
    int N = strlen(s);
    if(N == 1) {
      printf("1\n");
      continue;
    }
    memset(c,0,sizeof(c));
    c[0] = 1;
    rep(i, 1, N) {
      if(s[i] != s[i-1]) {
        c[i] = 1;
        continue;
      } else {
        c[i] = c[i-1] + 1;
      }
    }
    ans = 0ll;
    per(i, 0, N-1) {
      if(s[i] == s[i+1]) {
        c[i] = c[i+1];
      } else {
        ans += c[i]*c[i];
      }
    }
    ans += c[N-1]*c[N-1];
    ll preans = ans;
    //cout << ans << endl;
    //rep(i,0,N) cout << c[i];
    //cout << endl;
    rep(i,1,N-1) {
      if(s[i+1] != s[i-1]) {
        ll ta = preans - sqr(c[i-1]) - sqr(c[i+1]);
        ta += sqr(c[i-1]-1) + sqr(c[i+1]+1);
        if(ta > ans) ans = ta;
        ta = preans - sqr(c[i-1]) - sqr(c[i+1]);
        ta += sqr(c[i-1]+1) + sqr(c[i+1]-1);
        if(ta > ans) ans = ta;
      } 
      if(s[i+1] == s[i-1] && s[i+1]!=s[i]) {
        ll ta = preans - 1 - sqr(c[i-1]) - sqr(c[i+1]);
        ta += sqr(c[i-1]+c[i+1]+1);
        if(ta > ans) ans = ta;
      }
    }
    if(s[0] != s[1]) {
      ll ta = preans - 1 - c[1]*c[1];
      ta += sqr(c[1]+1);
      if(ta > ans) ans = ta;
    }
    if(s[N-1] != s[N-2]) {
      ll ta = preans -1 - c[N-2]*c[N-2];
      ta += sqr(c[N-2]+1);
      if(ta > ans) ans = ta;
    }
    cout << ans << endl;
  }
  return 0;
}

