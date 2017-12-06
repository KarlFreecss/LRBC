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

void work() {
  long long N;
  cin >> N;
  N *= 2;
  long long M = sqrt(N), start;
  if (M - 100 < 1)
    start = 1;
  else start = M - 100;
  for (long long i = start; i <= M + 100; i ++) {
    if (i * (i + 1) > N) {
      cout << i * (i - 1) / 2 << endl;
      return;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t ++) {
    printf("Case #%d: ", t);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

