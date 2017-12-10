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

const int maxN = 30 + 13;

char s[maxN][maxN];
int N, M;
long long f[maxN][maxN];

bool color(int x, int y, char c) {
  if(x == 0 || y == 0) return true;
  if(x == N+1 || y == M+1) return true;
  if(s[x][y] == c) return true;
  if(s[x][y] == '.') {
    s[x][y] = c;
    return true;
  } else {
    return false;
  }
}

int work() {
  if(scanf("%d%d", &N, &M) != 2) return 0;
  for(int i = 1; i <= N; i++) {
    scanf("%s", &s[i][1]);
  }
  bool ok = true;
  for(int i = N; i >= 1; i--) {
    for(int j = M; j >= 1; j--) {
      if(s[i][j] == 'B') {
        if(!color(i-1,j,'B')) ok = false;
        if(!color(i,j-1,'B')) ok = false;
        if(!color(i-1,j-1,'B')) ok = false;
      }
    }
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(s[i][j] == 'R') {
        if(!color(i+1,j,'R')) ok = false;
        if(!color(i,j+1,'R')) ok = false;
        if(!color(i+1,j+1,'R')) ok = false;
      }
    }
  }
  if(!ok) {
    printf("0\n");
    return 1;
  }

  memset(f,0,sizeof(f));
  f[0][M] = 1ll;
  for(int i = 1; i <= N; i++) {
    for(int j = M; j > 0; j--) {
      if(s[i][j] == '.') {
        for(int k = j; k <= M; k++) {
          f[i][j] += f[i-1][k];
        }
      }
      if(s[i][j] == 'B') {
        for(int k = j; k <= M; k++) 
          f[i][j] += f[i-1][k];
        break;
      }
    }
    bool isb = false;
    for(int j = 1; j <= M; j++) {
      if(s[i][j] == 'B') isb = true;
    }
    if(!isb) {
      for(int j = 0; j <= M; j++) {
        f[i][0] += f[i-1][j];
      }
    }
  }
  /*
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= M; j++) {
      cout << f[i][j] << ' ';
    }
    cout << endl;
  }
  */
  long long ans = 0;
  for(int i = 0; i <= M; i++) 
    ans += f[N][i];
  printf("%lld\n", ans);
  return 1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

