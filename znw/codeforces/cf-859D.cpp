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

#define oddr (l+r | l!=r)
#define mid  ((l+r)>>1)

const int maxN = 200 + 13;

double p[maxN][maxN],e[maxN][maxN];
double w[maxN][maxN];

void Build(int l, int r,int sc) {
  //cout << "l = " << l << " r = " << r << " mid = " << mid << " sc = "  << sc << endl;
  if(l == r) {
    p[oddr][l] = 1;
    e[oddr][l] = sc;
    return ;
  }
  Build(l, mid, sc/2);
  Build(mid+1,r, sc/2);
  //return ;
  int lson = (l + mid | l!=mid);
  int rson = (r + mid + 1 | r!=mid+1);
  for(int i = l; i <= mid; i++)
    for(int j = mid+1; j <= r; j++) 
      p[oddr][i] += p[lson][i] * p[rson][j] * w[i][j];
  for(int i = l; i <= mid; i++) {
    e[oddr][i] = p[oddr][i] * sc + e[lson][i];
    double tmax = 0;
    for(int j = mid+1; j <= r; j++) tmax = max(tmax, e[rson][j]);
    e[oddr][i] += tmax;
  }
  for(int j = mid+1; j <= r; j++) 
    for(int i = l; i <= mid; i++)
      p[oddr][j] += p[lson][i] * p[rson][j] * w[j][i];
  for(int i = mid+1; i <= r; i++) {
    e[oddr][i] = p[oddr][i] * sc + e[rson][i];
    double tmax = 0;
    for(int j = l; j <= mid; j++) tmax = max(tmax, e[lson][j]);
    e[oddr][i] += tmax;
  }
  return ;
}

int N;

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-859D.in","r",stdin);
  //freopen("cf-859D.out","w",stdout);
#endif
  scanf("%d", &N);
  N = 1 << N;
  //cout << N << endl;
  rep(i, 1, N+1) {
    rep(j, 1, N+1) {
      int tt; scanf("%d", &tt);
      w[i][j] = 1.0 * tt / 100;
    }
  }
  Build(1, N, N/2);
  double ans = 0.0;
  rep(i, 1, N+1) {
    int l = 1, r = N;
    ans = max(ans, e[oddr][i]);
  }
  printf("%.9lf\n", ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

