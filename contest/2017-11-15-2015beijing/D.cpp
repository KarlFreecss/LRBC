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

const int MAXANS = 1e7;

void work(){
 
  vector<vector<pair<int, int>>> net;
  vector<int> fuck;
  vector<int> cost;
  vector<int> depCost;
  vector<int> d;

  int N, M, S;
  scanf("%d%d%d", &N, &M, &S);
  net.resize(N + 1);
  fuck.resize(N + 1);
  depCost.resize(N + 1);
  cost.resize(N + 1);
  d.resize(N + 1);

  for (int i = 0; i < M; ++i){
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    net[A].push_back(make_pair(B, C));
    d[B]++;
  }

  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    cost[i+1] = x;
  }

  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    fuck[i+1] = x;
  }

  queue<int> que;
  for (int i = 1; i <= N; ++i) {
    if (d[i] == 0) {
      que.push(i);
      cost[i] = min(cost[i], fuck[i]);
    }
  }

  int ans = fuck[S];
  int sIsFind = 0;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    cost[x] = min(cost[x], fuck[x]);
    for (int i = 0; i < net[x].size(); ++i) {
      int y = net[x][i].first;
      --d[y];
      depCost[y] += min(net[x][i].second, cost[x]);
      if (depCost[y] > MAXANS) depCost[y] = MAXANS;
      if (d[y] == 0) {
        cost[y] = min(cost[y] + depCost[y], fuck[y]);
        que.push(y);
      }
    }
  }

  printf("%d\n", cost[S]);

}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("D.in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i)
    work();

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

