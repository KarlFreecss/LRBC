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

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else 
    return gcd(b, a % b);
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("B.in","r",stdin);
#endif

  long long l, r, w;
  cin >> l >> r >> w;
  if (r < w)
    swap(r, w);
  long long gcdVal = gcd(r, w);
  l /= gcdVal;
  r /= gcdVal;
  w /= gcdVal;
  if (l <= r + w - 2)
    cout << "DEADLOCK" << endl;
  else
    cout << "OK" << endl;
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

