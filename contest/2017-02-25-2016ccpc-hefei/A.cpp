#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 2500;

char mat[MAXN][MAXN];
int outLink[MAXN], a[MAXN];
int n, m;

bool big(int x, int y) {
  if (mat[x][y] == 'P')
    return true;
  else return false;
}
bool small(int x, int y) {
  if (mat[x][y] != 'P')
    return true;
  else return false;
}
void checkTrans() {
//  cout << "===========" << endl;
  char c;
  int n, sum, id;
  scanf("%d", &n);
  rep(i, 1, n + 1) {
    scanf("%c", &c);
    rep(j, 1, n + 1) {
      scanf("%c", &mat[i][j]);
    }
  }
  memset(outLink, 0, sizeof(outLink));
  rep(i, 1, n + 1) {
    sum = 0;
    rep(j, 1, n + 1)
      if (mat[i][j] != '-') {
        sum ++;
      }
    if (outLink[sum] != 0) {
      printf("N\n");
      return;
    } else {
      outLink[sum] = i;
    }
  }
//  rep(i, 0, n)
//    cout << outLink[i] << " ";
//  cout << endl;
  memset(a, 0, sizeof(a));
  m = 0;
  per(i, 0, n) {
    id = outLink[i];
    int j;
    for (j = 0; j < m; j ++)
      if (big(a[j], id))
        break;
    per(k, j, m) {
      if (small(a[k], id)) {
        printf("N\n");
        return;
      }
      a[k + 1] = a[k];
    }
    a[j] = id;
    m ++;
//    for (j = 0; j < m; j ++)
//      cout << a[j] << " ";
//    cout << endl;
  }
  printf("T\n");
  return;
}
int main()
{
#ifndef ONLINE_JUDGE
//  freopen("A.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T --) {
    checkTrans();
  }

  return 0;
}

