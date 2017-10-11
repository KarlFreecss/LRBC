#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;
const int maxN = 40000+13;
const int maxM = 80000+13;
const ll inf = (1ll<<62) - 1;
struct Arc {
  int dest;
  ll cost;
  int rest;
  Arc *rev,*next;
  Arc(){};
  Arc(int dest,ll cost,int rest,Arc *next):
    dest(dest),cost(cost),rest(rest),next(next){};
}Npool[maxM],*Nptr(Npool);

Arc *adj[maxN],*preE[maxN];
map<string,int> hs;
queue<int>q;
ll dis[maxN];
int preV[maxN];
ll mincost(0);
int maxflow(0);
int v[maxN],S,T,N,M;

inline void add_edge(int s, int t , int r, ll cost) {
  adj[s]=new (Nptr++) Arc(t,cost,r,adj[s]);
  adj[t]=new (Nptr++) Arc(s,-cost,0,adj[t]);
  adj[s]->rev=adj[t];
  adj[t]->rev=adj[s];
}

void init() {
  hs.clear();
  Nptr = Npool;
  for(int i = 0; i <= 2*N + 13; i++) adj[i] = NULL;
}
bool spfa() {
  for(int i = 0; i <= T; i++) dis[i] = inf;
  memset(v,0,sizeof(v[0]) * (T+1));
  while(!q.empty()) q.pop();
  dis[S]=0; v[S]=1; q.push(S);
  while(!q.empty()) {
    int id=q.front();
    q.pop(); v[id]=0;
    for(Arc *p=adj[id];p;p=p->next) {
      if(p->rest>0) {
        ll temp=dis[id]+p->cost;
        if(dis[p->dest]>temp) {
          dis[p->dest]=temp;
          preV[p->dest]=id; preE[p->dest]=p;
          if(!v[p->dest]) v[p->dest]=1, q.push(p->dest);
        }
      }
    }
  }
  return dis[T]!=inf;
}

void aug() {
  int tflow=1;
  for(int i=T;i!=S;i=preV[i]) {
    preE[i]->rest-=tflow;
    preE[i]->rev->rest+=tflow;
  }
  maxflow+=tflow;
  mincost+=dis[T]*tflow;
  return ;
}

void MinCostMaxFlow() {
  maxflow = 0;
  mincost = 0;
  for(int i = 1; i <= 2; i++) {
    if(spfa()) aug();
    else return ;
  }
  return ;
}

char cs1[3000000], cs2[3000000];
int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    init();
    scanf("%d", &M);
    N = 0;
    rep(i, 1, M+1) {
      scanf("%s%s", cs1, cs2);
  //    cout << cs1 << ' ' << cs2 << endl;
      string s1,s2;
      s1 = cs1; s2 = cs2;
      ll td; scanf("%lld", &td);
      int t1, t2;
      if(hs.find(s1) == hs.end()) {
        ++N;
        hs[s1] = N;
        t1 = N;
      } else t1 = hs[s1];
      if(hs.find(s2) == hs.end()) {
        ++N;
        hs[s2] = N;
        t2 = N;
      } else t2 = hs[s2];
      t1 = t1*2;
      t2 = t2*2 - 1;
      add_edge(t1, t2, 1, td);
      t1 = t1-1;
      t2 = t2+1;
      add_edge(t2, t1, 1, td);
    }
    for(int i = 1; i <= N; i++) {
      add_edge(i*2-1, i*2, 1, 0);
    }
    S = hs["Shanghai"];
    S = S*2 - 1; 
    add_edge(S , S+1 , 1, 0);
    T = N * 2 +1;
    add_edge(hs["Xian"] * 2, T, 1, 0);
    add_edge(hs["Dalian"] * 2, T, 1, 0);
    MinCostMaxFlow();
    if(maxflow != 2) {
      printf("-1\n");
    } else {
      printf("%lld\n", mincost);
    }
  }
  return 0;
}

