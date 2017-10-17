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

const int maxV = 100 + 13;
const int maxE = maxV * maxV + 13;
const int inf = 0x7f7f7f7f;

struct Arc
{
  int dest,cost,rest;
  Arc *rev,*next;
  Arc(){};
  Arc(int dest,int cost,int rest,Arc *next):
    dest(dest),cost(cost),rest(rest),next(next){};
}Npool[maxE],*Nptr(Npool);
Arc *adj[maxV],*preE[maxV];
queue<int>q;
int dis[maxV],preV[maxV],mincost(0),maxflow(0);
int l[maxV], r[maxV];
bool v[maxV];
int S, T;
inline void add_edge(int st, int ed, int rest, int cost) {
  //cout << st << " -> " << ed << ' ' << rest << ' ' << cost << endl;
  adj[st] = new(Nptr++) Arc(ed, cost, rest, adj[st]);
  adj[ed] = new(Nptr++) Arc(st, -cost, 0, adj[ed]);
  adj[st] -> rev = adj[ed];
  adj[ed] -> rev = adj[st];
}
bool spfa()
{
  memset(dis,inf,sizeof(dis));
  memset(v,0,sizeof(v));
  while(!q.empty()) q.pop();
  dis[S]=0; v[S]=1; q.push(S);
  while(!q.empty())
  {
    int id=q.front(); q.pop(); v[id]=0;
  //  cout << id << ' ';
    for(Arc *p=adj[id];p;p=p->next)
    {
      if(p->rest>0)
      {
        int temp=dis[id]+p->cost;
        if(dis[p->dest]>temp)
        {
          dis[p->dest]=temp;
          preV[p->dest]=id; preE[p->dest]=p;
          if(!v[p->dest]) v[p->dest]=1, q.push(p->dest);
        }
      }
    }
  }
  //cout << endl;
  return dis[T]!=inf;
}
void aug()
{
  //for(int i = 1; i <= T; i++) {
  //  cout << dis[i] << ' ';
  //}
  //cout << endl;

  int tflow=inf;
  for(int i=T;i!=S;i=preV[i])
    if(tflow > preE[i]->rest) tflow = preE[i]->rest;
  for(int i=T;i!=S;i=preV[i])
  preE[i]->rest-=tflow, preE[i]->rev->rest+=tflow;
  maxflow+=tflow;
  mincost+=dis[T]*tflow;
  return ;
}
void MinCostMaxFlow(){
  maxflow = 0;
  mincost = 0;
  while(spfa())
    aug();
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-863F.in","r",stdin);
#endif
  int N, Q;
  cin >> N >> Q;
  rep(i, 1, N+1) l[i] = 1, r[i] = N;
  rep(i , 1, Q+1) {
    int op, a , b, c;
    cin >> op >> a >> b >> c;
    if(op == 1) {
      rep(j, a, b+1) 
        l[j] = max(l[j], c);
    } else {
      rep(j, a, b+1) 
        r[j] = min(r[j], c);
    }
  }
  S = 0; T = 2*N+1;
  rep(i, 1, N+1) 
    rep(j, 1, N+1) 
      add_edge(S, i, 1, j*2-1);
  //cout << "part 1 done!" << endl;
  rep(i, 1, N+1) 
    rep(j, l[i], r[i]+1) 
      add_edge(j,i+N,1,0);
  //cout << "part 2 done!" << endl;
  rep(i, 1, N+1) 
    add_edge(i+N, T, 1, 0);
  //cout << "part 3 done!" << endl;
  MinCostMaxFlow();
  //cout << "maxflow = " << maxflow << endl;
  //cout << "mincost = " << mincost << endl;
  if(maxflow == N) {
    cout << mincost << endl;
  } else {
    cout << -1 << endl;
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

