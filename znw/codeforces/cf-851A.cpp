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

ll N, K, T;

int main() {
#ifndef ONLINE_JUDGE
  //freopen("cf-851A.in","r",stdin);
#endif
  cin >> N >> K >> T;
  ll p1, p2;
  p1 = K;
  p2 = N;
  if(T <= p1) {
    cout << T << endl;
  } else if(T <= p2) {
    cout << K << endl;
  } else {
    cout << K - T + p2 << endl; 
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

