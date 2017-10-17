#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 200 + 13;

int N;
int a[maxN];

int main() {
  cin >> N;
  rep(i, 1, N+1) cin >> a[i];
  sort(a+1, a+1+N);
  bool ok = true;
  if(a[1] == a[N]) {
    cout << "NO" << endl;
    return 0;
  }
  for(int i =1 ;i <= N/2; i++) {
    if(a[i] == a[1]) continue;
    ok = false;
    break;
  }
  for(int i =N/2+1 ;i <= N; i++) {
    if(a[i] == a[N]) continue;
    ok = false;
    break;
  }
  if(!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << a[1] << ' ' << a[N] << endl;
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}
