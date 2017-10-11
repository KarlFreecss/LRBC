#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 3000000+13;

int nextInt() {
  int ret;char c;
  while(c=getchar(),c<'0'||c>'9');
  ret=c-'0';
  while(c=getchar(),c>='0'&&c<='9')ret=ret*10+c-'0';
  return ret;
}

int N;
int b[maxN],a[maxN];
int s[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("1012.in","r",stdin);
#endif
  while(scanf("%d", &N)!=EOF) {
    rep(i, 1, N+1) a[i] = a[i+N] = nextInt();
    rep(i, 1, N+1) b[i] = b[i+N] = nextInt();
    int ans = 0;
    int tsum = 0, ta = 0;;
    int st = 1,anst = -1;
    for(int i = 1; i <= 2*N; i++) {
      if(i - st == N) {
        ans = ta;
        anst = st;
        break;
      }
      tsum += a[i] - b[i];
      ta += a[i];
      if(tsum < 0) {
        if(ans < ta) {
          ans = ta;
          anst = st;
        }
        tsum = 0;
        ta = 0;
        st = i+1;
      }
    }
    printf("%d\n", anst-1);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

