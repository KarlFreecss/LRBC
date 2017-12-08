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

const int MAXN = 1e5 + 100;
const long long MAXVAL = 2e18;

long long a[MAXN], b[MAXN];
long long T, N, M;


long long myAdd(long long x, long long y) {
  if (x > MAXVAL - y)
    return MAXVAL;
  else
    return x + y;
}
long long getMin(long long val, long long num) {
  if (num >= val) {
    return (val * (val + 1) / 2);
  } else {
    return ((2 * val - num + 1) * num / 2);
  }
}
long long getMax(long long val, long long num) {
  return ((2 * val + num - 1) * num / 2);
}
long long getMax(long long valX, long long valY, long long num) {
  long long res = -valX;
  if (valX > valY)
    swap(valX, valY);
  long long tmpNum = (num - (valY - valX)) / 2;
  res = myAdd(res, getMax(valY, tmpNum));
  tmpNum = num - tmpNum;
  res = myAdd(res, getMax(valX, tmpNum));
  return res;
}
long long getMin(long long valX, long long valY, long long num) {
  long long res = -valX;
  if (valX > valY)
    swap(valX, valY);
  long long tmpNum = (num - (valY - valX)) / 2;
  res = myAdd(res, getMin(valX, tmpNum));
  tmpNum = num - tmpNum;
  res = myAdd(res, getMin(valY, tmpNum));
  return res;
}

bool work() {
  if (scanf("%I64d%I64d%I64d", &T, &N, &M) != 3) return false;
  for (int i = 1; i <= M; i ++) {
    scanf("%I64d%I64d", &a[i], &b[i]);
  }
  for (int i = 2; i <= M; i ++) {
    if (abs(a[i] - a[i - 1]) < abs(b[i] - b[i] - 1)) {
//      cout << "!!!!!!" << endl;
      printf("No\n");
      return true;
    }
  }
  long long minVal = 0, maxVal = 0;
  minVal = myAdd(minVal, getMin(b[1], a[1]));
  maxVal = myAdd(maxVal, getMax(b[1], a[1]));
  for (int i = 2; i <= M; i ++) {
    minVal = myAdd(minVal, getMin(b[i - 1], b[i], (a[i] - a[i - 1] + 1)));
    maxVal = myAdd(maxVal, getMax(b[i - 1], b[i], (a[i] - a[i - 1] + 1)));
  }
  minVal = myAdd(minVal, getMin(b[M], (N - a[M] + 1)) - b[M]);
  maxVal = myAdd(maxVal, getMax(b[M], (N - a[M] + 1)) - b[M]);
//  cout << minVal << " " << maxVal << endl;
  if (minVal <= T && T <= maxVal) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("H.in","r",stdin);
#endif
  while (work());

  return 0;
}

