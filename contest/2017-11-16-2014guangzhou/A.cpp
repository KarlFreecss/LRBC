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

const int maxN = 50000+13;

int a[maxN], b[maxN], v[maxN];

int work() {
  int N;
  scanf("%d", &N);
  if(N == 0) return 0;
  int ind = 0;
  for(int i = 1; i <= N; i++) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    ll lx = x; 
    ll ly = y;
    if(t == 1) {
      ind++;
      v[ind] = 0;
      a[ind] = x;
      b[ind] = y;
    } else if(t == -1) {
      for(int i = 1; i <= ind; i++) if(!v[i])
        if(a[i] == x && b[i] == y) {
          v[i] = 1;
          break;
        }
    } else {
      ll ans = (ll)(-2e18) , ta;
      for(int i = 1; i <= ind; i++) if(!v[i]) {
        ta = lx * (ll)a[i] + ly * (ll) b[i];
        if(ta > ans) ans = ta;
      }
      printf("%lld\n", ans);
    }
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  while(work());

  return 0;
}

