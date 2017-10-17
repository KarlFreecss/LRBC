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

inline ll iabs(ll x) {
  if(x < 0) return -x;
  return x;
}

const int maxN = 1e5 + 13;

int N, M, Q;
int a[maxN];
int b[maxN];
ll sum;
vector<ll> sum2;

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-862E.in","r",stdin);
#endif
  scanf("%d%d%d", &N, &M, &Q);
  sum = 0ll;
  rep(i, 1, N+1) {
    scanf("%d", &a[i]);
    if(i&1) sum+= a[i];
    else sum -= a[i];
  }
  ll temp = 0ll;
  rep(i, 1, M+1) {
    scanf("%d", &b[i]);
    if(i <= N) {
      if(i&1) temp -= b[i];
      else temp += b[i];
    } else {
      temp = -temp;
      temp -= b[i-N];
      if(N&1) temp -= b[i];
      else temp += b[i];
    } 
    if(i >= N) sum2.pb(temp);
    //if(i >= N) cout << temp << endl;
  }
  sort(all(sum2));
  int l2,l1;
  ll ans = 0;
  l1 = lower_bound(all(sum2), -sum) - sum2.begin();;
  if(l1 == 0) {
    ans = iabs(sum + sum2[l1]);
  } else {
    l2 = l1 - 1;
    ans = iabs(sum + sum2[l1]);
    ans = min(ans, iabs(sum + sum2[l2]));
  }
  printf("%I64d\n", ans);
  rep(i, 1, Q+1) {
    int l,r,x;
    scanf("%d%d%d", &l, &r, &x);
    if( (r-l+1) % 2) {
      if(l & 1) sum += x;
      else sum -= x;
    } 
    l1 = lower_bound(all(sum2), -sum) - sum2.begin();
    if(l1 == 0) {
      ans = iabs(sum + sum2[l1]);
    } else {
      l2 = l1 - 1;
      ans = iabs(sum + sum2[l1]);
      ans = min(ans, iabs(sum + sum2[l2]));
    }
    printf("%I64d\n", ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

