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

const int MAXL = 1;
const int MAXR = 1e6;
const int MAXH = 20;

vector<vector<int>> g;
vector<int> s;
vector<pair<int, int>> ans;

int dfs(int u, int fa){
  s[u] = 1;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i];
    if (v == fa) continue;
    s[u] += dfs(v, u);
  }
  return s[u];
}

void emmm(const int u, const int fa, int l, int r, int h){
  assert(h < MAXH);
  ans[u] = make_pair(l, h);
  //cout << u << ' ' << l << ' ' << r << endl;
  long long alreadyN = 0;
  long long len = r - l;
  ++l;
  int maxS = 0;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    if (fa == g[u][i]) continue;
    if (s[maxS] < s[g[u][i]]) {
      maxS = g[u][i];
    }
  }
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i];
    if (v == fa) continue;
    if (v == maxS) continue;
    int sL = l + len * alreadyN / s[u] + 1;
    alreadyN += s[v];
    int sR = l + len * alreadyN / s[u];
    emmm(v, u, sL, sR, h + 1);
  }
  if (maxS) {
    int sL = l + len * alreadyN / s[u] + 1;
    alreadyN += s[maxS];
    int sR = l + len * alreadyN / s[u];
    emmm(maxS, u, sL, sR, h);
  }
}

int work(){
  int n;
  if (scanf("%d", &n) != 1) return false;
  g.clear();
  g.resize(n+1);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  s.clear();
  s.resize(n+1);
  dfs(1, 1);
  /*for (int i = 1; i <= n; ++i) {
    cout << i << ' ' << s[i] << endl;
  }*/
  ans.clear();
  ans.resize(n + 1);
  emmm(1, 1, MAXL, MAXR, 1);
  for (int i = 1; i <= n; ++i) {
    int x = ans[i].first;
    int y = ans[i].second;
    //cout << "# " << i << ' ';
    printf("%d %d\n", x, y);
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("C.in","r",stdin);
#endif

  while(work());


 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

