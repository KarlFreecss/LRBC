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

const long long MAXN = 10;
const long long MAXM = 1e18 + 100;
const long long matN = 500;
const long long MM = 1e9;

long long mi[8];
long long mat[matN][matN], mat1[matN][matN], mat2[matN][matN], f[MAXN][matN][matN], tmpMat[matN][matN], res[matN][matN]; 
long long N, M, K;

bool isEmpty(long long state, long long pos) {
  return !(state & mi[pos]);
}
long long toFill(long long state, long long pos) {
  return (state | mi[pos]);
}
long long matMul(long long a[matN][matN], long long b[matN][matN], long long c[matN][matN]) {
  memset(tmpMat, 0, sizeof(tmpMat));
  for (int i = 0; i < K; i ++) {
    for (int j = 0; j < K; j ++) {
      for (int k = 0; k < K; k ++) {
        long long tmp = b[i][k] * c[k][j];
        tmp %= MM;
        tmpMat[i][j] += tmp;
        tmpMat[i][j] %= MM;
      }
    }
  }
  for (int i = 0; i < K; i ++) {
    for (int j = 0; j < K; j ++) {
      a[i][j] = tmpMat[i][j];
    }
  }
}

void makeMat1(long long N, long long K) {
  memset(mat1, 0, sizeof(mat1));
  memset(f, 0, sizeof(f));
  for (int start = N - 1; start >= 0; start --) {
    for (int i = K - 1; i >= 0; i --) {
      for (int j = start; j < N; j ++) {
        if (isEmpty(i, j)) {
          long long tmp = toFill(i, j);
          f[start][i][tmp] ++;
          f[start][i][tmp] %= MM;
          if (j + 1 < N) {
            for (int k = 0; k < K; k ++) {
              f[start][i][k] += f[j + 1][tmp][k];
              f[start][i][k] %= MM;
            }
          } 
          if (j < N - 1 && isEmpty(tmp, j + 1)) {
            tmp = toFill(tmp, j + 1);
            f[start][i][tmp] ++;
            f[start][i][tmp] %= MM;
            if (j + 2 < N) {
              for (int k = 0; k < K; k ++) {
                f[start][i][k] += f[j + 2][tmp][k];
                f[start][i][k] %= MM;
              }
            }
          }
        }
      }
    }
  }
//  cout << "mat1:" << endl;
  for (int i = 0; i < K; i ++) {
    for (int j = 0; j < K; j ++) {
      mat1[i][j] = f[0][i][j];
//      cout << mat1[i][j] << " ";
    }
    mat1[i][i] = 1;
//    cout << endl;
  }
}
void makeMat2(long long N, long long K) {
  memset(mat2, 0, sizeof(mat2));
  for (int i = 0; i < K; i ++) {
    long long j = (i ^ (K - 1));
//    cout << i << " " << j << endl;
    mat2[i][j] = 1;
  }
}
bool work() {
  if (scanf("%I64d%I64d", &N, &M) != 2) {
    return false;
  }
  K = mi[N];
  makeMat1(N, K);
  makeMat2(N, K);
  matMul(mat, mat1, mat2);
  M --;
  memset(res, 0, sizeof(res));
  for (int i = 0; i < K; i ++)
    res[i][i] = 1;
  while (M > 0) {
    if (M % 2 == 1) {
      matMul(res, res, mat);
    }
    matMul(mat, mat, mat);
    M /= 2;
  }
  matMul(res, res, mat1);
  printf("%I64d\n", res[0][K - 1]);
  return true;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  mi[0] = 1;
  for (int i = 1; i < MAXN; i ++)
    mi[i] = mi[i - 1] * 2;
  while (work());
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

