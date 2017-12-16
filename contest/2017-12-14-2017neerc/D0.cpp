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

const int maxN = 100 + 13;

int a , b , c;
vector<int> ori;
int v[maxN][maxN];

bool check(int num, vector<int> x, vector<int> y, vector<int> z) {
  int ta, tb, tc;
  set<pii> xa, xb, xc;
  for(int i = 0; i < num; i++) {
    xa.insert(mk(x[i],y[i]));
    xb.insert(mk(x[i],z[i]));
    xc.insert(mk(y[i],z[i]));
  }
  ta = xa.size();
  tb = xb.size();
  tc = xc.size();
  if(ta == ori[0] && tb == ori[1] && tc == ori[2]) {
    printf("%d\n", num);
    for(int i = 0; i < num; i++) {
      printf("%d %d %d\n", x[i], y[i], z[i]);
    }
    return true;
  } 
  return false;
}
int work() {
  if(scanf("%d", &a) != 1) return 0;
  ori.clear();
  ori.push_back(a);
  for(int i =1 ; i <= 2; i++) {
    scanf("%d", &a);
    ori.push_back(a);
  }
  vector<int> xx = ori;
  sort(all(xx));
  if(xx[0] * xx[1] < xx[2]) {
    printf("-1\n");
    return 1;
  }
  int num = xx[2];
  vector<int> pos[5];
  for(int i = 0; i <= 3; i++) pos[i].clear();
  for(int i = 1; i <= xx[2]; i++) pos[2].push_back(0);
  for(int i = 1; i <= xx[1]; i++) {
    int x = i, y = i;
    if(x > xx[0]) x = xx[0];
    v[x][y] = 1;
    pos[0].push_back(x);
    pos[1].push_back(y);
  }
  int tt = xx[1];;
  for(int i = 1; i <= xx[0]; i++) {
    for(int j = 1; j <= xx[1]; j++) {
      if(v[i][j]) continue;
      v[i][j] = 1;
      pos[0].push_back(i);
      pos[1].push_back(j);
      tt  ++;
      if(tt == num) break;
    }
  }
  int vv[4];
  vector<int> ans[4];
  for(int i = 0; i < 4; i++) ans[i].clear();
  memset(vv, 0, sizeof(vv));
  for(int i = 0; i < 3 ; i++) {
    for(int j = 0; j < 3; j++) {
      if(vv[j]) continue;
      if(ori[i] == xx[j]) {
        vv[j] = 1;
        ans[i] = pos[j];
      }
    }
  }
  for (int i = 0; i < 3; ++i)
  if (ans[i].size() == 0) while(true);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) if(i != j) 
      for(int k = 0; k < 3; k++) if(k != i && k != j) 
        if(check(num, ans[i], ans[j], ans[k])) return 1;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}
