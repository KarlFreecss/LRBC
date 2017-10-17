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

int N, K;

int main() {
#ifndef ONLINE_JUDGE
  //freopen("cf-854B.in","r",stdin);
#endif
  cin >> N >> K;
  if(N == K || K==0) {
    cout << 0 << ' ' << 0 << endl;
    return 0;
  }
  int ans1, ans2;
  int tt = (N+2) / 3;
  if(K >= tt) {
    cout << 1 << ' ';
    cout << N - K << endl;
  } else {
    cout << 1 << ' ';
    cout << 2*K << endl;
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

