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

const int maxN = 10000+13;

int N, a[maxN];
int T;

void work() {
  memset(a, 0, sizeof(a));
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    int xx; scanf("%d", &xx);
    a[xx] = 1;
  }
  int l1 = 0, r1 = 10000+3;
  int l2 = 0, r2 = 10000+3;
  for(int i = 1; i <= 10000; i++) {
    if(a[i] && l1 != 0) {l2 = i; break;}
    if(a[i] && l1 == 0) l1 = i;
  }
  for(int i = 10000; i >= 1; i--) {
    if(a[i] && r1 != 10000+3) {r2 = i; break;}
    if(a[i] && r1 == 10000+3) r1 = i;
  }
  int ans = r1 - l1 + 1 - N;;
  ans -= min(l2 - l1, r1 - r2) - 1;
  //cout << l1 << ' ' << l2 << ' ' << r2 << ' ' << r1 << endl;
  printf("%d\n", ans);
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    work();
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

