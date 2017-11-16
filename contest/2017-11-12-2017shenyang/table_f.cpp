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
  //freopen(".in","r",stdin);
#endif
  
  long long last = 1;
  double rate = 1;
  for (int i = 4; i < 100000000; ++i) {
    long long n = 3ll * i * i - 12;
    long long k = sqrt(n);
    if (n - k * k == 0) {
      cout << i << ' ' << n << ' ' << k << ' ';
      printf("%.18lf\n", i * 1./ last);
      last = i;
    }
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

