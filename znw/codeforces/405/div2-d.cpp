#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 200000+13;
const int maxK = 13;

int N,K;
vector<int> e[maxN][maxK];
ll s[maxN][maxK];
ll f[maxN][maxK];
ll ans = 0ll;

void dfs(int id, int pre) {
  s[id][0] = 1;
  f[id][0] = 1;
  for(auto tt:e[id][1]) if(tt!=pre){
    dfs(tt,id);
    for(int j = 0; j < K; j++) {
      for(int k = 0; k < K; k++) {
        ans += s[tt][j]*f[id][k];
        ans += f[tt][j]*s[id][k];
        if(j+k<K) {
          ans -= s[tt][j]*s[id][k];
        }
      }
    }
    for(int j = 0; j < K; j++) {
      s[id][(j+1)%K] += s[tt][j];
      f[id][(j+1)%K] += f[tt][j];
    }
    f[id][0] += s[tt][K-1];
  }
  return ;
}

int main()
{
  scanf("%d%d", &N, &K);
  rep(i,1,N) {
    int a,b;
    scanf("%d%d",&a,&b);
    e[a][1].push_back(b);
    e[b][1].push_back(a);
  }
  ans = 0ll;
  dfs(1,0);

  printf("%I64d\n",ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

