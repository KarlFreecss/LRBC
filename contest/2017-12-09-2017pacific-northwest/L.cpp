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

double k, p , x;

int main() {
#ifndef ONLINE_JUDGE
#endif
  cin >> k >> p >> x;
  double ans = k * p + x;
  for(int i = 1; i <= 1000000; i++) {
    double tm = i;
    double ta = (k/tm)*p + x * tm;
    if(ta < ans) ans = ta;
  }
  printf("%.3lf\n", ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

