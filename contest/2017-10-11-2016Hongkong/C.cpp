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

int a[MAXN], b[MAXN], tmpA[MAXN], tmpB[MAXN];
int n;

bool less1(int iA, int iB, int A, int B) {
  double iVal = 1.0 * iA * log(2) + 1.0 * iB * log(3);
  double val = 1.0 * A * log(2) + 1.0 * B * log(3);
  return iVal < val;
}

void getRes(int gcdN, int lcmN) {
  if (gcdN == 0) {
    printf("%d %d %d %d\n", tmpA[n - 1], tmpB[n - 1], tmpA[n - 1], tmpB[n - 1]);
    return;
  } else if (lcmN == 0) {
    printf("%d %d %d %d\n", tmpA[0], tmpB[0], tmpA[0], tmpB[0]);
    return;
  }
  if (lcmN == 1) {
    int resA = 0, resB = 0, aa, bb;
    rep(i, 0, n) {
      if (a[i] == tmpA[0])
        aa = tmpA[1];
      else
        aa = a[i];
      if (b[i] == tmpB[0])
        bb = tmpB[1];
      else
        bb = b[i];
      if (less1(resA, resB, aa, bb)) {
        resA = aa;
        resB = bb;
      }
    }
    printf("%d %d ", resA, resB);
  } else {
    printf("%d %d ", tmpA[n - 1], tmpB[n - 1]);
  }

  if (gcdN == 1) {
    int resA = 1e4, resB = 1e4, aa, bb;
    rep(i, 0, n) {
      if (a[i] == tmpA[n - 1])
        aa = tmpA[n - 2];
      else
        aa = a[i];
      if (b[i] == tmpB[n - 1])
        bb = tmpB[n - 2];
      else
        bb = b[i];
      if (!less1(resA, resB, aa, bb)) {
        resA = aa;
        resB = bb;
      }
    }
    printf("%d %d\n", resA, resB);
  } else {
    printf("%d %d\n", tmpA[0], tmpB[0]);
  }
  return;
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("C.in","r",stdin);
#endif

  scanf("%d", &n);
  rep(i, 0, n) {
    scanf("%d%d", &a[i], &b[i]);
    tmpA[i] = a[i];
    tmpB[i] = b[i];
  }
  sort(tmpA, tmpA + n);
  sort(tmpB, tmpB + n);
  rep(i, 0, n) {
    getRes(i, n - 1 - i);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

