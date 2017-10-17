#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100+13;
const int maxD = 2000+13;

struct gd {
  int t,d,p;
  int id;
  friend bool operator < (const gd& a, const gd& b) {
    return a.d < b.d;
  }
};

int N;
gd xx[maxN];
int f[maxN][maxD];
int pre[maxN][maxD];

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-864E.in","r",stdin);
#endif
  cin >> N;
  rep(i, 1, N+1) {
    cin >> xx[i].t >> xx[i].d >> xx[i].p;
    xx[i].id = i;
  }
  sort(xx+1, xx+1+N);
  rep(i, 1, N+1) {
    rep(j , 1, xx[i].d) {
      if(j < xx[i].t) {
        f[i][j] = f[i-1][j];
        pre[i][j] = 0;
        continue;
      }
      if(f[i-1][j] < f[i-1][j-xx[i].t] + xx[i].p) {
        f[i][j] = f[i-1][j-xx[i].t] + xx[i].p;
        pre[i][j] = i;
      } else {
        f[i][j] = f[i-1][j];
        pre[i][j] = 0;
      }
    }
  }
  int ans = 0, k = -1;
  rep(i, 1, maxD) 
    if(f[N][i] > ans) {
      ans = f[N][i];
      k = i;
    }
  cout << ans << endl;
  vector<int> order;
  per(i, 1, N+1) {
    if(pre[i][k] == 0) continue;
    order.push_back(xx[pre[i][k]].id);
    k -= xx[pre[i][k]].t;
  }
  cout << order.size() << endl;
  per(i, 0,order.size()) 
    cout << order[i] << ' ';
  cout << endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

