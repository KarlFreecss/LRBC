#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 100;

class abPoint {
  public:
    int pos, flag;
    abPoint(int iPos = 0, int iFlag = 0) {
      pos = iPos;
      flag = iFlag;
    }
};

bool cmp(abPoint a, abPoint b) {
  return a.pos < b.pos;
}

int DFS[MAXN * 4], fa[MAXN], L[MAXN], R[MAXN];
//vector<int> id2DFS[MAXN];
int f[MAXN * 4][20], findMi[MAXN * 4], mi2[20];
vector<int> v[MAXN];
vector<abPoint> abV;
int n, m, t;

void dfs(int x, int depth) {
  L[x] = t;
  DFS[t ++] = depth;
  rep(i, 0, v[x].size()) {
    int y = v[x][i];
    if (fa[y] == -1) {
      fa[y] = x;
      dfs(y, depth + 1);
      DFS[t ++] = depth;
    }
  }
  R[x] = t - 1;
  return;
}

void buildRMQ() {
  int mi = 1;
  rep(i, 0, t)
    f[i][0] = DFS[i];
  rep(j, 1, 20) {
    rep(i, 0, t) {
      if (i + mi < t) {
        f[i][j] = min(f[i][j - 1], f[i + mi][j - 1]);
      } else {
        f[i][j] = f[i][j - 1];
      }
    }
    mi *= 2;
  }
}

int findLCADepth(int x, int y) {
  if (x > y)
    swap(x, y);
  int len = y - x + 1;
  int mi = findMi[len];
  return min(f[x][mi], f[y - mi2[mi] + 1][mi]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1009.in","r",stdin);
#endif
  memset(findMi, 0, sizeof(findMi));
  int mi = 0, val = 1, an, bn, x, y;
  while (val < 4 * MAXN) {
    findMi[val] = mi;
    mi2[mi] = val;
    mi ++;
    val *= 2;
  }
  rep(i, 1, 4 * MAXN)
    findMi[i] = max(findMi[i], findMi[i - 1]);

  while (cin >> n >> m) {
    rep(i, 1, n + 1) {
      v[i].clear();
      fa[i] = -1;
    }
    fa[1] = 1;
    rep(i, 1, n) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    t = 0;
    dfs(1, 1);
    buildRMQ();
    rep(k, 0, m) {
      abV.clear();
      scanf("%d", &an);
      rep(i, 0, an) {
        scanf("%d", &val);
        abV.push_back(abPoint(L[val], 0));
        abV.push_back(abPoint(R[val], 0));
      }
      scanf("%d", &bn);
      rep(i, 0, bn) {
        scanf("%d", &val);
        abV.push_back(abPoint(L[val], 1));
        abV.push_back(abPoint(R[val], 1));
      }
      sort(abV.begin(), abV.end(), cmp);
/*      rep(i, 0, abV.size()) {
        cout << " (" << abV[i].pos << "," << abV[i].flag << ")";
      }
      cout << endl;
*/
      int res = 1;
      an = bn = -1;
      rep(i, 0, abV.size()) {
        if (abV[i].flag == 0) {
          an = abV[i].pos;
        } else if (abV[i].flag == 1) {
          bn = abV[i].pos;
        }
        if (an == -1 || bn == -1)
          continue;
        int lcaDepth = findLCADepth(an, bn);
        res = max(res, lcaDepth);
      }
      printf("%d\n", res);
    }
  }

  return 0;
}

