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

const int MAXN = 410;

double f[MAXN], g[MAXN];
int N, K;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("F.in","r",stdin);
#endif
  scanf("%d%d", &N, &K);
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (int i = 0; i < K; i ++) {
    memset(g, 0, sizeof(g));
    for (int j = 0; j < N; j ++) {
      g[j] += f[j] * 0.5;
      g[j + 1] += f[j] * 0.5;
    }
    g[N] += f[N] * 0.5;
    g[N - 1] += f[N] * 0.5;
    for (int j = 0; j <= N; j ++) {
      f[j] = g[j];
//      cout << f[j] << " ";
    }
//    cout << endl;
  }
  double res = 0;
  for (int i = 1; i <= N; i ++) {
    res += f[i] * i;
  }
  printf("%.8lf\n", res);
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

