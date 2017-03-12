#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=2e5+13;

int N, ans;
vector<int> e[maxN];
int d[maxN];
int c[maxN];

inline void add_edge(int st, int ed) {
  e[st].push_back(ed);
  e[ed].push_back(st);
}

void dfs(int id, int pre) {
  int ind = 1;
  for(auto tt:e[id]) {
    if(tt != pre) {
      while(ind==c[id] || ind==c[pre]) ind++;
      c[tt] = ind;
      dfs(tt,id);
      ind++;
    }
  }
  return ;
}

int main()
{
  scanf("%d", &N);
  ans = 0;
  for(int i = 1; i < N; i++) {
    int a,b;
    scanf("%d%d", &a, &b);
    add_edge(a,b);
    d[a]++,d[b]++;
    if(d[a] > ans) ans = d[a];
    if(d[b] > ans) ans = d[b];
  }
  ans++;
  printf("%d\n",ans);
  c[1] = 1;
  dfs(1,0);
  printf("%d", c[1]);
  rep(i,2,N+1) printf(" %d",c[i]);
  printf("\n");

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

