#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 1000+13;
const int Mod = 1e9+7;

map<int,int>hs;
int N,M;
int a[maxN],b[maxN];
int f[maxN][maxN],bit[maxN][maxN];

void init() {
  memset(bit,0,sizeof(bit));
  memset(f,0,sizeof(f));
  hs.clear();
}

void dealMap() {
  rep(i, 1, N+1) b[i] = a[i];
  sort(a+1, a+1+N);
  rep(i, 1, N+1) hs[a[i]] = i+1;
  rep(i, 1, N+1) b[i] = hs[b[i]];
  return ;
}

int query(int len, int val) {
  int id = val;
  int ret = 0;
  while(id>0) {
    ret = (ret+bit[len][id]) % Mod;;
    id -= id&-id;
  }
  return ret;
}

void add(int len, int val, int tf) {
  int id = val;
  while(id<=N+1) {
    bit[len][id] = (bit[len][id]+tf) % Mod;
    id += id&-id;
  }
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("c.in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: ", cas);
    scanf("%d%d", &N, &M);
    init();
    rep(i, 1, N+1) scanf("%d", &a[i]);
    dealMap();
    ll ans = 0ll;
    rep(i, 1, N+1) {
      f[i][1] = 1;
      for(int j = 2; j<=i && j<=M; j++) {
        f[i][j] = query(j-1, b[i]-1);
        add(j, b[i], f[i][j]);
      }
      add(1, b[i], 1);
      ans = (ans + f[i][M]) % Mod;
    }
    printf("%d\n",(int)(ans%Mod));
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

