#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int a,b,f,k;

int main() {
  cin >> a >> b >> f >> k;
  int tb = b;
  int now = 0;
  int ans = 0;
  for(int i = 1; i < k; i++) {
    if(tb < f) {
      cout << -1 << endl;
      return 0;
    }
    if(tb >= a + a - f) {
      tb -= a;
    } else {
      ans ++;
      tb = b - ( a - f );
    } 
    f = a - f;
  }
  if(tb < a)  ans ++;
  if(tb < f || b < a-f) ans = -1;
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}
