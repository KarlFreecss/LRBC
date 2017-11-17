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

const int maxN = 2500 + 13;
const int maxE = maxN * 10;

struct Arc {
  int dest, rest;
  Arc *next, *rev;
  Arc(){};
  Arc(int dest, int rest, Arc* next) : dest(dest), rest(rest) , next(next){};
}Npool[maxE], *Nptr, *adj[maxN] , *cur[maxN];

int v[maxN], dis[maxN];
queue<int> q;

bool bfs() {
  memset(v,0,sizeof(v));
  memset(dis, 0xff, sizeof(dis));
  while(!q.empty()) q.pop();
  while(!q.empty()) {
    int id = q.front(); q.pop();
    for(Arc *p = adj[id]; p ; p = p->next) {
      int j = p -> dest;
      if(p->rest && dis[j] == -1) {
        dis[j] = dis[id] + 1; 
        q.push(j);
        if(j == T) return true;
      }
    }
  }
  return false;
}

int aug(int i , int m = inf) {
  if(i == T) return m;
  int ret(0);
  for(Arc *p = cur[i]; p ; p = p->next) {
    int j = p->dest;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen(".in","r",stdin);
#endif

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

