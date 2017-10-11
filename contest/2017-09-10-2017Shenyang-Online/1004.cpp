#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100000+13;

int T,N,K;
int a[maxN];
int f[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("1004.in","r",stdin);
#endif
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    scanf("%d%d", &N, &K);
    rep(i, 1, N+1) scanf("%d", &a[i]);
    int lis = 1;
    memset(f,0x7f,sizeof(f));
    f[1] = a[1];
    rep(i, 2, N+1) {
      int k = upper_bound(f+1,f+N+1,a[i]) - f;
      if(k > lis) lis = k;
      f[k] = a[i];
    }
    //cout << lis << endl;
    int lds = 1;
    memset(f,0x7f,sizeof(f));
    f[1] = a[N];
    rep(i, 2, N+1) {
      int k = upper_bound(f+1,f+N+1,a[N-i+1]) - f;
      if(k > lds)  lds = k;
      f[k] = a[N-i+1];
    }
    //cout << lds << endl;
    if(max(lis, lds) + K >= N) {
      printf("A is a magic array.\n");
    } else {
      printf("A is not a magic array.\n");
    }
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

