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

const int maxN = 3e5+13;

int N, M;
char s[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("L.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &M);
    scanf("%s", s);
    int ansl = 0;
    rep(i,1,M) 
      if(s[i] != 'L') ansl ++;
    int ansr = 0;
    rep(i,M-1,N-1) {
      if(s[i] != 'R') ansr ++;
    }
    printf("%d\n", min(ansl, ansr));
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

