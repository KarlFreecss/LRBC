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

const int MAXN = 1e3 + 5;

struct EDGE{
  int to;
  int low, high;
};

vector<EDGE> net[MAXN];
int vis[MAXN];

int bfs(const int n, const int s, const int d, const int low, const int high){
  for (int i = 0; i <= n; ++i) {
    vis[i] = 0;
  } 
  vis[s] = 1;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    if (x == d) return true;
    for (int i = 0; i < (int)net[x].size(); ++i) {
      const int to = net[x][i].to;
      const int stdLow = net[x][i].low;
      const int stdHigh = net[x][i].high;
      if (low < stdLow) continue;
      if (high > stdHigh) continue;
      if (vis[to]) continue;
      vis[to] = 1;
      que.push(to);
    }
  }
  return false;
}

int work(){
  int n, m, k;
  if (scanf("%d%d%d", &n, &m, &k) != 3) return false;
  int s, d;
  scanf("%d%d", &s, &d);
  for (int i = 0; i < MAXN; ++i) net[i].clear();
  vector<int> p;
  p.push_back(k);
  p.push_back(1);
  for (int i = 0; i < m; ++i) {
    int a, b, low, high;
    scanf("%d%d%d%d", &a, &b, &low, &high);
    net[a].push_back((EDGE){b, low, high});
    p.push_back(low);
    p.push_back(high);
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int ans = 0;
  if (bfs(n, s, d, p[0], p[0])) ++ans;
  for (int i = 1; i < (int)p.size(); ++i) {
    if (p[i] - 1 >= p[i-1] + 1) {
      int low = p[i-1] + 1;
      int high = p[i] - 1;
      if (bfs(n, s, d, low, high)) ans += high - low + 1;
    }
    if (bfs(n, s, d, p[i], p[i])) ++ans;
  }
  printf("%d\n", ans);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif

  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

