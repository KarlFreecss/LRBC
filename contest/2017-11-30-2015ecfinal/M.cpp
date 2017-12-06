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

const int maxN = 1000+13;

int T, R, S, B;
int s[maxN][maxN];

void work(int cas) {
  scanf("%d%d", &R, &S);
  scanf("%d", &B);
  memset(s,0,sizeof(s));
  for(int i = 1; i <= B; i++) {
    int tr, ts;
    scanf("%d%d", &tr, &ts);
    s[tr][ts] = -1;
  }
  int ans1 = 0, ans2 = 0;
  int tt = 0;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < S; j++) {
      if(s[i][j] == -1) {
        ans1 += (tt+1) / 2;
        ans2 += (tt+2) / 3;
        tt =0;
        continue;
      }
      tt++;
    }
    ans1 += (tt+1) / 2;
    ans2 += (tt+2) / 3;
    tt =0;
  }
  printf("Case #%d: %d %d\n", cas, ans1, ans2);
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("M.in","r",stdin);
#endif
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    work(cas);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

