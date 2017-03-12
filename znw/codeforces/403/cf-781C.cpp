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

vector<int> e[maxN];
int N,M,K;
queue<int>q;
int ind=0;
int v[maxN];

void dfs(int id) {
  v[id] = 1;
  q.push(id);
  ind++;
  for(auto tt:e[id]) {
    if(!v[tt]) {
      dfs(tt);
      q.push(id);
      ind++;
    }
  }
  return ;
}

int ans[maxN];

int main() {

  scanf("%d%d%d",&N,&M,&K);
  rep(i,1,1+M) {
    int a,b;
    scanf("%d%d",&a,&b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(1);
  int tt=2*N/K;
  if(2*N%K != 0) tt++;
  while(K) {
    if(q.empty()) break;
    K--;
    int ts = 0;
    while(!q.empty() && ts<tt) {
      ts++;
      ans[ts]=q.front();q.pop();
    }
    printf("%d",ts);
    rep(i,1,ts+1) printf(" %d",ans[i]);
    printf("\n");
  }
  while(K--) {
    printf("1 1\n");
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

