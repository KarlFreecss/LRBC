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

//typedef __int128 ll;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll qmul(ll a, ll b){
  long long H = 1e18;
  H += 1000;
  // a * b > H
  if (b > H / a) return H;
  return a * b;
}

ll qpow(ll a , int b) {
  ll ret = 1ll;
  ll xx = a;
  while(b) {
    if(b&1) ret = qmul(ret, xx);
    xx = qmul(xx, xx);
    b >>= 1;
  }
  return ret;
}

vector<ll> try_ans(ll n, ll a, int m){
  vector<ll> res;
  //cout << n << ' ' << a << ' ' << m << endl;
  for (int i = 0; i <= m; ++i) {
    ll tmp = qmul(qpow(a, i), qpow(a + 1, m-i));
   // cout << tmp << endl;
    if (tmp == n) {
      for (int k = 0; k < i; ++k) res.push_back(a);
      for (int k = 0; k < m-i; ++k) res.push_back(a+1);
      return res;
    } 
  }

  return res;
}

vector<ll> find(ll n, int m){
  ll low = 1, high = n;
  while (low + 1 < high) {
    ll mid = (low + high) / 2;
    ll tmp = qpow(mid, m);
  //  cout << tmp << endl;
   if (tmp <= n) {
     low = mid;
   } else high = mid;
  }
  //cout << low << ' ' << high << endl;
  return try_ans(n, low, m);
}

int work() {
  ll n;
  if(scanf("%I64d", &n) != 1) return 0;
  int s1 = 0;
  ll tt = n;
  for(int i = 1; i <= 70; i++) {
    if(tt&1) s1++;
    tt >>= 1;
  }
  if(s1 == 1){
    printf("-1\n");
    return 1;
  }

  vector<vector<ll>> ans;
  vector<ll> ans_0;
  ans_0.push_back(n);
  ans.push_back(ans_0);
  for(int i = 2; i <= 70; i++) {
    vector<ll> res = find(n, i);
   // cout << __LINE__ << res.size() << endl;
    if (res.size() > 0) ans.push_back(res);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << (long long)ans[i].size();
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ' ' << (long long)ans[i][j];
    }
    cout << endl;
  }
  return 1;
}

int main() {
  //cout << qmul(1234ll * 12345678912334ll, 12334455ll) << endl;
  freopen("little.in","r",stdin);
  freopen("little.out","w",stdout);
  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

