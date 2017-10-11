#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

vector<long long> vNum;
vector<char> vOper;
long long mi2[61];
long long N, K;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("B.in","r",stdin);
#endif
  mi2[0] = 1;
  rep(i, 1, 61)
    mi2[i] = mi2[i - 1] * 2;

  long long T, t = 0;
  scanf("%lld", &T);
  rep(t, 1, T + 1) {
    printf("Case #%lld:\n", t);
    scanf("%lld%lld", &N, &K);
    K --;
    vNum.clear();
    vOper.clear();
    if (N % 2 == 0) {
      N -= mi2[K] + 1;
      vNum.push_back(mi2[K] + 1);
      vOper.push_back('+');
    } else {
      N -= mi2[K];
      vNum.push_back(mi2[K]);
      vOper.push_back('+');
    }
    per(k, 0, K) {
      if (N > 0) {
        N -= mi2[k];
        vNum.push_back(mi2[k]);
        vOper.push_back('+');
      } else {
        N += mi2[k];
        vNum.push_back(mi2[k]);
        vOper.push_back('-');
      }
    }
    per(i, 0, vNum.size()) {
      printf("%lld %c\n", vNum[i], vOper[i]);
    }
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

