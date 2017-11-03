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

const int maxN = 1000+13;

int N, R, L;
int m[maxN][maxN];
int x[maxN], y[maxN];
vector<int> e[maxN];
int v[maxN];

bool dfs(int id, int c) {
  v[id] = c;
  int tx = x[id], ty = y[id];
  if(c == 1) {
    for(int j = max(1,ty-R-R+1); j <= min(N, ty+R+R-1); j++) {
      if(m[tx][j] != 0 && m[tx][j] != id) {
        int tt = m[tx][j];
        if(v[tt] == -c) continue;
        if(v[tt] == c) return false;
        if(false == dfs(tt, -c)) return false;
      }
    }
  } else {
    for(int i = max(1,tx-R-R+1); i <= min(N, tx+R+R-1); i++) {
      if(m[i][ty] != 0 && m[i][ty] != id) {
        int tt = m[i][ty];
        if(v[tt] == -c) continue;
        if(v[tt] == c) return false;
        if(false == dfs(tt, -c)) return false;
      }
    }

  }
  return true;
}
int tv[maxN];

bool try_dfs(int id, int c) {
  for(int i = 1; i <= L; i++) 
    tv[i] = v[i];
  if(dfs(id, c)) return true;
  for(int i = 1; i <= L; i++) 
    v[i] = tv[i];
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  memset(m, 0, sizeof(m));
  memset(v, 0, sizeof(v));
  scanf("%d%d%d", &N, &R, &L);
  for(int i = 1; i <= L; i++) {
    scanf("%d%d", &x[i], &y[i]);
    m[x[i]][y[i]] = i;
  }
  bool ok = true;
  for(int i = 1; i <= L; i++) {
    if(v[i] == 0) {
      if(false == try_dfs(i, 1) && false == try_dfs(i, -1)) {
        ok = false; break;
      }
    }
  }
  if(ok) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

