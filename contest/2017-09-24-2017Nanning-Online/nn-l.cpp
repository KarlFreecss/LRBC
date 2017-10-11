#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x7f7f7f7f;
vector<int> xx;

int main() {
#ifndef ONLINE_JUDGE
  freopen("nn-l.in","r",stdin);
#endif
  int tt;
 // xx.push_back(-inf);
  while(scanf("%d", &tt) != EOF) {
    if(tt < 0) continue;
    if(tt >= 10000) {
      rep(i, 1, 6)xx.push_back(tt-10000);
    } else xx.push_back(tt);
  }
  int n = xx.size();
  //for(auto i:xx) 
  //  cout << i << ' ';
  //cout << endl;
  vector<int> a(n+1, inf);

  for(auto i:xx) {
    *upper_bound(all(a), i) = i;
    //for(auto j:a) 
    //  cout << j << ' ';
    //cout << endl;
  }
  int ans = 0;
  rep(i, 0, n+1) {
    if(a[i] == inf) {ans = i;break;}
  }
  printf("%d\n", ans);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

