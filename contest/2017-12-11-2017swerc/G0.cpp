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
const int inf = 0x3f3f3f3f;

struct Arc {
  int dest, cost;
  Arc(){};
  Arc(int dest, int cost) : dest(dest), cost(cost){};
};

int nx, ny;
vector<Arc> g[maxN];
//int g[maxN][maxN];
int linker[maxN], lx[maxN], ly[maxN];
int slack[maxN];
bool visx[maxN], visy[maxN];

inline void add_edge(int st, int ed, int c) {
  g[st].push_back(Arc(ed, -c));
}

bool dfs(int x) {
  visx[x] = 1;
  for(int i = 0;i < (int) g[x].size(); i++) {
    int y = g[x][i].dest;
    int w = g[x][i].cost;
    if(visy[y]) continue;
    int temp = lx[x] + ly[y] - w;
    if(temp == 0) {
      visy[y] = 1;
      if(linker[y] == -1 || dfs(linker[y])) {
        linker[y] = x;
        return true;
      }
    }
    else if(slack[y] > temp) 
      slack[y] = temp;
  }
  return false;
}

int KM() {
  memset(linker , -1, sizeof(linker));
  memset(ly, 0, sizeof(ly));
  for(int i = 0; i < nx; i++) {
    lx[i] = -inf;
    for(int j = 0; j < (int)g[i].size(); j++) {
      if(g[i][j].cost > lx[i]) 
        lx[i] = g[i][j].cost;
    }
  }
  cout << __LINE__ << "KM1" << endl;
  for(int x = 0; x < nx; x++) {
    for(int i = 0; i < ny; i++) 
      slack[i] = inf;
    cout << __LINE__ << "KM21" << endl;
    while(1) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if(dfs(x)) break;
      int d = inf;
      for(int i = 0; i < ny; i++) 
        if(!visy[i] && d > slack[i])
          d = slack[i];
      for(int i = 0; i < nx; i++) 
        if(visx[i]) lx[i] -= d;
      for(int i = 0; i < ny; i++) {
        if(visy[i]) ly[i] += d;
        else slack[i] -= d;
      }
    }
    cout << __LINE__ << "KM22" << endl;
  }
  cout << __LINE__ << "KM2" << endl;
  int res = 0;
  for(int i = 0; i < ny; i++) 
    if(linker[i] != -1) {
      for(auto tt:g[linker[i]]) {
        if(tt.dest == i) {
          res += tt.cost;
          break;
        }
      }
    }
  cout << __LINE__ << "KM3" << endl;
  return res;
}

struct POINT{
  int x, y;
};

int work(){
  int N, M;
  if (scanf("%d%d", &N, &M) != 2) return false;
  vector<POINT> B, C;
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

  int fixed = 0x1f2f3f4f;
  int isFixed = 1;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int gDist = abs(R.x - B[i].x) + abs(R.y - B[i].y);
    ans += gDist;
    add_edge(i, i, gDist);
    int minC = 0x1f2f3f4f;
    for (int j = 0; j < M; ++j) {
      int dist = abs(C[j].x - B[i].x) + abs(C[j].y - B[i].y);
      minC = min(minC, dist);
      if (dist >= gDist) continue;
      add_edge(M + j, i, dist);
    }
    if (minC >= gDist) {
      fixed = min(fixed, minC - gDist);
    } else isFixed = 0;
  }
  if (isFixed == 0) fixed = 0;
  nx = N + M;
  ny = M;
  cout << __LINE__ << " KM" << endl;
  printf("%d\n", KM() + ans);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif

  while(work());

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

