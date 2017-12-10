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

const int MAXN = 5e4 + 5;

vector<vector<pair<int, int>>> net;
int ans[MAXN];
int deleteNum;
int n;

void set_fault(const int x, const int fa){
 // cout << "fault : " << x << ' ' << fa << endl;
  if (ans[x] >= 0) {
    ans[x] = 0;
  }
  if (ans[x] < -10) return;
  --ans[x];
  for (int i = 0; i < (int)net[x].size(); ++i) {
    int v = net[x][i].first;
    if (v == fa) continue;
    set_fault(v, x);
  }
}

int dfs(const int x, const int fa) {
  //cout << "dfs : " << x << ' ' << fa << endl;
  if (ans[x] == 0) ans[x] = 1;
  map<int, int> col;
  for (int i = 0; i < (int)net[x].size(); ++i) {
    const int c = net[x][i].second;
    col[c]++;
  }

  int faIsOk = 1;
  int presice = 0;
  for (int i = 0; i < (int)net[x].size(); ++i) {
    const int v = net[x][i].first;
    const int c = net[x][i].second;
    if (col[c] >= 2) {
      if (v == fa) {
        faIsOk = false;
      } else {
        set_fault(v, x);
      }
    }
    {
      if (v == fa) continue;
      if (dfs(v, x) == false) {
        if (presice == 0) presice = v;
        else presice = -1;
        faIsOk = false;
        //return false;
      }
    }
  }

     //   cout << fa << " -> " << x << " -> " << v << endl;
  if (presice) {
    for (int k = 0; k < (int)net[x].size(); ++k) {
      if (net[x][k].first == fa) continue;
          if (net[x][k].first == presice) continue;
          set_fault(net[x][k].first, x);
        }
        ans[x] = -1;
  }
  return faIsOk;
}

int work(){
  if (scanf("%d", &n) != 1) return 0;
  net.clear();
  net.resize(n+1);
  deleteNum = 0;
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    net[a].push_back(make_pair(b, c));
    net[b].push_back(make_pair(a, c));
  }
  net[0].push_back(make_pair(1, 0));
  memset(ans, 0, sizeof(ans));

  dfs(0, 0);
  int ansN = 0;
  vector<int> ansQ;
  for (int i = 1; i <= n; ++i){
    if (ans[i] == 1) {
      ansN++;
      ansQ.push_back(i);
    }
  }
  printf("%d\n", ansN);
  for (int i = 0; i < (int)ansQ.size(); ++i) {
    printf("%d\n", ansQ[i]);
  }

  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif

  while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

