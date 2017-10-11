#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 400 + 13;
const int maxM = 90000 + 13;
const int inf = 0x3f7f7f7f;

struct Arc
{
  int dest,cap,rest;
  Arc *rev,*next;
  Arc(){};
  Arc(int dest,int cap, int rest,Arc *next):
    dest(dest),cap(cap),rest(rest),next(next){};
}Npool[maxM],*Nptr(Npool);

Arc* adj[maxN], *cur[maxN];
int v[maxN],dis[maxN];
int S,T,flow,N,M;
queue<int>q;

void init() {
  for(int i = 0; i < maxN ; i++) 
    adj[i] = cur[i] = NULL;
  Nptr = Npool;
}

inline void add_edge(int s,int t,int r)
{
  adj[s]=new (Nptr++) Arc(t,1,r,adj[s]);
  adj[t]=new (Nptr++) Arc(s,0,0,adj[t]);
  adj[s]->rev=adj[t];
  adj[t]->rev=adj[s];
}

bool bfs()
{
  memset(v,0,sizeof(v));
  memset(dis,0xff,sizeof(dis));
  while(!q.empty()) q.pop();
  dis[S]=13; q.push(S);
  while(!q.empty())
  {
    int id=q.front(); q.pop();
    for(Arc *p=adj[id];p;p=p->next)
    {
      int j=p->dest;
      if(p->rest && dis[j]==-1)
      {
        dis[j]=dis[id]+1;
        if(j==T)return true;
        q.push(j);
      }
    }
  }
  return false;
}

int aug(int i,int m=inf)
{
  if(i==T)return m;
  int ret(0);
  for(Arc *&p=cur[i];p;p=p->next)
  {
    int j=p->dest;
    if(p->rest && !v[j] && dis[i]==dis[j]-1)
    {
      if(int a=aug(j,min(m-ret,p->rest)))
      {
        ret+=a;
        p->rest-=a;
        p->rev->rest+=a;
        if(ret==m)return ret;
      }
    }
  }
  if(ret==0)dis[i]=-1;
  v[i]=1;
  return ret;
}

void MaxFlow()
{
  flow=0;
  while(bfs())
  {
    for(int i=0;i<maxN;i++)
      cur[i]=adj[i];
    flow+=aug(S);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1009.in","r",stdin);
#endif
  scanf("%d", &T) ;
  rep(cas , 1 , T+1) {
    init();
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    rep(i , 1 , M+1) {
      int a,b,c;
      scanf("%d%d%d", &a,&b,&c);
      if(a != b) add_edge(a,b,c);
    }
    MaxFlow();
    rep(i , 1, N+1) {
      for(Arc *p = adj[i]; p ; p = p->next) {
        if(p->cap == 0) continue;
        if(p->rest == 0) {
          p->rest = 1;
          //p->rev->rest = 0;
        } else {
          p->rest = inf;
          //p->rev->rest = 0;
        }
      }
    }
    MaxFlow() ;
    printf("%d\n", flow);
  }
  //while(1);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

