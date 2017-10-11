#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100000+13;
const int maxM = 300000+13;
const int inf = 0x7f7f7f7f;

struct Arc
{
  int dest,cost;
  Arc *next;
  Arc(){};
  Arc(int dest,int cost,Arc *next):
    dest(dest),cost(cost),next(next){};
}Npool[maxM],*Nptr(Npool);

Arc *adj[maxN];
queue<int>q;
int dis[maxN];
bool v[maxN];
int p[maxN];
int S,N;

inline void add_edge(int s, int t, int c) {
  //cout << s <<' ' << t << ' ' << c << endl;
  adj[s] = new (Nptr++) Arc(t, c, adj[s]);
}

void init() {
  rep(i , 0 , N+5) adj[i] = NULL;
  Nptr = Npool;
}
void spfa()
{
  rep(i, 1, N+1) dis[i] = -inf;
  memset(v,0,sizeof(v));
  while(!q.empty()) q.pop();
  dis[S]=0; v[S]=1; q.push(S);
  while(!q.empty())
  {
    int id=q.front();
    q.pop(); v[id]=0;
    for(Arc *p=adj[id];p;p=p->next)
    {
      int temp=dis[id]+p->cost;
      if(dis[p->dest]<temp)
      {
        dis[p->dest]=temp;
        if(!v[p->dest]) 
          v[p->dest]=1, q.push(p->dest);
      }
    }
  }
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1008.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  rep( cas , 1, T+1) {
    scanf("%d", &N);
    init();
    rep(i, 1, N+1) scanf("%d", &p[i]);
    rep(i, 1, N){
      int a,b,c;
      scanf("%d%d%d", &a, &b, &c);
      add_edge(a,b,-c-p[a]+p[b]);
      add_edge(b,a,-c-p[b]+p[a]);
    }
    S = 0;
    rep(i, 1, N+1) 
      add_edge(S, i, 0);
    spfa();
    int ans = 0;
    rep(i ,1 ,N+1) 
      if(dis[i] > ans) ans = dis[i];
    printf("%d\n", ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

