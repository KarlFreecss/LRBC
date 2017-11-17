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

int work(){
  int n;
  if (scanf("%d", &n) != 1) return 0;
  int m = n / 3;
  int k = n % 3;
  int ans = 0;
  if (k == 1) {
    ans = 7 * (m - 1) + 4;
  } else if (k == 2) {
    ans = 7 * m + 1;
  } else ans = 7 * m;
  printf("%d\n", ans);
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  freopen("auxiliary.in","r",stdin);
  freopen("auxiliary.out","w",stdout);

  work();
  //while (work());
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

