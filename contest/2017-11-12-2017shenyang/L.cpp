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

const int maxN = 200000+13;

int T,N,K;
vector<int> e[maxN];
int s[maxN], p[maxN];

void dfs(int id, int pre = -1) {
  for(auto tt : e[id]) {
    if(tt == pre) continue;
    //cout << id << " -> " << tt << endl;
    dfs(tt, id);
    s[id] += s[tt];
  }
  s[id] += 1;;
  p[id] = pre;
  return ;
}
void work() {
  scanf("%d %d", &N, &K);
  for(int i = 1; i <= N; i++)  e[i].clear();
  for(int i = 1; i < N; i++) {
    int a,b; scanf("%d%d", &a, &b);
    e[a].pb(b); e[b].pb(a);
  }
  memset(s,0,sizeof(s));
  memset(p,0,sizeof(p));
  dfs(1);
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    for(auto tt : e[i]) {
      if(p[tt] == i) {
        if(s[tt] >= K && N-s[tt] >= K) ans++;
      }
    }
  }
  printf("%d\n", ans);
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("L.in","r",stdin);
#endif
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) 
    work();

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

