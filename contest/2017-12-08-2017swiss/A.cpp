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

const int MAXN = 2e5 + 100;

long long a[MAXN];
long long N;

bool checkOK(long long MM) {
  map<long long, long long> countA;
  for (int i = 1; i <= N; i ++) {
    countA[a[i]] ++;
  }
  long long val = 1;
  for (int i = 1; i <= N; i ++) {
    countA[val] --;
    if (countA[val] < 0)
      return false;
    val *= 2;
    val %= MM;
  }
  return true;
}
bool work() {
  map<long long, long long> countNum;
  set<long long> s;
  long long maxA = 0;
  if (scanf("%I64d", &N) != 1) return false;
  for (int i = 1; i <= N; i ++) {
    scanf("%I64d", &a[i]);
    maxA = max(maxA, a[i]);
    s.insert(a[i]);
    countNum[a[i]] ++;
  }
  vector<long long> vX;
  vector<long long> vY;
  while (!s.empty()) {
    long long x = *s.begin();
    vX.push_back(x);
    countNum[x] --;
    if (countNum[x] == 0)
      s.erase(x);
    long long y = 2 * x;
    while (countNum[y] != 0) {
      countNum[y] --;
      if (countNum[y] == 0)
        s.erase(y);
      y = y * 2;
    }
    y /= 2;
//    cout << x << " " << y << endl;
    vY.push_back(y);
  }
  if (vX.size() == 1) {
    printf("%I64d\n", maxA + 1);
    return true;
  } else {
    sort(vX.begin(), vX.end());
    sort(vY.begin(), vY.end());
    long long x = vX[vX.size() - 1];
    if (x == 1)
      x = vX[vX.size() - 2];
    long long y = vY[vY.size() - 2];
//    cout << x << " " << y << endl;
    long long res = y * 2 - x;
    if (res > 0 && checkOK(res)) {
      printf("%I64d\n", res);
      return true;
    }
    y = vY[vY.size() - 1];
//    cout << x << " " << y << endl;
    res = y * 2 - x;
//    cout << res << endl;
    if (res > 0 && checkOK(res)) {
      printf("%I64d\n", res);
      return true;
    }
  }
  cout << "11111" << endl;
  while (true);
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

