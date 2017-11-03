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

typedef __int64 lll;

const int MAXN = 1010;
const lll BIGSISTER = (long long)1e18 + 1;
lll ingredient[MAXN];
vector<int> st[30], ma[30], de[30];
set<pair<int, int>> uncom;

void readVector(const int n, vector<int> v[30]){
  for (int i = 0; i < n; ++i) {
    int k;
    v[i].clear();
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int x;
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }
}

void mergeVector(vector<int> &v, const vector<int> & a){
  for (int i = 0; i < a.size(); ++i) v.push_back(a[i]);
}

int work(){
  int r, s, m, d, n;
 
  if (scanf("%d%d%d%d%d", &r, &s, &m, &d, &n) != 5) return 0;
  for (int i = 0; i < r; ++i) {
    int b;
    scanf("%d", &b);
    ingredient[i] = b;
  }

  readVector(s, st);
  readVector(m, ma);
  readVector(d, de);

  uncom.clear();
  for (int i = 0; i < n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    uncom.insert(make_pair(x-1, y-1));
    uncom.insert(make_pair(y-1, x-1));
  }

  lll ans = 0;
  for (int si = 0; si < s; ++si) {
    for (int mi = 0; mi < m; ++mi) {
      if (uncom.count(make_pair(si, mi + s))) continue;
      for (int di = 0; di < d; ++di) {
        if (uncom.count(make_pair(si, di + s + m))) continue;
        if (uncom.count(make_pair(mi + s, di + s + m))) continue;
        vector<int> v;
        mergeVector(v, st[si]);
        mergeVector(v, ma[mi]);
        mergeVector(v, de[di]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        lll count = 1;
        for (int i = 0; i < v.size(); ++i) {
          if (BIGSISTER / count >= ingredient[v[i]-1]) {
            count *= ingredient[v[i]-1];
          } else {
            count = BIGSISTER;
          }
        }
        if (BIGSISTER - ans >= count) {
          ans += count;
        } else {
          ans = BIGSISTER;
        }
      }
    }
  }
  if (ans > (long long)1e18) puts("too many");
  else {
    long long _ans = ans;
    cout << _ans << endl;
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif

  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

