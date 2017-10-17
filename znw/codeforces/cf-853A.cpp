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

int N,K;
int ans[maxN], c[maxN];
priority_queue<pair<int,int>> q;

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-853A.in","r",stdin);
#endif
  cin >> N >> K;
  ll sum = 0ll;
  rep(i, 1, K+1) {
    cin >> c[i];
    q.push(mk(c[i], i));
  }
  rep(i, 1, N+1-K) {
    cin >> c[i];
    q.push(mk(c[i], i+K));
    pii tp = q.top();q.pop();
    sum += 1ll * tp.fi * (i+K - tp.se);
    ans[tp.se] = i + K;
  }
  rep(i, 1, K+1) {
    pii tp = q.top();q.pop();
    sum += 1ll * tp.fi * (i+N - tp.se);
    ans[tp.se] = i + N;
  }
  cout << sum << endl;
  rep(i, 1, N+1) cout << ans[i] << ' ' ;
  cout << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

