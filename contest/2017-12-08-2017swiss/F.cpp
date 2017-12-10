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

const int maxN = 50 + 3;
const int maxD = 365 + 3;
const int maxM = 5000+3;
const int inf = 0x7f7f7f7f;

struct Op {
  int b, e, c, h,id;
  Op(){};
  void read() {
    scanf("%d", &h);
    scanf("%d%d%d", &b, &e, &c);
    return ;
  }
  friend bool operator < (const Op& x, const Op& y) {
    return x.e < y.e;
  }
};

Op o[maxM];
int Y, N, S;
int H, M;
int f[maxD][maxN][maxN], g[maxD][maxN][maxN];
int pref[maxD][maxN][maxN], preg[maxD][maxN][maxN];

template<typename T>
bool upd_min(T& dest, T src) {
  if(dest > src) {
    dest = src;
    return true;
  }
  return false;
}

bool work() {
  if(scanf("%d%d%d", &Y, &N, &S) != 3) return 0;
  scanf("%d%d", &H, &M);
  for(int i = 1; i <= M; i++) {
    o[i].read();
    o[i].id = i;
  }

  sort(o+1, o+1+M);
  int ind = 1;
  memset(f,inf, sizeof(f));
  memset(g,inf, sizeof(g));
  f[0][0][0] = 0;
  g[0][0][0] = 0;
  for(int i = 1; i <= Y; i++) {
    for(int k = 0; k <= N; k++) 
      for(int j = 0; j <= H; j++) 
        if(upd_min(f[i][0][k], f[i-1][j][k])) 
          pref[i][0][k] = j * 100 + k;
    for(int k = 0; k <= S; k++) 
      for(int j = 0; j <= H; j++) 
        if(upd_min(g[i][0][k], g[i-1][j][k])) 
          preg[i][0][k] = j;
    while(o[ind].e-1 == i && ind <= M) {
      int st = o[ind].b, ed = o[ind].e-1;
      int ht = o[ind].h;
      for(int k = 0; k < N; k++) {
        int newd = k + ed - st + 1;
        if(newd > N) newd = N;
        for(int j = 0; j <= H; j++) {
          if(j == ht) continue;
          if(upd_min(f[i][ht][newd], f[st-1][j][k]+o[ind].c)) {
            pref[i][ht][newd] = ind * 10000 + j * 100 + k;
          }
        }
      }
      for(int k = 0; k < S; k++) {
        for(int j = 0; j <= H; j++) {
          if(j == ht) continue;
          if(upd_min(g[i][ht][k+1], g[st-1][j][k]+o[ind].c)) {
            preg[i][ht][k+1] = ind*100 + j;
          }
        }
      }
      ind ++;
    }
  }
  int ansf, ansg;
  int no;
  //no = ansf = ansg = (long long) inf  * inf;
  no = ansf = ansg = inf;
  for(int k = N; k <= N; k++) 
    for(int j = 0; j <= H; j++) 
      if(ansf > f[Y][j][k]) {
        ansf = f[Y][j][k];
      }
  for(int k = S; k <= S; k++) 
    for(int j = 0; j <= H; j++) 
      if(ansg > g[Y][j][k]) {
        ansg = g[Y][j][k];
      }
  //cout << ansf << ' ' << ansg << endl;
  if(ansf == ansg && ansf == no) {
    printf("IMPOSSIBLE\n");
  } else if(ansf < ansg) {
    printf("NIGHTS\n");
    int ak, aj;
    vector<int> ans; 
    ans.clear();
    for(int k = N; k <= N; k++) 
      for(int j = 0; j <= H; j++) {
        if(ansf == f[Y][j][k]) {
          ak = k; aj = j;
          break;
        }
      }
    int day = Y;
    while(day > 0) {
      int tt = pref[day][aj][ak];
      int id = tt/10000, ht = (tt/100) % 100;
      int td = tt % 100;
      if(id == 0) {
        day --;
        aj = ht;
        continue;
      } else {
        day = o[id].b-1;
        aj = ht;
        ak = td;
        ans.push_back(o[id].id);
      }
    }
    //sort(all(ans));
    printf("%d\n", (int)ans.size());
    printf("%d", ans[ans.size()-1]);
    for(int i = ans.size()-2; i >=0 ; i--) 
      printf(" %d", ans[i]);
    printf("\n");
  } else {
    printf("STAYS\n");
    int ak, aj;
    vector<int> ans; 
    ans.clear();
    for(int k = S; k <= S; k++) 
      for(int j = 0; j <= H; j++) {
        if(ansg == g[Y][j][k]) {
          ak = k; aj = j;
          break;
        }
      }
    int day = Y;
    while(day > 0) {
      int tt = preg[day][aj][ak];
      int id = tt/100, ht = tt % 100;
      if(id == 0) {
        day --;
        aj = ht;
        continue;
      } else {
        day = o[id].b-1;
        aj = ht;
        ak -= 1;
        ans.push_back(o[id].id);
      }
    }
    //sort(all(ans));
    printf("%d\n", (int)ans.size());
    printf("%d", ans[ans.size()-1]);
    for(int i = ans.size()-2; i >=0 ; i--) 
      printf(" %d", ans[i]);
    printf("\n");
  }
  return true;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  while(work());
  return 0;
}

