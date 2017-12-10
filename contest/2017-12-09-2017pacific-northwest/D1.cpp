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

const int MAXN = 5e4 + 100;

class line {
  public:
    int x, y, color;
    line(int iX = 0, int iY = 0, int iColor = 0) {
      x = iX;
      y = iY;
      color = iColor;
    }
};

line l[MAXN];
vector<line> v[MAXN];
vector<line> colorLine[MAXN];
vector<line> DFSXY;
int LID[MAXN], RID[MAXN], DFS[MAXN * 2], fa[MAXN], colorNum[MAXN];
int h[MAXN];
int N, m;

void dfs(int x) {
  DFS[m] = x;
  LID[x] = m;
  m ++;
  for (int i = 0; i < v[x].size(); i ++) {
    int y = v[x][i].y, color = v[x][i].color;
    if (fa[y] == y) {
      fa[y] = x;
      dfs(y);
    }
  }
  DFS[m] = x;
  RID[x] = m;
  m ++;
  return;
}
int getSon(int x, int y) {
  if (fa[x] == y)
    return x;
  else return y;
}
int getFa(int x, int y) {
  if (fa[x] == y)
    return y;
  else return x; 
}
void updata(int pos, int val) {
  while (pos < m) {
    h[pos] += val;
    pos += pos & -pos;
  }
}
int query(int pos) {
  int res = 0;
  while (pos > 0) {
    res += h[pos];
    pos -= pos & -pos;
  }
  return res;
}
int query(int x, int y) {
  if (x > y)
    return 0;
  return query(y) - query(x - 1);
}
bool work() {
  int x, y, color, nSon, nFa;
  cout << "============" << endl;
  if (scanf("%d", &N) != 1) return false;
  for (int i = 1; i <= N; i ++) {
    v[i].clear();
    colorLine[i].clear();
    colorNum[i] = 0;
    fa[i] = i;
  }
  for (int i = 0; i < N - 1; i ++) {
    scanf("%d%d%d", &x, &y, &color);
    l[i] = line(x, y, color);
    v[x].push_back(line(x, y, color));
    v[y].push_back(line(y, x, color));
    colorNum[color] ++;
    colorLine[color].push_back(line(x, y, color));
  }

  m = 1;
  fa[1] = 0;
  dfs(1);

  DFSXY.clear();
  memset(h, 0, sizeof(h));
  for (int i = 1; i <= N; i ++) {
    for (int j = 0; j < colorLine[i].size(); i ++) {
      x = colorLine[i][j].x;
      y = colorLine[i][j].y;
      int nSon = getSon(x, y);
      int nFa = getFa(x, y);
      colorLine[i][j].x = nSon;
      colorLine[i][j].y = nFa;
    }
  }

  for (int i = 1; i <= N; i ++) {
    if (colorNum[i] > 1) {
      cout << "color = " << i << " colorNum = " << colorNum[i] << endl; 
      cout << colorLine[i].size() << endl;
      for (int j = 0; j < colorLine[i].size(); j ++) {
        nSon = colorLine[i][j].x;
        updata(LID[nSon], 1);
      }
      for (int j = 0; j < colorLine[i].size(); j ++) {
        nSon = colorLine[i][j].x;
        int subTreeNum = query(LID[nSon] + 1, RID[nSon] - 1);
        int exSubTreeNum = colorNum[i] - subTreeNum - 1;
        cout << subTreeNum << " " << exSubTreeNum << endl;
        if (subTreeNum != 0 && exSubTreeNum != 0) {
          printf("0\n");
          return true;
        } else if (subTreeNum != 0) {
          DFSXY.push_back(line(LID[nSon], RID[nSon], -1));
        } else if (exSubTreeNum != 0) {
          DFSXY.push_back(line(LID[nSon], RID[nSon], 1));
        } else {
          assert(true);
        }
      } 
      for (int j = 0; j < colorLine[i].size(); j ++) {
        nSon = colorLine[i][j].x;
        updata(LID[nSon], -1);
      }
    }
  }
  for (int i = 0; i < DFSXY.size(); i ++) {
    cout << "DFSXY" << endl;
    x = DFSXY[i].x;
    y = DFSXY[i].y;
    color = DFSXY[i].color;
    cout << x << " " << y << " " << color << endl;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif

  while (work());

  return 0;
}

