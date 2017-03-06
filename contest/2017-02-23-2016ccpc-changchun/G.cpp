#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MM = 1e9 + 7;
const int MAXN = 60;

bool edge[MAXN][MAXN];
int a[MAXN];
int n, m, ans;

int mi2(int n) {
  int ans = 1;
  rep(i, 0, n) {
    ans *= 2;
    ans %= MM;
  }
  return ans;
}
void DFS(int preID, int t) {
  vector<int> connectID;
  vector<int> disConnectID;
  bool flag;
  rep(i, preID + 1, n + 1) {
    connectID.clear();
    disConnectID.clear();
    rep(j, 0, t) {
      if (edge[i][a[j]]) connectID.push_back(a[j]);
      else disConnectID.push_back(a[j]);
    }
    flag = false;
    rep(j, 0, connectID.size()-1)
      rep(k, j + 1, connectID.size())
        if (edge[connectID[j]][connectID[k]])
          flag = true;
    if (flag) continue;
    flag = false;
    rep(j, 0, disConnectID.size()-1)
      rep(k, j + 1, disConnectID.size())
        if (!edge[disConnectID[j]][disConnectID[k]])
          flag = true;
    if (flag) continue;
    if (t >= 2) {
      ans --;
    }
    if (t < 4) {
      a[t] = i;
      DFS(i, t + 1);
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif
  int T, t, x, y;
  scanf("%d", &T);
  t = 0;
  while (T --) {
    t ++;
    scanf("%d%d", &n, &m);
    memset(edge, 0, sizeof(edge));
    rep(i, 0, m) {
      scanf("%d%d", &x, &y);
      edge[x][y] = true;
      edge[y][x] = true;
    }
    ans = mi2(n);
    ans --;
    ans -= n;
    ans -= n * (n-1) / 2;
    if (ans < 0) ans += MM;
    DFS(0, 0);
    while (ans < 0) ans += MM;
    printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}

