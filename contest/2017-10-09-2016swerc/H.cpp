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

const int MAXD = 100;

set<long long> s;
int D, H;
int a[40];
int res[MAXD];

void dfs(int t, int n, int last) {
  if (t == D) {
    /*
    for (int i = 0; i < D; i ++) {
      cout << a[i] << " ";
    }
    cout << endl;
    */
    memset(res, 0, sizeof(res));
    res[0] = 1;
    for (int i = 1; i < H; i ++) {
      for (int j = 0; j < MAXD; j ++)
        res[j] *= i;
      for (int j = 0; j < MAXD - 1; j ++) {
        res[j + 1] += res[j] / 10;
        res[j] %= 10;
      }
    }
    for (int i = 0; i < D; i ++) {
      for (int val = 1; val <= a[i]; val ++) {
        int tmp = 0;
        for (int j = MAXD - 1; j >= 0; j --) {
          tmp = tmp * 10 + res[j];
          res[j] = tmp / val;
          tmp %= val;
        }
      }
//      cout << tmp << endl;
    }
    long long tmp = 0;
    for (int j = MAXD - 1; j >= 0; j --) {
      tmp = tmp * 10 + res[j];
    }
    s.insert(tmp);
//    cout << res << endl;
  } else if (t == D - 1) {
    a[t] = n;
    dfs(t + 1, 0, n);
  } else {
    for (int i = last; i * (D - t) <= n; i ++) {
      a[t] = i;
      dfs(t + 1, n - i, i);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("H.in","r",stdin);
#endif
  s.clear();
  cin >> D >> H;
  dfs(0, H - 1, 0);
  set<long long>::iterator iter;
  for (iter = s.begin(); iter != s.end(); iter ++) {
    printf("%lld\n", *iter);
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

