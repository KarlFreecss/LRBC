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

const long long step = 100;
const long long MM = 1e9 + 7;
const long long MAXN = 5e4 + 13;
const long long MAXK = 100 + 13;
const long long MAXN_10 = MAXN * 10;

char s[MAXN];
long long a[MAXN], sum[MAXN];
long long S[MAXK];
long long C[MAXK][MAXK];
long long miK[MAXN_10];
long long N, K;

long long mi(long long val, long long K) {
  long long res = 1;
  while (K > 0) {
    if ((K & 1)) {
      res *= val;
      res %= MM;
    }
    K >>= 1;
    val *= val;
    val %= MM;
  }
  return res;
}
long long calS(long long K, long long i_1_tt) {
  long long i_1_tt_mi_j = 1;
  long long res = 0;
  for (int j = 0; j <= K; j ++) {
    long long tmp = S[K - j] * i_1_tt_mi_j;
    tmp %= MM;
    tmp *= C[K][j];
    tmp %= MM;
    res += tmp;
    res %= MM;
    i_1_tt_mi_j *= i_1_tt;
    i_1_tt_mi_j %= MM;
  }
  res %= MM;
  return res;
}
void work() {
  //cin >> N >> K;
  scanf("%lld%lld", &N, &K);
  scanf("%s", s);
  sum[0] = 0;
  for (int i = 1; i <= N; i ++) {
    a[i] = s[i - 1] - '0';
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 0; i <= N * 10; i ++) {
    miK[i] = mi(i, K);
  }
//  cout << miK[9] << endl;
  for (int i = 0; i <= K; i ++)
    S[i] = 0;
  long long tt = 0, i = 0;
  long long res = 0;
  while (true) {
//    cout << "=============" << endl;
    for (int k = 1; k < step; k ++) {
      tt ++;
      if (tt > N)
        return;
      if (tt != 1) printf(" ");
      res = calS(K, sum[tt] - sum[i]);
      for (int l = i + 1; l <= tt; l ++) {
        res += miK[sum[tt] - sum[l - 1]];
        res %= MM;
//        cout << sum[tt] << " " << sum[l - 1] << " " << miK[sum[tt] - sum[l - 1]] << endl;
      }
      res %= MM;
      printf("%lld", res);
    }
/*    for (int i = 0; i <= K; i ++) 
      cout << S[i] << " " ;
    cout << endl;
*/    tt ++;
    if (tt > N)
      return;
    if (tt != 1) printf(" ");
    for (int kk = K; kk >= 0; kk --) {
//      cout << sum[tt] - sum[i] << endl;
      S[kk] = calS(kk, sum[tt] - sum[i]);
    }
    /*
    for (int i = 0; i <= K; i ++) 
      cout << S[i] << " " ;
    cout << endl;
    */
    for (int l = i + 1; l <= tt; l ++) {
      long long mi_j = 1;
      long long val = sum[tt] - sum[l - 1];
//      cout << "val = " << val << endl;
      for (int j = 0; j <= K; j ++) {
        S[j] += mi_j;
        S[j] %= MM;
        mi_j *= val;
        mi_j %= MM;
      }
    }
    printf("%lld", S[K]);
    i = tt;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif
  C[0][0] = 1;
  for (int i = 1; i < MAXK; i ++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j ++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      C[i][j] %= MM;
    }
  }
  int T;
  scanf("%d", &T);
  while (T --) {
//    cout << "------------" << endl;
    work();
    printf("\n");
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

