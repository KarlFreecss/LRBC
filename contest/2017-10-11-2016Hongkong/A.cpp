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
typedef vector<int> vi;

const int maxN = 200 + 13;

int N,M,K;
int base[maxN];
int cs[maxN], ct[maxN];
int lcs[maxN];
int v[maxN];
int sok = 0, T;
vi path, tp, e[maxN];
bool Find = false;
queue<vi> q;
void out() {
  bool same= true;
  rep(i, 1, N+1) if(cs[i] != lcs[i]) same = false;
  if(same) return ;
  rep(i, 1, N) printf("%d ", cs[i]);
  printf("%d\n", cs[N]);
}

void dfs(int id) {
  tp.pb(id);
  v[id] = 1;
  if(id == T) {
    for(auto tt:tp) path.pb(tt);
    Find = true;
    return ;
  }
  if(Find) return ;
  for(auto tt:e[id]) {
    if(!v[tt]) {
      dfs(tt);
      if(Find) return ;
    }
  }
  tp.pop_back();
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  scanf("%d%d%d",&N, &M, &K);
  rep(i, 1, N+1) scanf("%d", &cs[i]);
  rep(i, 1, N+1) scanf("%d", &ct[i]);
  rep(i, 1, M+1) {
    int a,b;
    scanf("%d%d", &a, &b);
    e[a].pb(b);
    e[b].pb(a);
  }
  memset(base, 0, sizeof(base));
  rep(i, 1, N+1) {
    if(cs[i] == ct[i]) {
      base[cs[i]] = i;
    }
  }
  bool noans = false;
  rep(i, 1, N+1) {
    int tc = ct[i];
    if(base[tc] != 0) continue;
    T = -1;
    rep(j, 1, N+1) if(j != i){
      if(cs[j] == tc) T = j;
    }
    if(T == -1) noans = true;
    if(noans) break;
  }
  if(noans) {
    printf("Impossible\n");
    return 0;
  }
  out();
  rep(i, 1, N+1) {
    int tc = ct[i];
    if(base[tc] != 0) continue;
    rep(j, 1, N+1) {
      if(cs[j] == tc) {
        T = j;
        break;
      }
    }
    int S = T;
    T = i;
    memset(v,0,sizeof(v));
    Find = false;
    tp.clear();
    path.clear();
    dfs(S);
    for(int i = 0; i < (int)path.size()-1; i++) {
      rep(k, 1, N+1) lcs[k] = cs[k];
      swap(cs[path[i]],cs[path[i+1]]);
      out();
    }
    base[tc] = i;
  }
  //cout << "xxxxx" << endl;
  rep(i, 1, N+1) {
    //cout << i << ":" << endl;
    if(cs[i] == ct[i]) continue;
    int tc = ct[i];
    T = i;
    memset(v,0,sizeof(v));
    tp.clear();
    path.clear();
    Find = false;
    //cout << base[tc] << ' ' << T << endl;
    dfs(base[tc]);
    //cout << "path size() " << path.size() << endl;
    //for(auto tt : path) cout << tt << ' ' ;
    //cout << endl;

    for(int i = 0; i < (int)path.size()-2; i++) {
      //cout << path[i] << ' ' << path[i+1] << endl;
      //cout << i << endl;
      rep(k, 1, N+1) lcs[k] = cs[k];
      //cout << "swap" << endl;
      //cout << path[i] << ' ' << path[i+1] << endl;
      swap(cs[path[i]],cs[path[i+1]]);
      //cout << "out() " << endl;
      out();
    }
    //cout << "mid" << endl;
    cs[i] = tc;
    out();
    for(int i = (int)path.size() - 2; i >= 1; i--) {
      rep(k, 1, N+1) lcs[k] = cs[k];
      swap(cs[path[i]],cs[path[i-1]]);
      out();
    }
    //cout << endl;
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

