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

const int MAXP = 4e6 + 5;
const int MAXN = 3e3 + 3;

int P[MAXP];
int Pb[MAXP];
int countP = 0;
int a[MAXN];

void initP(){
  Pb[0] = 1;
  Pb[1] = 1;
  for (int i = 2; i < MAXP; ++i) {
    if (Pb[i]) continue;
    P[countP++] = i;
    for (int k = i + i; (long long)k * k < MAXP; k += i) {
      Pb[k] = 1;
    }
  }
}

vector< vector<int> > net;
int used[MAXN];
int vis[MAXN];
int linker[MAXN];

int dfs(int u) {
  for (int i = 0; i < net[u].size(); ++i) {
    int v = net[u][i];
    if (!vis[v]) {
      vis[v] = true;
      if (linker[v] == -1 || dfs(linker[v])) {
        linker[v] = u;
        return true;
      }
    }
  }
  return false;
}

void work(){
  int n, k;
  scanf("%d%d", &n, &k);
  net.resize(n);
  for (int i = 0; i < net.size(); ++i) {
    net[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (Pb[a[i]+a[j]]) continue;
      if (a[i] == a[j]) continue;
      net[i].push_back(j);
    }
  }
  int count = 0;
  memset(linker, 0xff, sizeof(linker));
  for (int i = n-1; i >= 0; --i) {
    if (a[i]&1) {
      memset(vis, 0, sizeof(vis));
      if (dfs(i)) {
        count++;
        //used[i] = 1;
        //used[linker[i]] = 1;
      }
    }
  }
  memset(used, 0, sizeof(used));
  for(int i = 0; i < n; i++) {
    if(linker[i] == -1) continue;
    used[i] = 1;
    used[linker[i]] = 1;
  }
  //cout << "count : " << count << endl;
  int unusedOne = 0;
  int canBeOne = 0;
  int isOneBeOne = 0;
  for (int i = 0; i < n; ++i){
    if (a[i] == 1 && !used[i]) ++unusedOne;
    if (!used[i]) {
      for (int j = 0; j < n; ++j) {
        if (used[j] && !Pb[a[i] + a[j]]) {
          if (a[i] != 1) canBeOne++;
          if (a[i] == 1) isOneBeOne++;
          break;
        }
      }
    }
  }
  //cout << "count = " << count << endl;
  //cout << "unusedOne = " << unusedOne << endl;
  //cout << "canBeOne = " << canBeOne << endl;
  //cout << "isOneBeOne = " << isOneBeOne << endl;
  int ans = 0;
  count = count + unusedOne / 2;
  if (count >= k) {
    ans = k * 2;
  } else {
    if (unusedOne > 1) isOneBeOne = unusedOne % 2;
    if (canBeOne + count + isOneBeOne >= k) {
      ans = count * 2 + (k - count);
    } else {
      ans = count * 2 + canBeOne + isOneBeOne;
    }
  }
  cout << ans << endl;
  //exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  initP();
  //for (int i = 0; i < 10; ++i) cout << P[i] << endl;
  int T;
  scanf("%d", &T);
 
  for (int i = 0; i < T; ++i){
    work();
  }
 
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

