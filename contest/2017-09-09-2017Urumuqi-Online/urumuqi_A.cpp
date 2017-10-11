#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100;

vector<int> adj[maxN];
vector<int> guo[maxN];
vector<pair<int,int>> ans;

int T,N,M;
int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  scanf("%d", &T);
  rep(cas , 1 , T+1) {
    rep(i, 0, 61) {
      adj[i].clear();
      guo[i].clear();
    }
    ans.clear();
    scanf("%d%d", &N, &M);
    rep(i, 1, N+1) {
      int a, b;
      scanf("%d%d",&a, &b);
      adj[a].push_back(b);
    } 
    rep(i, 1, M+1) {
      int a, b;
      scanf("%d%d",&a, &b);
      guo[a].push_back(b);
    } 
    for(int i = 0; i <= 50; i++) {
      for(auto tt : adj[i]) {
        for(auto pl : guo[tt]) {
          ans.push_back(make_pair(i,pl));
        }
      }
    }
    sort(all(ans));
    printf("%d %d\n", ans[0].first, ans[0].second);
    for(int i = 1; i <ans.size(); i++) {
      if(ans[i] != ans[i-1])
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    printf("\n");
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

