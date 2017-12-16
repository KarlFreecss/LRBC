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

const int MAXN = 2010;

char s[MAXN];
int a[MAXN];
vector<vector<vector<vector<int>>>> f;
int n, m, len;

bool work() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  scanf("%s", s);
  len = strlen(s);
  if ((n * m + m - 1) > len) {
    printf("-1\n");
    return true;
  }
  for (int i = 0; i < len; i ++) {
    if (s[i] == 'D') {
      a[i + 1] = 0;
    } else {
      a[i + 1] = 1;
    }
  }
  f.resize(len + 1);
  for (int i = 0; i <= len; i ++) {
    f[i].resize(m + 1);
    for (int j = 0; j <= m; j ++) {
      f[i][j].resize(n + 1);
      for (int k = 0; k <= n; k ++) {
        f[i][j][k].resize(2);
        for (int l = 0; l <= 1; l ++)
          f[i][j][k][l] = len + 1;
      }
    }
  }
  f[0][0][0][0] = 0;
  for (int i = 0; i < len; i ++) {
    for (int j = 0; j <= m; j ++) {
      for (int k = 0; k <= n; k ++) {
        for (int l = 0; l <= 1; l ++) {
          if (f[i][j][k][l] > len)
            continue;
    //      cout << i << " " << j << " " << k << " " << l << " " << f[i][j][k][l] << endl;
          for (int nl = 0; nl <= 1; nl ++) {
            int tA = a[i + 1] ^ nl, nj, nk, nVal;
            if (tA == 0) {
              nj = j;
              nk = k + 1;
              if (nk >= n) {
                nk = n;
              }
            } else {
              if (k >= n) {
                nj = j + 1;
                if (nj >= m) {
                  nj = m;
                }
              } else 
                nj = j;
              nk = 0;
            }
            nVal = f[i][j][k][l];
         //   cout << i + 1 << " " << nj << " " << nk << " " << nl << " " << f[i + 1][nj][nk][nl] << endl;
            if (l == 0 && nl == 1) {
              nVal ++;
            }
            f[i + 1][nj][nk][nl] = min(f[i + 1][nj][nk][nl], nVal);
          }
        }
      }
    }
  }
  int res = len + 1;
  for (int j = 0; j <= m; j ++) {
    for (int k = 0; k <= n; k ++) {
      for (int l = 0; l <= 1; l ++) {
        int tmp = j;
        if (k >= n)
          tmp ++;
        if (tmp >= m)
          res = min(res, f[len][j][k][l]);
      }
    }
  }
  printf("%d\n", res);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif

  while (work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

