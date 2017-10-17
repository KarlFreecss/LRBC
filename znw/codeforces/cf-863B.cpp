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

const int maxN = 200 + 13;

int N;
int w[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-863B.in","r",stdin);
#endif
  int ans = 100000000;
  cin >> N; N <<= 1;
  rep(i,1,N+1) cin >> w[i];
  rep(i,1,N+1) {
    rep(j,i+1, N+1) {
      vector<int> xx;
      rep(k, 1, N+1) 
        if(k != i && k != j) xx.pb(w[k]);
      sort(all(xx));
      int ta = 0;
      rep(k, 0, N-2) {
        ta += xx[k+1] - xx[k];
        k++;
      }
      if(ta < ans) ans = ta;
    }
  }
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

