#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=31;
const int maxM=100+13;

int T,N,M;
int c[maxN],d[maxN];
int expertList[maxM];
int skillHave[maxN][maxN];
int skillNeed[maxN][maxN];
int project[maxN][maxM];
int projPeople[maxN];
int restPeople;
int ans;

void dfs(int id, int sid, int ta) {
  if(id == N+1) {
    if(ta <= ans) return ;
    ans = ta;
    return ;
  }
  if(sid == c[id]+1) {
    dfs(id+1, 1, ta+1);
    return ;
  }
  if(sid == 1) {
    dfs(id+1 ,1, ta);
  }
  if(projPeople[id] > 3) return ;
  if(N-id+1 + ta <= ans) return ;
  if(restPeople + ta <=ans) return ;
  int ts = skillNeed[id][sid];
  if(project[id][ts] > 0) {
    dfs(id, sid+1, ta);
    return ;
  }
  if(expertList[ts] == 0) return ;
  for(int i = 1,j = 1; j<expertList[ts]; j <<= 1,i++) {
    if((expertList[ts]&j) > 0) {
      expertList[ts] -= j;
      for(int k = 1; k <= d[i]; k++) {
        project[id][skillHave[i][k]] += j;
      }
      projPeople[id]++;
      restPeople--;
      dfs(id, sid+1, ta);
      projPeople[id]--;
      restPeople++;
      expertList[ts] += j;
      for(int k = 1; k <= d[i]; k++) {
        project[id][skillHave[i][k]] -= j;
      }
      dfs(id, sid+1, ta);
    }
  }
  return ;
}

void init() {
  restPeople = M;
  memset(project,0,sizeof(project));
  memset(projPeople,0,sizeof(projPeople));
  memset(expertList,0,sizeof(expertList));
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  scanf("%d",&T);
  for(int cas = 1; cas <=T; cas++) {
    scanf("%d%d", &N, &M);
    init();
    rep(i, 1, 1+N) {
      scanf("%d", &c[i]);
      rep(j, 1, 1+c[i]) {
        scanf("%d", &skillNeed[i][j]);
        expertList[skillNeed[i][j]] |= 1 << (i-1);
      }
    }
    rep(i, 1, 1+M) {
      scanf("%d", &d[i]);
      rep(j, 1, 1+d[i]) 
        scanf("%d", &skillHave[i][j]);
    }
    ans = 0;
    dfs(1,1,0);
    printf("Case #%d: %d\n", cas, ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

