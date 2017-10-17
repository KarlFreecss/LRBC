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

const int maxN = 100 + 13;

int n,x;
int a[maxN];
int v[maxN];

int main() {
  cin >> n >> x;
  rep(i , 1, n+1) {
    cin >> a[i];
    v[a[i]] = 1;
  }
  int ans = 0;
  rep(i, 0, x) {
    if(v[i] == 0) ans ++;
  }
  if(v[x] == 1) ans++;
  cout << ans << endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

