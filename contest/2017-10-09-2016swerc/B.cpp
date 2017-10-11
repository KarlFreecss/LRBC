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

const double esp = 1e-7;

class type1 {
  public:
    double val;
    int flag;
    type1(double iVal = 0, int iFlag = 0) {
      val = iVal;
      flag = iFlag;
    }
};
bool cmp(type1 a, type1 b) {
  return a.val < b.val;
}

vector<type1> v;
int N, iX, iY, resMax, resMin;
int count1, sameN, minN, minX, maxX, minY, maxY;

void update() {
  if (minN + count1 < resMin)
    resMin = minN + count1;
  if (minN + count1 + sameN > resMax)
    resMax = minN + count1 + sameN;
  return;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  minX = maxX = minY = maxY = 0;
  int x, y;
  scanf("%d", &N);
  scanf("%d%d", &iX, &iY);
  count1 = sameN = minN = 0;
  for (int i = 1; i < N; i ++) {
    scanf("%d%d", &x, &y);
    if (x < iX)
      minX ++;
    if (x <= iX)
      maxX ++;
    if (y < iY)
      minY ++;
    if (y <= iY)
      maxY ++;
    if (x == iX && y == iY) {
      sameN ++;
    } else if (x <= iX && y <= iY) {
      minN ++;
    } else if (x >= iX && y >= iY) {
    } else if (x >= iX && y <= iY) {
      double tmp = 1.0 * (x - iX) / (iY - y);
      v.push_back(type1(tmp, -1));
      count1 ++;
    } else if (x <= iX && y >= iY) {
      double tmp = 1.0 * (iX - x) / (y - iY);
      v.push_back(type1(tmp, 1));
    }
  }
  resMax = max(maxX, maxY);
  resMin = min(minX, minY);
//  cout << resMin << " " << resMax << endl;
  sort(v.begin(), v.end(), cmp);
  update();
  int pos = 0, neg = 0;
  for (int i = 0; i < v.size(); i ++) {
    if (v[i].flag == 1)
      pos ++;
    else
      neg ++;
    if (i < v.size() && fabs(v[i].val - v[i + 1].val) < esp) {
      continue;
    }
    int tmp = count1;
    count1 = tmp + pos;
    update();
    count1 = tmp - neg;
    update();
    count1 = tmp + pos - neg;
    update();
    pos = neg = 0;
  }
  printf("%d %d\n", N - resMax, N - resMin);
  return 0;
}

