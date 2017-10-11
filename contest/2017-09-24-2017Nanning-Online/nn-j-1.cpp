#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 13;

int N;
string s1,s2;
int a[maxN], b[maxN];

bool check() {
  rep(i , 1, N+1) if(a[i] != b[i]) return false;
  return true;
}

inline int findinB(int tt) {
  rep(i, 1, N+1) if(b[i] == tt) return i;
}

int ans = 10000;
void dfs(int step) {
  if(step >= ans) return ;
  if(check()) {
    ans = step;
    return ;
  }
  if(a[1] == b[1]) {
    for(int i = 2; i <= N; i++) if(a[i] != b[i]){
      int tt = findinB(a[i]);
      swap(a[1] , a[tt]);
      dfs(step + 1);
      swap(a[1] , a[tt]);
    }
    return ;
  } else {
    int tt = findinB(a[1]);
    swap(a[1] , a[tt]);
    dfs(step + 1);
    swap(a[1] , a[tt]);
    return ;
  }
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("nn-j.in","r",stdin);
#endif
  cin >> N;
  rep(cas , 1 , 5+1) {
    cin >>s1 >> s2;
    rep(i, 1 , N+1) a[i] = s1[i-1]-'0';
    rep(i, 1 , N+1) b[i] = s2[i-1]-'0';
    ans = 10000;
    dfs(0);
    printf("%d\n",ans);
  }

  return 0;
}

