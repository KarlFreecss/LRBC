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

const int maxN = 3e5 + 13;
const int Mod = 1e9 + 7;

int N;
int p[maxN],s[maxN];
int selfloop[maxN], loop[maxN];

int find(int x) {
  for(;x != p[x]; x = p[x])
    p[x] = p[p[x]];
  return p[x];
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-859E.in","r",stdin);
#endif
  scanf("%d", &N);
  rep(i, 0, N*2+1) p[i] = i, s[i] = 1;
  rep(e, 1 , N+1) {
    int u,v;
    scanf("%d%d", &u, &v);
    if(u == v) selfloop[u] = 1;
    //cout << "raw : " << u <<' ' << v << endl;
    u = find(u);
    v = find(v);
    //cout << "new : " << u <<' ' << v << endl;
    if(u == v) {
      loop[u] = 1;
      continue;
    } else {
      p[u] = v;
      s[v] += s[u];
      loop[v] |= loop[u];
    }
  }
  N = N*2;
  ll ans = 1ll;
  rep(i, 1, N+1) {
    int rt = find(i);
    //cout << i << ' ' << rt << endl;
    if(rt != i) continue;
    if(selfloop[i]) continue;
    if(loop[i]) {
      ans = (ans * 2) % Mod;
    } else {
      ans = (ans * s[i]) % Mod;
    }
  }
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

