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

const int MAXN = 30;

class planet {
  public:
    int H, R, T;
};

planet p[MAXN];
int N;

int check(planet a, int day) {
  day %= a.H;
  if (a.R > a.T) {
    if (day > a.R || day < a.T)
      return 1;
  } else {
    if (a.R < day && day < a.T)
      return 1;
  }
  return 0;
}

void work() {
  int maxD = 0;
  cin >> N;
  for (int i = 0; i < N; i ++) {
    cin >> p[i].H >> p[i].R >> p[i].T;
    maxD = max(maxD, p[i].H);
  }
  maxD *= 1825;
  for (int i = 0; i < maxD; i ++) {
    int j;
    for (j = 0; j < N; j ++) {
      if (check(p[j], i) == 1) {
        break;
      }
    }
    if (j >= N) {
      printf("%d\n", i);
      return;
    }
  }
  printf("impossible\n");
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A1.in","r",stdin);
#endif
  work();
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

