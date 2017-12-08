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

long long N, K;

void work() {
  long long res = 1e15;
  for (int i = 1; i < K; i ++) {
    long long day = 1, user = i, needUser = N - K + i;
    while (user < needUser) {
      long long tmp = (N - user) / 2;
      tmp = min(tmp, user);
      user += tmp;
      day ++;
    }
    res = min(res, day);
  }
  cout << res << endl;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  while (cin >> N >> K) {
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

