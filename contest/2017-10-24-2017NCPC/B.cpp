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

const int maxN = 500 + 13;

struct athletics {
  double t1, t2;
  string name;
  bool friend operator < (const athletics& a, const athletics& b) {
    return a.t2 < b.t2;
  }
};

athletics a[maxN];
int N;

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  cin >> N;
  rep(i, 1, N+1) {
    cin >> a[i].name >> a[i].t1 >> a[i].t2;
    //cout << a[i].name << ' ' << a[i].t1 << ' ' << a[i].t2 << endl;
  }
  sort(a+1, a+N+1);
  double ans = 100000;
  vector<string> aname;
  rep(i, 1, N+1) {
    double ta = a[i].t1;
    vector<string> taname ;
    taname.pb(a[i].name);
    int sn = 0, ind = 1;;
    while(sn < 3) {
      if(ind == i) ind ++;
      ta += a[ind].t2;
      taname.pb(a[ind].name);
      sn++;
      ind++;
    }
    if(ta < ans) {
      ans = ta;
      aname = taname;
    }
  }
  cout << ans << endl;
  for(auto tt:aname) {
    cout << tt << endl;
  }
  return 0;

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

