#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 1000+13;

int T,N;
char s[maxN];
int c[maxN];

int main() {
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    scanf("%s", s);
    N = strlen (s);
    int ans = maxN;
    memset(c,-1,sizeof(c));
    rep(i, 0, N) {
      int tt = s[i]-'a'+1;
      if(c[tt] == -1) {
        c[tt] = i;
        continue;
      } else {
        if(ans > i-c[tt]) {
          ans = i-c[tt];
        }
        c[tt] = i;
      }
    }
    memset(c,-1,sizeof(c));
    per(i, 0, N) {
      int tt = s[i]-'a'+1;
      if(c[tt] == -1) {
        c[tt] = i;
        continue;
      } else {
        if(ans > c[tt]-i) {
          ans = i-c[tt];
        }
        c[tt] = i;
      }
    }
    if(ans == maxN) printf("Case #%d: -1\n",cas);
    else printf("Case #%d: %d\n", cas, ans);
  }

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

