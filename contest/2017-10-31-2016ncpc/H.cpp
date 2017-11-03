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

const int maxN = 250000+13;

struct edge {
  int st,ed;
};

int N;
edge e[maxN];
map<int,int>hs;
vector<int> a;
vector<int> adj[maxN];

int se = 0 , sv = 0;
int v[maxN], cnt[maxN];

vector<int> tv;
void dfs(int id) {
  if(v[id]) return ;
  v[id] = 1;
  sv ++;
  se += adj[id].size();
  for(auto tt : adj[id]) {
    tv.pb(tt);
    if(!v[tt])
      dfs(tt);
  }
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d%d", &e[i].st ,&e[i].ed);
    a.pb(e[i].st);
    a.pb(e[i].ed);
  }
  sort(all(a));
  a.resize(unique(all(a)) - a.begin());
  for(int i = 0; i < a.size(); i++) {
    hs[a[i]] = i;
  }
  for(int i = 0; i < N; i++) {
    adj[hs[e[i].st]].pb(hs[e[i].ed]);
    adj[hs[e[i].ed]].pb(hs[e[i].st]);
  }
  ll ans = 0ll;
  for(int i = 0; i < a.size(); i++) {
    if(v[i]) continue;
    se = 0;sv = 0;
    tv.clear();
    dfs(i);
    se /= 2;
    if(se == sv) {
      ll ta = 0ll;
      for(auto tt: tv) ta += a[tt];
    } else {
      ll ta = 0ll;
    }
    ans += ta;
  }
  cout << ans << endl;

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

