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

const int MAXN = 2e5 + 100;

class proposal {
  public:
    char opt;
    int val;
    proposal(char iOpt = '_', int iVal = 0) {
      opt = iOpt;
      val = iVal;
    }
};
proposal pool[MAXN];
double f[MAXN];
int num[MAXN];
int n;

int main() {
#ifndef ONLINE_JUDGE
  freopen("L.in","r",stdin);
#endif
  char opt;
  int val;
  scanf("%d", &n);
  n *= 2;
  for (int i = 0; i < n; i ++) {
    while (true) {
      scanf("%c", &opt);
      if (opt == '+' || opt == '-')
        break;
    }
    scanf("%d", &val);
    pool[i] = proposal(opt, val);
  }
  f[n - 1] = 0;
  num[n - 1] = 0;
  for (int i = n - 2; i >= 0; i --) {
    if (pool[i + 1].opt == '+') {
      f[i] = pool[i + 1].val - pool[i].val + f[i + 1];
      num[i] = num[i + 1] - 1;
    } else {
      f[i] = pool[i + 1].val - pool[i].val + f[i + 1] * num[i + 1] / (num[i + 1] + 1);
      num[i] = num[i + 1] + 1;
    }
  }
  for (int i = 0; i < n; i ++) {
    if (pool[i].opt == '+') {
      printf("%.9lf\n", f[i]);
    }
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

