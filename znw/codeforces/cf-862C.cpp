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

int N,X;

int main() {
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif
  cin >> N >> X;
  if(N == 1) {
    cout << "YES" << endl;
    cout << X << endl;
    return 0;
  }
  if(N == 2) {
    if(X == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << "0 ";
      cout << X << endl;
    }
    return 0;
  }
  cout << "YES" << endl;
  int ta = 0;
  for(int i = 1; i <= N-3; i++) {
    cout << i << ' ' ;
    ta ^= i;
  }
  cout << (ta^(1<<17)) << ' ' ;
  cout << ((1<<17)^(1<<18)) << ' ' ;
  cout << (X^(1<<18)) << endl;

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

