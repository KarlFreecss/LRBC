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

const int MAXN = 15;
const int MAXSTATE = 1e4;

int a[MAXN], mi2[MAXN];
int SA[MAXN], newSA[MAXN];
double f[MAXSTATE];
int N;

double calS(int x, int y, int z) {
  int sum = x + y + z;
  int maxVal = max(x, y);
  maxVal = max(maxVal, z);
  if (maxVal >= (sum - maxVal)) {
    return 0.0;
  } else {
    double mid = 1.0 * (x + y + z) / 2;
    return sqrt(mid * (mid - x) * (mid - y) * (mid - z));
  }
  return 0.0;
}

void work() {
  for (int i = 0; i < N; i ++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < mi2[N]; i ++) {
    f[i] = -1.0;
  }
  double res = 0.0;
  f[0] = 0.0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int state = q.front();
    res = max(res, f[state]);
    q.pop();
    int tmp = state;
    for (int i = N - 1; i >= 0; i --) {
      SA[i] = (tmp & 1);
      tmp /= 2;
    }
    for (int x1 = 0; x1 < N; x1 ++) {
      for (int x2 = x1 + 1; x2 < N; x2 ++) {
        for (int x3 = x2 + 1; x3 < N; x3 ++) {
          if (SA[x1] == 0 && SA[x2] == 0 && SA[x3] == 0) {
            int newState = 0;
            for(int i = 0; i < N; i ++)
              newSA[i] = SA[i];
            newSA[x1] = 1;
            newSA[x2] = 1;
            newSA[x3] = 1;
            for (int i = 0; i < N; i ++) {
              newState <<= 1;
              newState += newSA[i];
            }
            if (f[newState] < -0.5) {
              q.push(newState);
            }
            double S = calS(a[x1], a[x2], a[x3]);
            f[newState] = max(f[newState], f[state] + S);
/*            for (int i = 0; i < N; i ++)
              cout << newSA[i] << " ";
            cout << endl;
            cout << f[state] << " " << f[newState] << endl;
*/          } 
        }
      }
    }
  }
  printf("%.2lf\n", res);
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif
  mi2[0] = 1;
  for (int i = 1; i < MAXN; i ++)
    mi2[i] = mi2[i - 1] * 2;
  while (scanf("%d", &N)) {
    if (N == 0)
      break;
    work();
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

