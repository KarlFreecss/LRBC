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

const int maxN = 100+13;

int s[maxN][maxN];
int H, W, N;

void show() {
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) 
      printf("%c",s[i][j]==1?'#':'.');
    printf("\n");
  }
  return ;
}
int work() {
  if(scanf("%d%d%d", &H, &W, &N) != 3) return 0;
  memset(s, 0, sizeof(s));
  int h, w; h = (H+1) / 2; w = (W+1) / 2;
  for(int x = 1; x <= h; x++) {
    for(int y = 1; y <= w; y++) {
      if(x*y == N) {
        int tx = 2;
        for(int i = 1; i < x; i++) {
          for(int j = 1; j <= W; j++) {
            s[tx][j] = 1;
          }
          tx += 2;
        }
        tx = 2;
        for(int i = 1; i < y; i++) {
          for(int j = 1; j <= H; j++) {
            s[j][tx] = 1;
          }
          tx += 2;
        }
        show();
        return 1;
      }
    }
  }
  printf("Impossible\n");
  return 1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
#ifdef ONLINE_JUDGE
  freopen("kotlin.in","r",stdin);
  freopen("kotlin.out","w",stdout);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

