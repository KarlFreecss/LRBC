#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;

class line {
  public:
    int x, y, color;
    line(int iX = 0, int iY = 0, int iColor = 0) {
      x = iX;
      y = iY;
      color = iColor;
    }
};

map<int, int> inCycle[MAXN];
map<int, int> colorCount[MAXN];
map<int, int> lineColor[MAXN];
map<int, int> cycleColor;
vector<line> v[MAXN];
vector<line> a;
int fa[MAXN], count1[MAXN];
int N, M, cycleN, res;

void updata(int x, int y, int iColor, int color) {
  colorCount[x][color] ++;
  colorCount[y][color] ++;
  lineColor[x][y] = color;
  lineColor[y][x] = color;
  if (inCycle[x][y] == 1) {
    cycleColor[color] ++;
  }
}

void setInCycle(int x, int y) {
 // cout << "inCycle = " << x << " " << y << endl;
  inCycle[x][y] = 1;
  inCycle[y][x] = 1;
  cycleN ++;
}

void changeRes(int x, int y, int color, int val) {
  if (colorCount[x][color] == 0 && colorCount[y][color] == 0) {
    res += val;
  } else if (colorCount[x][color] != 0 && colorCount[y][color] != 0) {
    res -= val;
  }
}
void work() {
  int x, y, color;
  cycleN = 0;
  scanf("%d%d", &N, &M);
  a.clear();
  cycleColor.clear();
  for (int i = 1; i <= N; i ++) {
    v[i].clear();
    inCycle[i].clear();
    colorCount[i].clear();
    lineColor[i].clear();
    fa[i] = i;
    count1[i] = 0;
  }
  for (int i = 1; i <= N; i ++) {
    scanf("%d%d%d", &x, &y, &color);
    a.push_back(line(x, y, color));
    v[x].push_back(line(x, y, color));
    v[y].push_back(line(y, x, color));
    lineColor[x][y] = color;
    lineColor[y][x] = color;
  }
  fa[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < v[x].size(); i ++) {
      int y = v[x][i].y;
      if (y != fa[x] && cycleN == 0) {
	if (fa[y] != y) {
	  setInCycle(x, y);
	  int tmp = x, tmpFa;
	  while (tmp != 0) {
	    count1[tmp] ++;
	    tmp = fa[tmp];
	  }
	  tmp = y;
	  while (tmp != 0) {
	    count1[tmp] ++;
	    tmp = fa[tmp];
	  }
	  tmp = x;
	  while (count1[tmp] != 2) {
	    tmpFa = fa[tmp];
	    setInCycle(tmp, tmpFa);
	    tmp = tmpFa;
	  }
	  tmp = y;
	  while (count1[tmp] != 2) {
	    tmpFa = fa[tmp];
	    setInCycle(tmp, tmpFa);
	    tmp = tmpFa;
	  }

	} else {
	  fa[y] = x;
	  q.push(y);
	}
      }
    }
  }
  
  res = 0;
  for (int i = 0; i < N; i ++) {
    x = a[i].x; y = a[i].y; color = a[i].color;
    if (inCycle[x][y] == 1) {
      cycleColor[color] ++;
    }
    if (inCycle[x][y] == 1 && cycleColor[color] == cycleN) {
    } else {
      changeRes(x, y, color, 1);
/*      if (colorCount[x][z] == 0 && colorCount[y][z] == 0)
	res ++;
      else if (colorCount[x][z] != 0 && colorCount[y][z] != 0)
	res --;
*/
    }
    colorCount[x][color] ++;
    colorCount[y][color] ++;
//    cout << x << " " << y << " " << color << endl;
  }
  for (int i = 1; i <= M; i ++) {
//    cout << "================" << endl;
    scanf("%d%d%d", &x, &y, &color);
    int iColor = lineColor[x][y];
    colorCount[x][iColor] --;
    colorCount[y][iColor] --;
    if (inCycle[x][y] == 1)
      cycleColor[iColor] --;

    if (inCycle[x][y] == 1 && cycleColor[iColor] == cycleN - 1) {
    } else {
//      cout << "before " <<  colorCount[x][iColor] << " " << colorCount[y][iColor] << endl;
      changeRes(x, y, iColor, -1);
    }

    if (inCycle[x][y] == 1 && cycleColor[color] == cycleN - 1) {
    } else {
      changeRes(x, y, color, 1);
//      cout << "after " << colorCount[x][color] << " " << colorCount[y][color] << endl;
    }
    updata(x, y, iColor, color);
    printf("%d\n", res);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t ++) {
    printf("Case #%d:\n", t);
    work();
  }
  return 0;
}
