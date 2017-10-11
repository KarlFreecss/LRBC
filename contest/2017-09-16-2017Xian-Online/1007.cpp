#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 50000+13;
const int maxM = 1000+13;
const int maxK = 17;

vector<int> a[maxN];
int N,Q;
int dfn[maxN];
int f2[maxN][maxK], fn[maxN][maxM];
int sumk[maxN][maxM];

int query(int a, int b, int k) {
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("1007.in","r",stdin);
#endif
  while(scanf("%d%d", &N, &Q) != EOF) {
    rep(i , 1 , N+1) {
    }
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

