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

const int maxN = 2500*3;

vector<int> e[maxN];
int vis[maxN], linker[maxN];
map <ll, int> hs;
int N;
int a[maxN], b[maxN];
vector<ll> num;

bool find(int id) {
  for(auto tt:e[id]) {
    if(vis[tt]) continue;
    vis[tt] = 1;
    if(linker[tt] == -1 || find(linker[tt])) {
      linker[tt] = id;
      return true;
    }
  }
  return false;
}

void init() {
  num.clear();
  hs.clear();
}

char op[10];

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  op[0] = '*';
  op[1] = '+';
  op[2] = '-';

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d%d", &a[i], &b[i]);
    num.pb((ll)a[i] * (ll)b[i]);
    num.pb((ll)a[i] + (ll)b[i]);
    num.pb((ll)a[i] - (ll)b[i]);
  }
  sort(all(num));
  num.resize(unique(all(num)) - num.begin());
  for(int i = 0; i < num.size(); i++) 
    hs[num[i]] = i;
  for(int i = 0; i < N; i++) {
    e[i].pb(hs[(ll)a[i] * (ll)b[i]]);
    e[i].pb(hs[(ll)a[i] + (ll)b[i]]);
    e[i].pb(hs[(ll)a[i] - (ll)b[i]]);
  }
  memset(linker, -1, sizeof(linker));
  int ans = 0;
  for(int i = 0; i < N; i++) {
    memset(vis, 0 ,sizeof(vis));
    if(find(i)) ans++;
  }
  if(ans != N) {
    printf("impossible\n");
  } else {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < 3; j++) {
        if(linker[e[i][j]] == i) {
          printf("%d %c %d = %lld\n", a[i], op[j], b[i], num[e[i][j]]);
          break;
        }
      }
    }
  }
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

