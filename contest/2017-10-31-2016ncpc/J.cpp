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

int n1, n2;
int res1 , res2, res3;

int iabs(int x) {
  if(x < 0 ) return -x;
  return x;
}

vector<int> xx;
int main() {
#ifndef ONLINE_JUDGE
#endif
  sort(all(xx));
  cin >> n1 >> n2;
  res1 = n2 - n1;
  res2 = n2 - n1 + 360;
  res3 = n2 - n1 - 360;
  int ans = 0;
  if(iabs(res1) <= iabs(res2) && iabs(res1) <= iabs(res3)) {
    if(res1 == -180) res1 = 180;
    ans = res1;
  } else {
    if(iabs(res2) <= iabs(res3)) {
      if(res2 == -180) res2 = 180;
      ans = res2;
    } else {
      if(res3 == -180) res3 = 180;
      ans = res3;
    }
  }
  cout << ans << endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

