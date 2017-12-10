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

const int maxN = 1000 + 13;


struct Arc {
  int dest, x, y;
  Arc(){};
  Arc(int dest, int x,int y) :dest(dest), x(x), y(y){};
};

queue<int> q;
int v[maxN];
int S, T;
int N,M,K;
vector<Arc> e[maxN];

bool ok(Arc x, int st, int ed) {
  if(st >= x.x&& ed <= x.y) return true;
  return false;
}

bool check(int st, int ed) {
  if(ed < st) return false;
  //cout << st << ' ' << ed << endl;
  while(!q.empty())q.pop();
  memset(v, 0, sizeof(v));
  q.push(S); v[S] = 1;
  while(!q.empty()) {
    int id = q.front(); q.pop();
    for(auto tp : e[id]) {
      int dest = tp.dest;
      if(v[dest]) continue;
      if(ok(tp , st, ed)) {
        q.push(dest);
        v[dest] = 1;
        if(dest == T) return true;
      }
    }
  }
  return false;
}

int work() {
  if(scanf("%d%d%d", &N, &M, &K) != 3) return 0;
  for(int i = 1; i <= N; i++) e[i].clear();
  scanf("%d%d", &S, &T);
  vector<int> xx; xx.clear();
  for(int i = 1; i <= M; i++) {
    int a, b , c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    e[a].push_back(Arc(b,c,d));
    xx.push_back(c);
    xx.push_back(d);
  }
  xx.push_back(K);
  sort(all(xx));
  xx.resize(unique(all(xx)) - xx.begin());
  //for(auto tt:xx) {
  //  cout << tt << ' ' ;
  //}
  //cout << endl;
  int ans = 0;
  for(int i = 0; i < (int)xx.size() - 1; i++) {
    int st = xx[i]+1, ed = xx[i+1] -1;;
    if(check(xx[i], xx[i])) ans++;
    if(st <= ed && check(st, ed)) ans += ed - st + 1;
  }
  if(check(xx.back(), xx.back())) ans++;
  printf("%d\n", ans);
  //for(int i = 1; i <= K; i++) {
  //  cout << i << ' ' << check(i,i) << endl;
  //}
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

