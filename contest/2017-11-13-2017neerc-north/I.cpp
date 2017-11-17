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

vector<pair<int, int>> p;

int main() {
  freopen("intel.in","r",stdin);
  freopen("intel.out","w",stdout);

  int n;
  scanf("%d", &n);
  int minX = 1e6+6;
  int minY = 1e6+6;
  int maxX = -1e6-6;
  int maxY = -1e6-6;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    p.push_back(make_pair(x, y));
    minX = min(minX, x);
    minY = min(minY, y);
    maxX = max(maxX, x);
    maxY = max(maxY, y);
  }
  p.push_back(p[0]);

  for (int i = 1; i < p.size(); ++i) {
    ans = ans + abs(p[i].first - p[i-1].first) + abs(p[i].second - p[i-1].second);
  }
  ans -= 2 * (maxX - minX) + 2 * (maxY - minY);
  
  cout << ans << endl;
  //cerr << ans << endl;
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

