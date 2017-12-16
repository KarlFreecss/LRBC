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

struct EDGE{
  int to, c;
};

struct SEG{
  int l, r;

  bool operator < (const SEG & T) const {
    return l < T.l;
  }
};

const int MAXN = 5e4 + 15;

int dIn[MAXN], dOut[MAXN];
int dic[MAXN];
int dTot;
vector<EDGE> net[MAXN];
vector<SEG> del;

void dfs(const int v, const int fa){
  dic[dTot] = v;
  dIn[v] = dTot++;
  for (int i = 0; i < (int)net[v].size(); ++i) {
    const int to = net[v][i].to;
    if (to == fa) continue;
    dfs(to, v);
  }
  dOut[v] = dTot;
}

void dfsDel(const int v, const int fa){
  map<int, int> colN;
  for (int i = 0; i < (int)net[v].size(); ++i) {
    colN[net[v][i].c]++;
  }
  for (int i = 0; i < (int)net[v].size(); ++i) {
    int u = net[v][i].to;
    int c = net[v][i].c;
    if (u == fa) {
      if (colN[c] >= 2) {
        del.push_back((SEG){1, dIn[v] - 1});
        del.push_back((SEG){dOut[v], dTot});
      }
    } else {
      if (colN[c] >= 2) {
        del.push_back((SEG){dIn[u], dOut[u] - 1});
      }
      dfsDel(u, v);
    }
  }
}

int work(){
  int n;
  if (scanf("%d", &n) != 1) return false;
  for (int i = 0; i < MAXN; ++i) net[i].clear();
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    net[a].push_back((EDGE){b, c});
    net[b].push_back((EDGE){a, c});
  }
  dTot = 1;
  dfs(1, 1);
  
  del.clear();
  del.push_back((SEG){dTot, dTot});
  dfsDel(1, 1);

  sort(del.begin(), del.end());
  vector<int> ans;
  int highBound = 0;
  for (int i = 0; i < (int)del.size(); ++i) {
   if (del[i].l > highBound) {
     for (int k = highBound + 1; k < del[i].l; ++k) {
       ans.push_back(dic[k]);
     }
   }
   highBound = max(highBound, del[i].r);
  }
  printf("%d\n", (int)ans.size());
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif

  while (work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

