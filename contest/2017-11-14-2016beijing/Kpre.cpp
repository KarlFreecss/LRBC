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
#ifndef ONLINE_JUDGE
  freopen("Kpre.out","w",stdout);
#endif
  long long n = 1e9 + 2e8;
  long long c = 0;
  long long num = 0;
  long long k = 1e8;
  for (long long i = 1; i <= n; i ++) {
    if (i % k == 0) {
//      cout << "-----------" << i << endl;
    }
    long long tmp = i;
    while (tmp > 0) {
      if (tmp % 10 == 1) {
        c ++;
      }
      tmp /= 10;
    }
    if (c == i) {
      num ++;
      printf("a[%I64d] = %I64d;\n", num, i);
//      cout << num << " " << i << endl;
    }
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

