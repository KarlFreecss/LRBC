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

const int MAXK = 25;

int mi2[MAXK];
int k, r, N, K;

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  mi2[0] = 1;
  for (int i = 1; i < MAXK; i ++) {
    mi2[i] = mi2[i - 1] * 2;
  }
  scanf("%d%d", &k, &r);
  N = mi2[k];
  K = N - r;
  N --; 
  double res = 0;
  int len = 2;
  while (len - 1 <= K) {
    double count = 1.0;
    for (int i = 0; i < len - 1; i ++) {
      count *= (K - i);
      count /= (N - i);
    }
    len *= 2;
    res += count;
  }
  printf("%.5lf\n", res);
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

