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

const int maxN = 1e5+13;

int N;
vector<int> adj[maxN];
int v[maxN];
int l[maxN];

void dfs(int id) {
  v[id] = 1;
  for(auto tt:adj[id]) {
    if(!v[tt]) { 
      l[tt] = l[id]^1;
      dfs(tt);
    }
  }
  return ;
}
int main() {
//#ifndef ONLINE_JUDGE
////  freopen("cf-862B.in","r",stdin);
//#endif
  scanf("%d", &N);
  rep(i,1,N) {
    int a,b;
    scanf("%d%d",&a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  ll ans = 0ll;
  dfs(1);
  int sl = 0;
  rep(i, 1, N+1) 
    sl += l[i];
  rep(i, 1, N+1) 
    if(l[i] == 0) 
      ans += sl - adj[i].size();
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

