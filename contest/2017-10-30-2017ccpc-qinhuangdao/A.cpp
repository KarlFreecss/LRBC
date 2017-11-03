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

const int MAXN = 1e5 + 100;

long long s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
//  freopen("A.in","r",stdin);
#endif
  long long n, m, p;
  long long T, res, x, y, sum;
  vector<long long> v;
  scanf("%lld", &T);
  while (T --) {
    v.clear();
    scanf("%lld%lld%lld", &n, &m, &p);
    for (int i = 1; i <= n; i ++) {
      scanf("%lld", &s[i]);
    }
    for (int i = 2; i <= n; i ++) {
      s[i] -= s[1];
      if (s[i] < 0)
        s[i] += m;
    }
    s[1] = 0;
    res = 1e18;
    sum = 0;
//    cout << "===========" << endl;
    for (int i = 0; i < p; i ++) {
      scanf("%lld%lld", &x, &y);
      y -= s[x];
      y %= m;
      if (y < 0)
        y += m;
      if (y != 0)
        y = m - y;
      v.push_back(y);
//      cout << y << endl;
      sum += y;
    }
//    cout << "=============" << endl;
    res = min(res, sum);
    sort(v.begin(), v.end());
//    for (int i = 0; i < v.size(); i ++)
//      cout << v[i] << " ";
//    cout << endl;
    int i = 0;
    long long last = 0;
    while (i < v.size()) {
      sum -= p * (v[i] - last);
      long long count = 0;
//      sum += m;
      count ++;
      i ++;
      while (i < v.size()) {
        if (v[i] != v[i - 1])
          break;
//        sum += m;
        count ++;
        i ++;
      }
      last = v[i - 1];
      res = min(res, sum);
      sum += m * count;
    }
    printf("%lld\n", res);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

