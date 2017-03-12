#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=5;

int a[maxN][maxN];
int ans[maxN][maxN];
int hang[maxN],lie[maxN],kuai[maxN];

inline int ck(int x,int y) {
  return ((x-1)/2)*2 + (y-1)/2 + 1;
}

void init() {
  memset(hang,0,sizeof(hang));
  memset(lie,0,sizeof(lie));
  memset(kuai,0,sizeof(kuai));
  memset(a,0,sizeof(a));
}

bool ok = false;
void dfs(int x,int y) {
  if(ok) return ;
  if(x == 5) {
    rep(i, 1, 5) rep(j, 1, 5) ans[i][j] = a[i][j];
    ok = true;
    return ;
  }
  if(y == 5) {
    dfs(x+1, 1);
    return ;
  }
  if(a[x][y] != -1) {
    dfs(x, y+1);
    return ;
  }
  rep(i, 1, 5) {
    int tt = (1<<i);
    if(hang[x]&tt) continue;
    if(lie[y]&tt) continue;
    if(kuai[ck(x,y)]&tt) continue;
    hang[x] |= (1<<i);
    lie[y] |= (1<<i);
    kuai[ck(x,y)] |= (1<<i);
    a[x][y] = i;
    dfs(x,y+1);
    a[x][y] = -1;
    hang[x] -= (1<<i);
    lie[y] -= (1<<i);
    kuai[ck(x,y)] -= (1<<i);
  }
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  char s[100];
  for(int cas = 1; cas <= T; cas++) {
    init();
    rep(i, 1, 5) {
      scanf("%s", s);
      rep(j, 1, 5) {
        a[i][j] = s[j-1]-'0';
        if(s[j-1] == '*') a[i][j] = -1;
        if(a[i][j] != -1) {
          hang[i] |= 1<<a[i][j];
          lie[j] |= 1<<a[i][j];
          kuai[ck(i,j)] |= 1<<a[i][j];
        }
      }
    }
    ok = false;
    dfs(1,1);
    printf("Case #%d:\n",cas);
    rep(i, 1, 5) {
      rep(j, 1, 5) {
        printf("%d",ans[i][j]);
      }
      printf("\n");
    }
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

