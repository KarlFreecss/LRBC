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

vector<pair<ll, ll> > pos;
vector<pair<ll, ll> > neg;

ll delive(ll & ren, const ll cost, ll num, const ll cap) {
  if (ren >= num) {
    ren -= num;
    return 0;
  }
  num -= ren;
  ll times = (num-1) / cap + 1;
  ren = times * cap - num;
  return times * cost * 2;
}

int work(){
  int n, k;
  if (scanf("%d%d", &n, &k) != 2) return 0;

  int x, m;
  ll ans = 0;
  neg.clear();
  pos.clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &m);
    if (x < 0) {
      neg.push_back(make_pair(-x, m));
    } else {
      pos.push_back(make_pair(x, m));
    }
  }

  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  ll ren = 0;
  for (int i = pos.size() - 1; i >= 0; --i) {
    ans += delive(ren, pos[i].first, pos[i].second, k);
  }
  ren = 0;
  for (int i = neg.size() - 1; i >= 0; --i) {
    ans += delive(ren, neg[i].first, neg[i].second, k);
  }
  cout << ans << endl;

  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif

  while (work());

#ifndef ONLINE_JUDGE
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
#endif

  return 0;
}

