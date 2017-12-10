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

const int MAXN = 5050;

int dis[MAXN];
int vis[MAXN];
int que[MAXN];

int bfs(const int n, const int S, const vector<vector<int>> & net){
  memset(dis, 1, sizeof(int) * (n + 1));
  memset(vis, 0, sizeof(int) * (n + 1));

  dis[S] = 0;
  vis[S] = 1;
  int tail = 0;
  int head = 0;
  que[head++] = S;
  while (head != tail) {
    int x = que[tail++];
    for (int i = 0; i < (int)net[x].size(); ++i) {
      int y = net[x][i];
      if (vis[y]) continue;
      dis[y] = dis[x] + 1;
      vis[y] = 1;
      que[head++] = y;
    }
  }

  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    if (dis[i] > ret) {
      ret = dis[i];
    }
  }
  return ret;
}

int work(){
  int n, m, k;
  if (scanf("%d%d%d", &n, &m, &k) != 3) return false;
  
  vector<vector<int>> net(n+1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    net[x].push_back(y);
    net[y].push_back(x);
  }
  
  int flag = true;
  for (int i = 1; i <= n; ++i) {
    if (bfs(n, i, net) > n - k) {
      flag = false;
      break;
    }
  }

  if (flag) {
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i) {
      printf("%d%c", i, i==n?'\n':' ');
    }
  } else {
    puts("0");
  }

  return true;
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen("D.in","r",stdin);
#endif
  while (work());
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

