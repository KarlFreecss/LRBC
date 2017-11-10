#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;


using namespace std;

const int maxN = 40000 + 13;
const int maxE = 200000 + 13;
const int inf = 0x7f7f7f7f;

struct Arc {
  int dest,rest,cost;
  Arc *next, *rev;
  Arc(){};
  Arc(int dest, int rest, int cost, Arc* next) : dest(dest), rest(rest), cost(cost), next(next){};
}Npool[maxE], *Nptr;

Arc *adj[maxN];

inline void add_edge(int st, int ed, int r, int cost) {
  //cout << st << " -> " << ed << " rest = " << r << " cost = " << cost << endl;
  adj[st] = new (Nptr++) Arc(ed, r, cost, adj[st]);
  adj[ed] = new (Nptr++) Arc(st, 0, -cost, adj[ed]);
  adj[st] -> rev = adj[ed];
  adj[ed] -> rev = adj[st];;
  return ;
}

Arc* preE[maxN];
int dis[maxN], preV[maxN], imincost(0), maxflow(0);
int v[maxN], S, T;
queue<int> q;

bool spfa() {
  memset(dis, inf , sizeof(dis));
  memset(v, 0, sizeof(v));
  while(!q.empty()) q.pop();
  dis[S] = 0; v[S] = 1; q.push(S);
  while(!q.empty()) {
    int id = q.front(); q.pop(); v[id] = 0;
    for(Arc* p = adj[id]; p ; p=p->next) {
      if(p->rest > 0) {
	int temp = dis[id] + p -> cost;
	if(dis[p->dest] > temp) {
	  dis[p->dest] = temp;
	  preV[p->dest] = id; 
	  preE[p->dest] = p;
	  if(!v[p->dest]) v[p->dest] = 1, q.push(p->dest);
	}
      }
    }
  }
  return dis[T] != inf;
}
void aug() {
  int tflow = inf;
  for(int i = T; i != S; i = preV[i]) 
    if(tflow > preE[i]->rest) tflow = preE[i]->rest;
  for(int i = T; i != S; i = preV[i]) {
    preE[i]->rest -= tflow;
    preE[i]->rev->rest += tflow;
  }
  maxflow += tflow;
  imincost += dis[T] * tflow;
  return ;
}

void MinCostMaxFlow() {
  maxflow = 0;
  imincost = 0;
  while(spfa()) aug();
  return ;
}

void init(int n) {
  for(int i = 0; i <= n; i++) adj[i] = NULL;
  Nptr = Npool;
}

void work(){
  int n;
  scanf("%d", &n);
  init(n*2 + 8);

  map<string, int> airportID;
  char buff1[255], buff2[255];
  int cityNum = 1;
  for (int i = 0; i < n; ++i) {
    string city1, city2;
    int cost;
    scanf("%s%s%d", buff1, buff2, &cost);
    city1 = buff1;
    city2 = buff2;

    int cN1, cN2;
    if (airportID.count(city1) == 0) {
      airportID[city1] = cityNum++;
      //cout << city1 << ' ' << cityNum -1 << endl;;
    }
    if (airportID.count(city2) == 0) {
      airportID[city2] = cityNum++;
      //cout << city2 << ' ' << cityNum -1 << endl;;
    }
    cN1 = airportID[city1];
    cN2 = airportID[city2];
    add_edge(cN1 * 2, cN2 * 2 - 1, 10086, cost);
    add_edge(cN2 * 2, cN1 * 2 - 1, 10086, cost);
  }

  for (int i = 1; i < cityNum; ++i) {
    add_edge(i * 2 - 1, i * 2, 1, 0);
  }
  
  int idXian = airportID["Xian"];
  int idQingdao = airportID["Qingdao"];
  int idHongqiao = airportID["Hongqiao"];
  int idPudong = airportID["Pudong"];
  S = 0 ; T = cityNum * 2 + 6;
  add_edge(idQingdao * 2 - 1, idQingdao * 2, 1, 0);
  add_edge(idHongqiao * 2 - 1, idHongqiao * 2, 1, 0);
  add_edge(S, idXian * 2 - 1, 1, 0);
  add_edge(S, idQingdao * 2 - 1, 2, 0);
  add_edge(idHongqiao * 2, T, 2, 0);
  add_edge(idPudong * 2, T, 1, 0);
  MinCostMaxFlow();
  if(maxflow == 3) {
    printf("%d\n", imincost);
  } else {
    printf("-1\n");
  }
}

int main(){
  int T;
  scanf("%d", &T);
  //T = 1;
  for (int i = 0; i < T; ++i) {
    work();
  }
}
