#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 10000+13;

int low[maxN],dfn[maxN],Belong[maxN];
bool v[maxN];
int in[maxN], out[maxN];
int ind ,Bcnt ;
int T,N,M;
stack<int> s;
vector <int> adj[maxN];

void init() {
  while(!s.empty()) s.pop();
  for(int i = 0 ; i <= N; i++) adj[i].clear();
  memset(low,0,sizeof(low));
  memset(Belong,0,sizeof(Belong));
  memset(dfn,0,sizeof(dfn));
  memset(v,0,sizeof(v));
  memset(in,0,sizeof(in));
  memset(out,0,sizeof(out));
  ind = 0, Bcnt = 0;
  return ;
}
void tarjan(int id) {
  dfn[id]=low[id]=++ind;
  v[id]=true; s.push(id);
  int tt;
  for(auto tt: adj[id]){
    if(!dfn[tt]) {
      tarjan(tt);
      if(low[tt]<low[id]) low[id]=low[tt];
    }
    else if(v[tt] && dfn[tt]<low[id]) low[id]=dfn[tt];
  }
  if(dfn[id]==low[id]) {
    Bcnt++;
    tt=0;
    while(tt!=id) {
      tt=s.top();
      s.pop(); v[tt]=false;
      Belong[tt]=Bcnt;
    }
  }
  return ;
}

void slove() {
  for(int i=1;i<=N;i++)
    if(!dfn[i])
      tarjan(i);
  return ;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  scanf("%d", &T);
  rep(cas , 1, T+1) {
    scanf("%d%d", &N, &M);
    init();
    rep(i, 1, M+1) {
      int a,b;
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
    }
    slove();
    for(int i = 1; i <= N; i++) {
      for( auto tt :adj[i]) {
        if(Belong[i] == Belong[tt]) continue;
        out[Belong[i]] ++;
        in[Belong[tt]] ++;
      }
    }
    if(Bcnt == 1) {
      printf("0\n");
    } else {
      int s1 = 0 ,s2 = 0 ;
      for(int i =1; i<= Bcnt;i++) {
        if(in[i] == 0) s1++;
        if(out[i] == 0) s2++;
      }
      printf("%d\n", max(s1, s2));
    }
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

