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

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif
  int T, x, y;
  scanf("%d", &T);
  while (T --) {
    scanf("%d%d", &x, &y);
//    if (min(x, y) > 50000) {
//      while (true) {
//      }
//    } else {
      printf("3\n");
      printf("%d %d\n", 0, 0);
      printf("%d %d\n", x, y);
      if (x < y) {
        printf("0 1\n");
      } else {
        printf("1 0\n");
      }
//    }
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

