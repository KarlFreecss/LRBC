#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 3000+13;
const int inf = 0x7f7f7f7f;

int T,N,d[maxN];
int f[maxN];

int main() {
  scanf("%d", &T);
  rep(cas, 0, T) {
    scanf("%d", &N);
    rep(i, 1, N) {
      scanf("%d", &d[i]);
      if(i!=1) d[i]-=d[1];
    }
    rep(i, 0, N) f[i] = -inf;
    f[0] = d[1]*N;
    rep(i, 1, N-1) {
      rep(j,0,N) if(f[j]!=-inf) {
        if(i+j > N) break;
        f[j+i] = max(f[j]+d[i+1],f[j+i]);
      }
    }
    printf("%d\n", f[N-2]);
  }
  return 0;
}

