#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef unsigned long long ll;

ll N,M;

inline ll cal(const ll& n) {
  ll ret(0);
  ret = ((n * (n-1)) >>1) + n+M;
  return ret;
}

int main()
{
  ll l = 0, r = 2e9;
  cin>>N>>M;
  if(N<=M) {
    cout << N << endl;
    return 0;
  }
  ll ans = min(M,N);
  while(r-l>(ll)1) {
    ll mid = (l+r) >>1;
    if(cal(mid) <= N) {
      l = mid;
    }
    else r = mid;
  }
  for(int i=1 ;i<=10 && l>0;i++ ,l--);
  for(;l>=0;l++)
    if(cal(l) >= N) break;
  cout << l+ans << endl;

  return 0;
}

