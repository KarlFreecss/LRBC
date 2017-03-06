#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=800+13;
const int maxE=400*400+13;

struct Arc {
  int to,next;
}edge[maxN];

int head[maxN],tot;
void init(){
  tot=0;
  memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v) {
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
int linker[maxN];
bool used[maxN];
int uN;
bool dfs(int u) {
  for(int i = head[u]; i!=-1; i=edge[i].next){
    int v=edge[i].to;
    if(!used[v]){
      used[v]=true;
      if(linker[v]==-1 || dfs(linker[v])){
        linker[v]=u;
        return true;
      }
    }
  }
  return false;
}
int hungary(){
  int ret=0;
  memset(linker,-1,sizeof(linker));
  for(int u=1;u<=uN;u++) {
    memset(used,0,sizeof(used));
    if(dfs(u)) ret++;
  }
  return ret;
}

int T,N,S;
int a[maxN];

int main()
{
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++) {
    scanf("%d%d",&N,&S);
    printf("Case #%d: ",cas);
    int crs=N-S; if(crs<0) crs=0;
    int rest=N-crs;
    if(rest>=300) {
      printf("No\n");
      continue;
    }
    init();
    for(int i=S+1+crs;i<=N+S;i++)
      for(int j=1;j<=rest;j++)
        if(i % j==0) 
          addedge(j,i-S-crs);
    uN=rest;
    int tt=hungary();
    if(tt==rest) 
      printf("Yes\n");
    else
      printf("No\n");
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

