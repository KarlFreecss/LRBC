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

const int Mod = 1e9 + 7;
const int maxN = 1e5 + 13;

int N;
int in[maxN];

ll quickpow(ll a, int b) {
  ll ret = 1ll;
  if(b == 1) return a;
  while(b) {
    if(b&1) ret = (ret * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-852E.in","r",stdin);
#endif
  scanf("%d", &N);
  rep(i, 1, N) {
    int a,b;
    scanf("%d%d", &a, &b);
    in[a] ++, in[b] ++;
  }
  int sl = 0;
  rep(i, 1, N+1) 
    if(in[i] == 1) sl++;
  ll ans = 0ll;
  ans = (ans + (quickpow(2, N-sl+1) % Mod) * sl % Mod) % Mod;
  ans = (ans + (quickpow(2, N-sl) % Mod) * (N-sl) % Mod) % Mod;
  cout << ans << endl;
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

