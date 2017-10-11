#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100000 + 13;

int N;
int inp[maxN],inap[maxN];
int p[maxN] , ap[maxN];
int rp[maxN];
int v[maxN];
int b[maxN];
int ans = 0;

void fuck(int id) {
  if(b[id] == 1) return;
  if(inp[id] == 0) id = p[id];;
  while(id != 0) {
    if(b[id] == 1) break;
    b[id] = 1;
    ans ++;
    id = p[id];
  }
  return ;
}

void work(int tt) {
  while(p[tt] == ap[tt]) {
    if(p[tt] == 0) break;
    if(b[p[tt]] == 1) break;
    tt = p[tt];
  }
  //cout << "id : " << tt << endl;
  fuck(p[tt]);
  //cout << "part 1 : " << ans << endl;
  tt = ap[tt];
  while(tt != 0) {
    if(!b[tt]) fuck(tt);
    ans ++;
    tt = ap[tt];
  }
  //cout << "part 2 : " << ans << endl;
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  while(scanf("%d", &N) != EOF) {
    memset(inp, 0 ,sizeof(inp));
    memset(inap, 0 ,sizeof(inap));
    memset(b, 0 ,sizeof(b));
    //cout << N << endl;
    ans = 0;
    rep(i, 1 , N+1) {
      scanf("%d", &p[i]);
      inp[p[i]] ++;
    }
    rep(i, 1 , N+1) {
      scanf("%d", &ap[i]);
      inap[ap[i]] ++;
    }
    rep(i, 1 , N+1) 
      if(inp[i] == 0 && p[i] == 0) b[i] = 1;
    memset(v,0,sizeof(v));
    rep(i, 1, N+1) {
      if(inap[i] == 0) {
        //if(b[i]) continue;
        //cout << i << ":" << endl;
        work(i);
        //cout << ans << endl;
        //cout << endl;
      }
    }
    printf("%d\n", ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

