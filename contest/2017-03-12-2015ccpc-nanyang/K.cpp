#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 4000+13;
const long long MAXVAL = 1e16;

int T;
long long f[maxN], g[maxN];
long long t[maxN], p[maxN];
long long sumT[maxN], sumP[maxN];
long long N, res;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("K.in","r",stdin);
#endif
  long long sum, sumDis, addLen;

  scanf("%d",&T);
  for(int cas = 1; cas <= T; cas++) {
    scanf("%lld", &N);
    sumT[0] = sumP[0] = 0;
    f[0] = g[0] = 0;
    rep(i, 1, 1 + N) {
      scanf("%lld%lld", &t[i], &p[i]);
      sumT[i] = sumT[i - 1] + t[i];
      sumP[i] = sumP[i - 1] + p[i];
      f[i] = f[i - 1] + sumP[i];
      g[i] = g[i - 1] + sumT[i];
    }
    rep(i, 1, N) {
      sumDis = 0;
      rep(k, 1, N - i) {
        int j = i + k;
        addLen = (k + 1) / 2;
        sumDis += sumT[j] - sumT[j - addLen];
        g[j] = min(g[j], f[i] + sumDis);
      }
      sumDis = 0;
      rep(k, 1, N - i) {
        int j = i + k;
        addLen = (k + 1) / 2;
        sumDis += sumP[j] - sumP[j - addLen];
        f[j] = min(f[j], g[i] + sumDis);
      }
    }
    res = MAXVAL;
    sumDis = sum = 0;
    per(i, 2, N + 1) {
      sum += t[i];
      sumDis += sum;
      res = min(res, sumDis + f[i - 1]);
    }
    sumDis = sum = 0;
    per(i, 2, N + 1) {
      sum += p[i];
      sumDis += sum;
      res = min(res, sumDis + g[i - 1]);
    }
    printf("Case #%d: %lld\n", cas, res);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

