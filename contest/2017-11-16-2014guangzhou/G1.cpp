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

const long long len = 1e8;

char s[100];
long long a, b, mi, n;

bool less1(long long P, long long Q, long long a, long long b) {
  long long A1 = 0, A2 = 0;
  A2 = P * P % len;
  A1 = P * P / len;
  A2 *= b;
  A1 *= b;
  A1 += (A2 / len);
  A2 %= len;

  long long B1 = 0, B2 = 0;
  B2 = Q * Q % len;
  B1 = Q * Q / len;
  B2 *= a;
  B1 *= a;
  B1 += (B2 / len);
  B2 %= len;

  if (A1 == B1)
    return A2 < B2;
  else
    return A1 < B1;

}
void work() {
  a = b = 0;
  mi = 1;
  n = strlen(s);
  for (int i = 2; i < n; i ++) {
    a *= 10;
    a += s[i] - '0';
    mi *= 10;
  }
  a *= 10;
  mi *= 10;
  a -= 5;
  b = a + 10;
//  cout << a << " " << b << " " << mi << endl;
  long long P = 1;
  for (long long Q = 2; true ; Q ++) {
    while (less1(P, Q, a, mi)) {
      P ++;
    }
    if (less1(P, Q, b, mi)) {
      printf("%lld%c%lld\n", P,'/', Q);
      return;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  int tt = 0;
  while (scanf("%s", s) != EOF) {
    tt ++;
    printf("Case #%d: ", tt);
    work();
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

