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
#define mp(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxN = 100000+13;

vector<pii> adj[maxN];
vector<pii> e;
int keep[maxN], dep[maxN];

int N, M;
int ind = 0;
void dfs(int id) {
  dep[id] = ++ ind;;
  for(auto tt : adj[id]) {
    int dest = tt.first;
    if(dep[dest] == 0) {
      dfs(dest);
      keep[tt.second] = 1;
    }
  }
  int imin = maxN , min_id = maxN;
  for(auto tt : adj[id]) {
    int dest = tt.first;
    if(dep[dest] < imin) {
      imin = dep[dest] ;
      min_id = tt.second;
    }
  }
  if(imin != maxN) {
    keep[min_id] = 1;
  }
  return ;
}

void work() {
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++) adj[i].clear();
  e.clear();
  ind = 0;
  memset(keep, 0, sizeof(keep));
  memset(dep, 0, sizeof(dep));
  for(int i = 0; i < M; i++) {
    int st, ed;
    scanf("%d %d", &st, &ed);
    adj[st].push_back(mp(ed,i));
    e.push_back(mp(st, ed));
  }
  dfs(1);
  int num = 0;
  for(int i = 0; i < M; i++) {
    if(keep[i]) continue;
    printf("%d %d\n", e[i].first, e[i].second);
    num++;
    if(num == M - 2 * N) break;
  }
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    work();
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

