#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxK = 63;
const int maxN = 500+13;

bitset<maxN> f[maxK][2][maxN];
int N,M;

int main()
{
  scanf("%d%d", &N, &M);
  rep(i, 0, maxK) {
    rep(j, 1, N+1) {
      f[i][0][j] = 0;
      f[i][1][j] = 0;
    }
  }
  rep(i, 1, M+1) {
    int st, ed, c;
    scanf("%d%d%d", &st, &ed, &c);
    f[0][c][st][ed] = 1;
  }
  rep(len, 1, maxK) {
    rep(tag, 0, 2) {
      rep(st, 1, N+1) {
        rep(ed, 1, N+1) {
          if(f[len-1][tag][st][ed])
            f[len][tag][st] |= f[len-1][tag^1][ed];
        }
      }
    }
  }
  ll ans = 0;
  rep(i,1,N+1) {
    if(f[60][0][1][i]) {
      ans = -1;
      break;
    }
  }
  if(ans == -1) {
    printf("%I64d\n", ans);
    return 0;
  } 

  bitset<maxN> temp,s;
  s[1]=1;
  int tag = 0;
  per(len, 0, 60) {
    temp = 0;
    rep(i, 1, N+1) {
      if(s[i]) temp = temp|f[len][tag][i];
    }
    if(temp.count() > 0) {
      s = temp;
      ans += 1ll<<len;
      tag^=1;
    }
  }
  if(ans > 1e18) ans = -1;
  printf("%I64d\n",ans);

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

