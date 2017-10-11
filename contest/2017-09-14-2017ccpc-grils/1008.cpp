#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const ll MO = 1e9+7;

class MAT{
  public:
    vector<vector<ll>> data;
    MAT(int n, int m){
      data.resize(n);
      for (int i = 0; i < data.size(); ++i) {
        data[i].resize(m);
        for (int j = 0; j < data[i].size(); ++j) {
          data[i][j] = 0;
        }
      }
    }

    MAT& operator =(const MAT & A){
      data.resize(A.data.size());
      for (int i = 0; i < data.size(); ++i) {
        data[i].resize(A.data[i].size());
        for (int j = 0; j < data[i].size(); ++j) {
          data[i][j] = A.data[i][j];
        }
      }
      return *this;
    }

    MAT(const MAT & A){
      data.resize(A.data.size());
      for (int i = 0; i < data.size(); ++i) {
        data[i].resize(A.data[i].size());
        for (int j = 0; j < data[i].size(); ++j) {
          data[i][j] = A.data[i][j];
        }
      }
    }


};

MAT ONE(3, 3);

MAT operator *(const MAT & A, const MAT & B) {
  MAT tmp(A.data.size(), A.data[0].size());
  for (int i = 0; i < A.data.size(); ++i) {
    for (int j = 0; j < A.data.size(); ++j) {
      for (int k = 0; k < A.data.size(); ++k) {
        tmp.data[i][j] = (tmp.data[i][j] + A.data[i][k] * B.data[k][j]) % MO;
      }
    }
  }
  return tmp;
}

MAT exp(const MAT & BASE, const ll index){
  if (index == 0) return ONE;
  if (index == 1) return BASE;

  MAT tmp(exp(BASE, index / 2));
  tmp = tmp * tmp;
  if (index % 2)
    tmp = tmp * BASE;
  return tmp;
}

void showMat(const MAT & fuck){
  for (int i = 0; i < fuck.data.size(); ++i) {
    for (int j = 0; j < fuck.data[i].size(); ++j) {
      cout << fuck.data[i][j] << ' ';
    } cout << endl;
  }
}

void party_always_exist(const MAT & BASE){
  ll n;
  cin >> n;
  
  for (int fuck_ = 1; fuck_ <= 1; ++fuck_) {
  MAT tmp = exp(BASE, n + fuck_);
  cout << (tmp.data[0][0] +  tmp.data[1][0] + 2*tmp.data[2][0])%MO << endl;
  }
}

int main() {
  for (int i = 0; i < 3; ++i) {
    ONE.data[i][i] = 1;
  }
  MAT base(3, 3);
  base.data[0][2] = 1;
  base.data[1][0] = 1;
  base.data[2][1] = 1;
  base.data[2][2] = 1;


  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    party_always_exist(base);
  }

  return 0;
}

