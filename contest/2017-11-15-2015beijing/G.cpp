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

struct rect {
  int x[2];
  void read() {
    scanf("%d%d", &x[0], &x[1]);;
  }
};

rect a[maxN];

bool find(int xx, int id1, int id2) {
  for(int i = 1; i <= 4; i++) {
    if(i == id1) continue;
    if(i == id2) continue;
    if(a[i].x[0] == xx) return true;
    if(a[i].x[1] == xx) return true;
  }
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    for(int i = 1; i <= 4; i++) a[i].read();
    bool ok = false;
    for(int i = 1; i <= 4; i++) {
      for(int j = 1; j <= 4; j++) if(i != j) {
        for(int id1 = 0; id1 < 2; id1 ++) {
          for(int id2 = 0; id2 < 2; id2 ++) {
            if(a[i].x[id1] == a[j].x[id2]) {
              int ta = a[i].x[id1^1] + a[j].x[id2^1];
              if(find(ta, i , j)) {
                ok = true;
              }
              if(find(a[i].x[id1],i,j)) ok = true;
            }
          }
        }
      }
    }
    if(ok) printf("Yes\n");
    else printf("No\n");
  }

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

