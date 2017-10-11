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

const int MAXN = 5e4+5;

int f[MAXN * 2];

int a[MAXN * 2];
int b[MAXN * 2];

int find(int x){
  if (f[x] != x) return f[x] = find(f[x]);
  return f[x];
}

int hasLoop(const int * a, const int * b, const int K){
  for (int i = 1; i <= 2 * K; ++i) f[i] = i;
  set<pair<int, int>> s;
  for (int i = 0; i < K; ++i) {
    if (a[i] == b[i]) continue;
    if (s.count(make_pair(a[i], b[i]))) continue;
    s.insert(make_pair(a[i], b[i]));
    s.insert(make_pair(b[i], a[i]));
    int fa = find(a[i]);
    int fb = find(b[i]);
    //cout << a[i] << ' ' << b[i] << ' ' << fa << ' ' << fb << endl;
    if (fa == fb) return 1;
    f[fb] = f[fa];
  }
  return 0;
}

vector<int> g[MAXN * 2];
vector<pair<int, int>> p2d;
int area[MAXN * 2];
int vis[MAXN * 2];

int dot(const pair<int, int> & A, const pair<int, int> & B){
  return A.first * B.second - A.second * B.first;
}

inline
pair<int, int> subPair(const pair<int, int> & A, const pair<int, int> & B){
  return make_pair(A.first - B.first, A.second - B.second);
}

int dfs(int ori, int v, const ll S){
  vis[v] = true;
  area[v] = S;
  //cout << __FILE__ << ' ' << ori << ' ' << v << endl;
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    int dS = dot(subPair(p2d[u], p2d[ori]), subPair(p2d[v], p2d[ori]));
    if (vis[u]) {
      //cout << __LINE__ << ' ' << ori << ' ' << v << ' ' << dS + S << ' ' << area[u] << endl;
      if (dS + S != area[u]) return 1;
    } else {
      if (dfs(ori, u, S + dS)) {
        return true;
      }
    }
  }
  return false;
}

int hasLoop2(){
  memset(area, 0, sizeof(area));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < p2d.size(); ++i) {
    if (vis[i]) continue;
    vis[i] = true;
    area[i] = 0;
    //cout << __FILE__ << " " << i << endl;
    for (int k = 0; k < g[i].size(); ++k) {
      if (!vis[g[i][k]])
        if (dfs(i, g[i][k], 0)) return 1;  
    }
  }
  return false;
}

int work(){
  int K;
  map<pair<int, pair<int, int>>, int> dic3D;
  map<pair<int, int>, int> dic2D;
  p2d.clear();
  int flag = 0;
  if (scanf("%d", &K) < 1) return false;
  for (int i = 0; i <= K*2; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < K; ++i) {
    int x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);

    pair<int, pair<int, int>> p3d1 = make_pair(x1, make_pair(y1, z1));
    pair<int, pair<int, int>> p3d2 = make_pair(x2, make_pair(y2, z2));
    pair<int, int> p2d1(x1, y1);
    pair<int, int> p2d2(x2, y2);
    if (dic3D.count(p3d1) == 0) {
      dic3D[p3d1] = dic3D.size();
    }
    if (dic3D.count(p3d2) == 0) {
      dic3D[p3d2] = dic3D.size();
    }
    if (dic2D.count(p2d1) == 0) {
      dic2D[p2d1] = dic2D.size() - 1;
      p2d.push_back(p2d1);
    }
    if (dic2D.count(p2d2) == 0) {
      dic2D[p2d2] = dic2D.size() - 1;
      p2d.push_back(p2d2);
    }
    a[i] = dic3D[p3d1];
    b[i] = dic3D[p3d2];
    int v = dic2D[p2d1];
    int u = dic2D[p2d2];
    g[v].push_back(u);
    g[u].push_back(v);
  }

  if (hasLoop(a, b, K)) {
    puts("True closed chains");
  } else {
    puts("No true closed chains");
  }

  if (hasLoop2()) {
    puts("Floor closed chains");
  } else {
    puts("No floor closed chains");
  }
  return 1;
}


int main() {
#ifndef ONLINE_JUDGE
  //freopen("k.in","r",stdin);
#endif
  while (work());
   //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

