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

int main() {

  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    long long n;
    scanf("%lld", &n);
    if (n % 3 == 0) {
      long long ans = n / 3;
      printf("%lld %lld %lld\n", ans, ans, ans);
    } else if (n % 4 ==0) {
      long long ans = n / 4;
      printf("%lld %lld %lld\n", ans * 2, ans, ans);
    } else {
      puts("IMPOSSIBLE");
    }
  }

  return 0;
}

