#include <bits/stdc++.h>

using namespace std;

#define DEBUG_INFO(x) //cerr << __LINE__ << #x " = " << x << endl
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

const int MAXN = 1e4 + 5;
const int INF = 0x2f2f2f2f;
const int MAXB = 1e4 + 5;
struct EDGE{
  int to, cost, prestige;
};
struct DISH{
  int cost, prestige;
};

vector<EDGE> net[MAXN];
int deg[MAXN];
DISH dish[MAXN];

inline int getIdFromName(const char * name, map<string, int> & dic){
  if (dic.count(name) == 0) {
    int size = dic.size();
    dic[name] = size;
  }
  //cout << "_-----" << name << "----_" << endl;
  //DEBUG_INFO(name);
  //DEBUG_INFO(dic[name]);
  return dic[name];
} 


void getFinalCostAndPrestige(const int N){
  queue<int> que;
  DEBUG_INFO(N);
 // cerr << __LINE__ << " : " << N << endl;

  for (int i = 0; i < N; ++i) {
    if (deg[i] == 0) {
      dish[i].cost = 0;
      dish[i].prestige = 0;
      que.push(i);
      DEBUG_INFO(i);
      //cerr << __LINE__ << " : " << i << endl;
    }
  }
  
  while(!que.empty()) {
    int v = que.front(); que.pop();
    for (int i = 0; i < (int)net[v].size(); ++i) {
      int u = net[v][i].to;
      int uCost = net[v][i].cost;
      int uPrestige = net[v][i].prestige;
      if (dish[u].cost > uCost + dish[v].cost) {
        dish[u].cost = uCost + dish[v].cost;
        dish[u].prestige = uPrestige + dish[v].prestige;
      } else if (dish[u].cost == uCost + dish[v].cost) {
        dish[u].prestige = max(dish[u].prestige, uPrestige + dish[v].prestige);
      }
      --deg[u];
      if (deg[u] == 0) {
        que.push(u);
      }
    }
  }
}


int f[MAXB];
pair<int, int> dp(const int B, const int N){
  memset(f, 0, sizeof(f));
  for (int i = 0; i < N; ++i) {
    int cost = dish[i].cost;
    int prestige = dish[i].prestige;
    for (int j = B; j >= cost; --j) {
      f[j] = max(f[j], f[j - cost] + prestige);
    }
  }
  pair<int, int> res;
  for (int i = 0; i <= B; ++i) {
    if (f[i] > res.first) {
      res = make_pair(f[i], i);
    }
  }
  return res;
}

int work(){
  int B;
  int N;
  if (scanf("%d%d", &B, &N) != 2) return false;

  for (int i = 0; i < MAXN; ++i) {
    net[i].clear();
    deg[i] = 0;
    dish[i].cost = INF;
    dish[i].prestige = 0;
  }
  map<string, int> nameToInt;
  for (int i = 0; i < N; ++i) {
    char piz1[256], piz2[256], ing[256];
    int cost, prestige;
    scanf("%s%s%s%d%d", piz1, piz2, ing, &cost, &prestige);
    int u = getIdFromName(piz1, nameToInt);
    int v = getIdFromName(piz2, nameToInt);
    //cout << u << ' ' << v << "    (" << piz2 << " -> " << piz1 << ")" << endl;
    net[v].push_back((EDGE){u, cost, prestige});
    deg[u]++;
  }

  getFinalCostAndPrestige(nameToInt.size());
  
 // for (int i = 0; i < (int)nameToInt.size(); ++i) {
  //  cout << "dish[" << i << "] = " << dish[i].cost << ' ' << dish[i].prestige << endl;
 // }
  
  pair<int, int> ans = dp(B, nameToInt.size());
  printf("%d\n%d\n", ans.first, ans.second);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen("E.in","r",stdin);
#endif

  while(work());

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

