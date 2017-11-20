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

const int maxN = 230 + 13;

int x[maxN], y[maxN];
int m[maxN][maxN];

int check(int i, int j, int x2, int y2) {
  if( (x[i]-x2)*(x[j]-x2) > 0) return 0;
  if( (y[i]-y2)*(y[j]-y2) > 0) return 0;
  return 1;
}
int check_onside(int i, int j, int x2, int y2) {
  if( (x[i]-x2)*(x[j]-x2) == 0) return 1;
  if( (y[i]-y2)*(y[j]-y2) == 0) return 1;
  return 0;
}

inline int iabs(int x) {
  if(x < 0) return -x;
  return x;
}

int calc(int i, int j) {
  int tx = iabs(x[i] - x[j]);
  int ty = iabs(y[i] - y[j]);
  return tx * ty;
}

int work() {
  int N;
  scanf("%d", &N);
  if(N == 0) return 0;
  memset(m,0,sizeof(m));
  for(int i = 1; i <= N; i++) {
    scanf("%d%d", &x[i], &y[i]);
    m[x[i]][y[i]] = 1;
  }
  int ans = -1;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) if(i != j) {
      if(m[x[i]][y[j]] == 0 || m[x[j]][y[i]] == 0) continue;
      if(x[i] == x[j] || y[i] == y[j]) continue;
      for(int i2 = 1; i2 <= N; i2++) if(i2 != i && i2 != j) {
        for(int j2 = 1; j2 <= N; j2++) if(j2 != i2 && j2 != i && j2 != j) {
          if(m[x[i2]][y[j2]] == 0 || m[x[j2]][y[i2]] == 0) continue;
          if(x[i2] == x[j2] || y[i2] == y[j2]) continue;
          int ta = -1;
          int ts1 = check(i,j,x[i2],y[i2]) + check(i,j,x[i2],y[j2]) + check(i,j,x[j2], y[j2]) + check(i,j,x[j2],y[i2]);
          int ts2 = check(i2,j2,x[i],y[i]) + check(i2,j2,x[i],y[j]) + check(i2,j2,x[j], y[j]) + check(i2,j2,x[j],y[i]);
          if(ts1 == 4 && ts2 == 0) {
            int tt =check_onside(i,j,x[i2],y[i2]) + check_onside(i,j,x[i2],y[j2]) + check_onside(i,j,x[j2], y[j2]) + check_onside(i,j,x[j2],y[i2]);
            if(tt > 0) continue;
            ta = calc(i,j);
            if(ta > ans) ans = ta;
            continue;
          }
          if(ts2 == 4 && ts1 == 0) {
            int tt = check_onside(i2,j2,x[i],y[i]) + check_onside(i2,j2,x[i],y[j]) + check_onside(i2,j2,x[j], y[j]) + check_onside(i2,j2,x[j],y[i]);
            if(tt > 0) continue;
            ta = calc(i2,j2);
            if(ta > ans) ans = ta;
            continue;
          }
          if(ts1 == 0 && ts2 == 0) {
            ta = calc(i,j) + calc(i2, j2);
            if(ta > ans) ans = ta;
            continue;
          }
        }
      }
    }
  }
  if(ans != -1)
    printf("%d\n", ans);
  else 
    printf("imp\n");
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

