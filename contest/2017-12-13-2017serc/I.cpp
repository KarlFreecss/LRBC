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

const int maxN = 100000+13;

int xx[maxN];

void check(int a, int b, int N) {
  if(a + b > N) return ;
  xx[0] = a; xx[1] = b;
  int tt = 0;
  while(N > 0) {
    N -= xx[tt];
    tt ^= 1;
  }
  if(N == 0) 
    printf("%d %d\n", a, b);
  return ;
}

int work() {
  int N;
  if(scanf("%d", &N) != 1) return 0;
  for(int i = 2; i <= N; i++) {
    check(i, i-1,N);
    check(i, i,N);
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

