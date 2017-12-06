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

const int maxN = 300000+13;

int N, K;
ll a[maxN];
ll b[maxN];

bool check(int n) {
  if(n * K > N) return false;
  memset(b,0,sizeof(b));
  int ind = N;
  for(int j = 1; j <= n; j++) {
    b[j] = a[ind];
    ind --;
  }
  if(ind <= 0) return false;
  for(int i = 2; i <= K; i++) {
    for(int j = 1; j <= n; j++) {
      while(b[j] < a[ind]*2ll) {
        ind --;
      }
      if(ind == 0) return false;
      b[j] = a[ind];
      ind --;
    }
  }
  return true;
}

int work() {
  memset(a,0,sizeof(a));
  a[0] = 0ll;
  scanf("%d%d", &N, &K);
  for(int i = 1; i <= N; i++) {
    long long tt;
    scanf("%lld", &tt);
    a[i] = tt;
  }
  if(K == 1) return N;
  sort(a+1, a+N+1);
  int l = 0, r = N / K + 1;
  while(r - l > 1) {
    int mid = (l+r) >> 1;
    if(check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: %d\n" , cas, work());
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

