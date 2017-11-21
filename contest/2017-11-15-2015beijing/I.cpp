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

const int maxN = 600 + 13;


vector<pair<int,int>> ans[maxN];
int s[maxN][maxN];

int work() {
  int N; 
  if(scanf("%d", &N) != 1) return 0;
  int tn = N;
  for(int i = 1; i <= N; i++) 
    ans[i].clear();
  int H = (N+1) / 2;
  int y = N * (N+1) / 2 / H;
  int W = y;
  printf("%d %d\n", H, W);
  int x = H;
  if((N&1) == 0) {
    for(int i = H; i >= 1; i--) 
      ans[N].pb(mk(i,y));
    y--;
    for(int i = 1; i <= H; i++) 
      ans[N].pb(mk(i,y));
    y--;
    tn --;
  }
  for(int k = tn ; k >= 1; k--) {
    if(k == 1) {
      ans[k].pb(mk(H,y));
      break;
    }
    ans[k].pb(mk(H-1,y-1));
    for(int i = y-1; i >= 1; i--) 
      ans[k].pb(mk(H, i));
    k--;
    if(k == 0) break;
    for(int i = H; i >= 1; i--) 
      ans[k].pb(mk(i,y));
    y--;
    for(int i = 1; i <= H-2; i++) 
      ans[k].pb(mk(i,y));
    y--;
    H--;
  }
  if(tn >= 5) {
    for(int i = 1; i <= 5; i++) ans[i].clear();
    ans[1].pb(mk(3,4));
    ans[2].pb(mk(1,4)); ans[2].pb(mk(1,5));
    ans[3].pb(mk(2,4)); ans[3].pb(mk(2,5)); ans[3].pb(mk(3,5)); 

    ans[4].pb(mk(2,2)); 
    ans[4].pb(mk(2,3)); 
    ans[4].pb(mk(3,3)); 
    ans[4].pb(mk(3,2)); 
    
    ans[5].pb(mk(1,3)); 
    ans[5].pb(mk(1,2)); 
    ans[5].pb(mk(1,1)); 
    ans[5].pb(mk(2,1)); 
    ans[5].pb(mk(3,1)); 
  }
  for(int i = 1; i <= N; i++) {
    printf("%d %d", ans[i][0].first, ans[i][0].second);
    s[ans[i][0].first][ans[i][0].second] = i;
    for(int j = 1; j < i; j++) {
      printf(" %d %d", ans[i][j].first, ans[i][j].second);
      s[ans[i][j].first][ans[i][j].second] = i;
    }
    printf("\n");
  }
  return 1;
  //cout << "ok" << endl;
  H = (N+1) / 2;
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) 
      cout << s[i][j] << ' ' ;
    cout<<endl;
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

