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

const int maxN = 1000+13;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int s[maxN][maxN], N, K;

map<pair<int,int>, int> hs;
set<pair<int,int>> sp;

inline int cal(int x, int y) {
  int ret = 5;
  if(x == 1 || x == N) ret --;
  if(y == 1 || y == N) ret --;
  return ret;
}
void work() {
  scanf("%d%d", &N, &K);
  memset(s,-1,sizeof(s));
  hs.clear();
  sp.clear();
  int fz = 0, fm = 0;
  fm = (N-2) * 4 * 4 + 12;
  fm += (N-2) * (N-2) * 5;
  fz = (N-2) * 4 * 2 + 9;
  fz += 5 * (N-2) * (N-1) /2;
  for(int i = 1; i <= K; i++) {
    int x,y; scanf("%d%d", &x, &y);
    x++; y++;
    sp.insert(make_pair(x,y));
  }
  for(auto tt:sp) {
    int x = tt.first;
    int y = tt.second;
//    cout << x << ' ' << y << endl;
    fm -= cal(x,y);
    if(x + y - 2 >= N-1) fz -= cal(x,y);
    for(int k = 0; k < 4; k++) {
      int tx = dx[k] + x;
      int ty = dy[k] + y;
      if(tx == 0 || ty == 0) continue;
      if(tx == N+1 || ty == N+1) continue;
      if(sp.count(make_pair(tx,ty)) == 0) {
        fm --;
        if(tx + ty -2 >= N-1) fz--;
      }
    }
//    cout << fz << ' ' << fm << endl;
  }
  int gcd = __gcd(fz, fm);
  fz /= gcd;
  fm /= gcd;
  printf("%d/%d\n", fz, fm);
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("M.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: ", cas);
    work();
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

