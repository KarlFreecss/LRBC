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

const int maxN = 200000+13;

int BitN;
int N;
int num[3][maxN];
int c[maxN];
int s[maxN];
int pos[maxN];

int query(int n) {
  int ret = 0;
  while(n > 0) {
    ret += s[n];
    n -= n&(-n);
  }
  return ret;
}

void add(int n) {
  while(n < BitN) {
    s[n] ++;
    n += n&(-n);
  }
  return ;
}

ll count(int a[], int b[]) {
  ll ret = 0;
  memset(pos,0,sizeof(pos));
  memset(s,0,sizeof(s));
  for(int i = 1; i <= N; i++) 
    pos[b[i]] = i;
  for(int i = 1; i <= N; i++) {
    int tt = pos[a[i]];
    ret += (ll) query(tt);
    add(tt);
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  scanf("%d", &N);
  BitN = N+1;
  for(int j = 0; j < 3; j++) {
    for(int i = 1; i <= N; i++) {
      scanf("%d", &num[j][i]);
    }
  }
  ll ans = 0ll;
  for(int j = 0; j < 3; j++) {
    ll ta = count(num[j], num[(j+1)%3]);
    ans += ta;
  }
  ans -= (ll)N * (ll)(N-1) / 2;
  ans /= 2;
  printf("%I64d\n", ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

