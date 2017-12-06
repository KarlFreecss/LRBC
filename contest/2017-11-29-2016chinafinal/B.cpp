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

long long res[MAXN], getPair[MAXN];
long long N, K, oddN, evenN, pairOddN, pairEvenN;

bool bigger(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll val) {
  if (x3 >= 0 && y3 >= 0) {
    long long mi = x3 + y3;
    long long tmp = 1;
    while (mi > 0) {
      mi --;
      tmp *= 2;
      if (tmp >= val)
        return true;
    }
    if (tmp >= val)
      return true;
    val += tmp;
  }
//  cout << val << " 1" << endl;
  if (x1 >= 0 && y1 >= 0) {
    long long mi = x1 + y1;
    long long tmp = 1;
    while (mi > 0) {
      mi --;
      tmp *= 2;
      if (tmp >= val)
        return true;
    }
    if (tmp >= val)
      return true;
    val -= tmp;
  }
//  cout << val << " 2" << endl;

  if (x2 >= 0 && y2 >= 0) {
    long long mi = x2 + y2;
    long long tmp = 1;
    while (mi > 0) {
      mi --;
      tmp *= 2;
      if (tmp >= val)
        return true;
    }
    if (tmp >= val)
      return true;
    val -= tmp;
  }
//  cout << val << " 3" << endl;

  return false;
}
long long myPow(long long val, long long x, long long y) {
  if (x < 0 || y < 0)
    return 0;
  long long mi = x + y;
  long long res = 1;
  for (int i = 1; i <= mi; i ++)
    res *= val;
  return res;
}
long long cal(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
//  cout << x1 + y1 << " " << x2 + y2 << " " << x3 + y3 << endl;
  long long res = myPow(2, x1, y1) + myPow(2, x2, y2) - myPow(2, x3, y3);
//  cout << res << endl;
  return res;
}
void work() {
  scanf("%I64d%I64d", &N, &K);
  oddN = (N + 1) / 2;
  evenN = N - oddN;
  pairOddN = (oddN + 1) / 2;
  pairEvenN = (evenN + 1) / 2;
  if (N % 2 == 1) {
    int x = 1, y = N;
    while (x <= y) {
      getPair[x] = y;
      getPair[y] = x;
      x ++;
      y --;
    }
  } else {
    int x = 1, y = N - 1;
    while (x <= y) {
      getPair[x] = y;
      getPair[y] = x;
      x += 2;
      y -= 2;
    }
    x = 2; y = N;
    while (x <= y) {
      getPair[x] = y;
      getPair[y] = x;
      x += 2;
      y -= 2;
    }
  }  
//    cout << "return = " <<  cal(pairOddN, evenN, oddN, pairEvenN, pairOddN, pairEvenN) << endl;
  if (!bigger(pairOddN, evenN, oddN, pairEvenN, pairOddN, pairEvenN, K)) {
    printf("NOT FOUND!\n");
    return;
  }
  for (int i = 1; i <= N; i ++) {
    int flag = 0;
    if (i % 2 == 1) {
      oddN --;
      if (pairOddN <= 0) {
        if (res[getPair[i]] != 0)
          pairOddN --;
        flag = 1;
      } else {
        pairOddN --;
      }
    } else {
      evenN --;
      if (pairEvenN <= 0) {
        if (res[getPair[i]] != 0) {
          pairEvenN --;
        }
        flag = 1;
      } else {
        pairEvenN --;
      }
    }
//    cout << pairOddN << " " << pairEvenN << " " << oddN << " " << evenN << " " << K << endl;
//    cout << "return = " <<  cal(pairOddN, evenN, oddN, pairEvenN, pairOddN, pairEvenN) << endl;
    if (bigger(pairOddN, evenN, oddN, pairEvenN, pairOddN, pairEvenN, K)) {
      res[i] = 0;
//      cout << "true" << endl;
    } else {
//      cout << "false" << endl;
      K -= cal(pairOddN, evenN, oddN, pairEvenN, pairOddN, pairEvenN);
      res[i] = 1;
      if (flag == 1) {
        if (i % 2 == 1) {
          if (res[getPair[i]] != 0)
            pairOddN ++;
          else 
            pairOddN --;
        } else {
          if (res[getPair[i]] != 0)
            pairEvenN ++;
          else
            pairEvenN --;
        }
      }
    }
  }
//  cout << K << endl;
  for (int i = 1; i <= N; i ++)
    printf("%I64d", res[i]);
  printf("\n");
  return;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t ++) {
    printf("Case #%d: ", t);
    work();
  }

  return 0;
}

