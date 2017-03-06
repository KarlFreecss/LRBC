#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=31;

map <string, int>hs;

int T,G;
char us[10],ts[10];
int team[maxN][maxN];
int num[maxN*maxN];

bool check(int n) {
  memset(num,0,sizeof(num));
  int sx = G - n;
  int sy = n;
  int tx = 0,ty = 0;
  for(int j = 1; j <= 20 && tx < sx; j++){
    for(int i = 1; i <= 5 && tx < sx; i++) {
      if(num[team[i][j]] == 0) {
        tx++;
        num[team[i][j]] = 1;
      }
    }
  }
  for(int i = 1; i <= 20 && ty < sy; i++) {
    if(num[team[6][i]] == 0) {
      ty++;
      num[team[6][i]]=1;
    }
  }
  return num[hs[us]];
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen("J.in","r",stdin);
 // freopen("J.out","w",stdout);
#endif
  scanf("%d", &T);
  for(int cas = 1;cas <= T; cas++) {
    hs.clear();
    printf("Case #%d: ",cas);
    scanf("%d%s",&G,us);
  //  cout<<us<<endl;
    int ind = 0;
    for(int i=1; i <= 6; i++) {
      for(int j = 1; j <= 20; j++) {
        scanf("%s", ts);
        if(hs[ts] == 0) {
          hs[ts] = ++ind;
        }
        team[i][j]=hs[ts];
  //      cout<<ts<<'\t';
      }
  //    cout << endl;
    }
    int ans = -1;
    for(int Y = 0; Y <= G; Y++) {
      if(check(Y)) continue;
      ans = Y;
      break;
    }
    if(ans == -1) 
      printf("ADVANCED!\n");
    else 
      printf("%d\n",ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

