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

const int maxN = 600 + 13;
const int maxM = 20000 + 13;
const int inf = 0x7f7f7f7f;

int V,E,N,K;
int sc[maxN];
ll m[maxN][maxN];
vi e[maxN];
vi rightP, leftP;
int ilink[maxN],used[maxN];
int lim = 0, sl = 0;;

bool find(int id) {
  int pos = sc[id];
  for(auto tt:e[id]) {
    if(m[pos][tt] > lim) continue;
    //if(pos == tt) continue;
    //cout << id << ' ' << tt << endl;
    if(!used[tt]) {
      used[tt] = 1;
      if(ilink[tt] == -1 || find(ilink[tt])) {
        ilink[tt] = id;
        return true;
      }
    }
  }
  return false;
}

int check() {
  int ret = 0;
  memset(ilink, -1 ,sizeof(ilink));
  for(auto i : leftP) {
    memset(used, 0 ,sizeof(used));
    if(find(i)) ret++;
  }
  return ret ;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-852D.in","r",stdin);
#endif
  scanf("%d%d%d%d", &V, &E, &N, &K);
  set<int> s;
  rep(i, 1, N+1) {
    scanf("%d", &sc[i]);
    s.insert(sc[i]);
  }
  if(s.size() >= K) {
    printf("0\n");
    return 0;
  }
  rep(i, 1, V+1)
    rep(j, 1, V+1) m[i][j] = inf;
  rep(i, 1, E+1) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    m[a][b] = min(m[a][b], (ll)c);
    m[b][a] = m[a][b];
  }
  //rep(i, 1, V+1) {
  //  rep(j, 1, V+1)
  //    cout << m[i][j] << ' ';
  //  cout << endl;
  //}
  rep(k, 1, V+1) 
    rep(i, 1, V+1)
      rep(j, 1, V+1) 
        m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
  //rep(i, 1, V+1) {
  //  rep(j, 1, V+1)
  //    cout << m[i][j] << ' ';
  //  cout << endl;
  //}
  rep(i, 1, V+1) m[i][i] = 0;
  memset(used, 0, sizeof(used));
  sl = s.size();
  rep(i, 1, V+1) 
    //if(s.find(i) == s.end()) 
      rightP.pb(i);
      //cout << i << endl;
  rep(i, 1, N+1) {
    //if(used[sc[i]] == 0) {
    //  used[sc[i]] = 1;
    //} else {
      leftP.pb(i);
      for(auto tt:rightP) {
        e[i].pb(tt);
        //cout << i << " -> " << tt << endl;
      }
    //}
  }
  int ll = 0, rr = 1731313;
  while(ll < rr-1) {
    lim = (ll + rr) >> 1;
    //cout << lim << endl;
    int tt = check();
    //cout << "tt: " << tt << ' ' << " sl: " << sl << endl;
    if(tt >= K) {
      rr = lim;
    } else {
      ll = lim;
    }
  }
  if(rr == 1731313) rr = -1;
  printf("%d\n", rr);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
};

