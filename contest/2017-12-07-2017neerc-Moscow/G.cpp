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

const int MAXN = 1010;

long long r[MAXN][MAXN], c[MAXN][MAXN], a[MAXN][MAXN], countR[MAXN][MAXN], countC[MAXN][MAXN];
int n, m;

void output(long long tmp[MAXN][MAXN]) {
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++)
      cout << tmp[i][j] << " ";
    cout << endl;
  }
}
bool work() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      scanf("%I64d%I64d", &r[i][j], &c[i][j]);
    }
  }
  a[0][0] = 1;
  for (int i = 1; i < n; i ++) {
    a[i][0] = a[i - 1][0] + r[i][0];
  }
  for (int i = 0; i < n; i ++) {
    for (int j = 1; j < m; j ++) {
      a[i][j] = a[i][j - 1] - c[i][j];
    }
  }
//  output(a);
  memset(countR, 0, sizeof(countR));
  memset(countC, 0, sizeof(countC));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      countR[i][j] += a[i][j];
      countR[i + 1][j] -= a[i][j];
      countC[i][j] -= a[i][j];
      countC[i][j + 1] += a[i][j];
    }
  }
  for (int i = 0; i < n; i ++)
    countC[i][0] += countC[i][m];
  for (int j = 0; j < m; j ++)
    countR[0][j] += countR[n][j];
//  output(countC);
//  output(countR);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      if (r[i][j] != countR[i][j] || c[i][j] != countC[i][j]) {
        printf("No\n");
        return true;
      }
    }
  }
  printf("Yes\n");
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  while (work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

