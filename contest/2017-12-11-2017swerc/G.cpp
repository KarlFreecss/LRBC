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

const int maxN = 2000 + 13;
const int maxE = 4100000 + 13;
const int inf = 0x3f3f3f3f;

struct Arc {
  int dest,rest,cost,rev;
  Arc(){};
  Arc(int dest, int rest, int cost, int rev) : dest(dest),rest(rest), cost(cost), rev(rev){};
}*Nptr, Npool[maxE];

int nx, ny;
int S, T;
vector<Arc> adj[maxN];
int dis[maxN], preV[maxN], preE[maxN];
int v[maxN];
queue<int> q;

inline void add_edge(int st, int ed, int r, int c) {
  adj[st].push_back(Arc(ed, r, c, -1));
  adj[ed].push_back(Arc(st, 0, -c, -1));
  adj[st][adj[st].size()-1].rev = adj[ed].size() - 1;
  adj[ed][adj[ed].size()-1].rev = adj[st].size() - 1;
}

bool spfa() {
  memset(dis, inf, sizeof(dis));
  memset(v,0,sizeof(v));
  while(!q.empty()) q.pop();
  dis[S] = 0; v[S] = 1; q.push(S);
  while(!q.empty()) {
    int id = q.front();
    q.pop(); v[id] = 0;
    for(int i = 0; i < (int) adj[id].size(); i++) {
      if(adj[id][i].rest == 0) continue;
      int temp = dis[id] + adj[id][i].cost;
      int dest = adj[id][i].dest;
      if(temp < dis[dest]) {
        dis[dest] = temp;
        preV[dest] = id;
        preE[dest] = i;
        if(!v[dest]) {
          v[dest] = 1;
          q.push(dest);
        }
      }
    }
  }
  return dis[T] != inf;
}

int maxflow() {
  int ret = 0;
  while(spfa()) {
    int tflow = inf;
    int id = T;
    while(id != S) {
      if(tflow > adj[preV[id]][preE[id]].rest) tflow = adj[preV[id]][preE[id]].rest;
      id = preV[id];
    }
    id = T;
    while(id != S) {
      adj[preV[id]][preE[id]].rest -= tflow;
      adj[id][adj[preV[id]][preE[id]].rev].rest += tflow;
      id = preV[id];
    }
    ret += tflow * dis[T];
  }
  return ret;
}

struct POINT{
  int x, y;
};

int work(){
  int N, M;
  if (scanf("%d%d", &N, &M) != 2) return false;
  vector<POINT> B, C;
  for(int i = 0; i <= N + M + 2; i++) adj[i].clear();
  for (int i = 0; i < N; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    B.push_back((POINT){x, y});
  }
  for (int i = 0; i < M; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    C.push_back((POINT){x, y});
  }
  POINT R;
  int x, y;
  scanf("%d%d", &x, &y);
  R = (POINT){x, y};

  int ans = 0;
  S = 0;
  add_edge(S, 1, B.size() - 1, 0);
  for (int i = 0; i < M; ++i) {
    add_edge(S, 2 + i, 1, 0);
  }
  for (int i = 0; i < N; ++i) {
    int gDist = abs(R.x - B[i].x) + abs(R.y - B[i].y);
    ans += gDist;
    add_edge(1, M + i + 2, 1, gDist);
    int minC = 0x1f2f3f4f;
    int bestC = 0;
    for (int j = 0; j < M; ++j) {
      int dist = abs(C[j].x - B[i].x) + abs(C[j].y - B[i].y);
      if (minC > dist) {
        bestC = j;
        minC = dist;
      }
      if (dist >= gDist) continue;
      add_edge(2 + j, M + i + 2, 1, dist);
    }
    if (minC >= gDist)
      add_edge(2 + bestC, M + i + 2, 1, minC); 
  }
  T = N + M + 2;
  for (int i = 0; i < N; ++i) {
    add_edge(i + M + 2, T, 1, 0);
  }
  printf("%d\n", ans + maxflow());
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif

  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

