#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=13;

int no[maxN][maxN];
int ans,sum=0;;
int li[40][3];
int num[maxN];

void dfs(int n, int ta) {
  if(ans == 36) return ;
  if(n == 21) {
    if(ta > ans) ans = ta;
    return ;
  }
  if((21-n)*2+ta <= ans) return ;
  if(sum/3+ta <= ans) return ;
  dfs(n+1,ta);
  num[li[n][0]]--;num[li[n][1]]--;num[li[n][2]]--;
  if(num[li[n][0]]>=0 && num[li[n][1]]>=0 && num[li[n][2]]>=0) {
    sum -= 3;
    dfs(n+1,ta+1);
    num[li[n][0]]--;num[li[n][1]]--;num[li[n][2]]--;
    if(li[n][0]!=li[n][1] && num[li[n][0]]>=0 && num[li[n][1]]>=0 && num[li[n][2]]>=0) {
      sum -= 3;
      dfs(n+1,ta+2);
      sum += 3;
    }
    num[li[n][0]]++;num[li[n][1]]++;num[li[n][2]]++;
    sum += 3;
  }
  num[li[n][0]]++;num[li[n][1]]++;num[li[n][2]]++;
  return ;
}

int cnt[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("hdu5937.in","r",stdin);
#endif
  for(int i = 1; i <= 9; i++) {
    cnt[i] = 0;
  }
  int ind = 1;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      if( i+j > 9) break;
      if(i <= j) {
        no[i][j] = ind;
        li[ind][0] = i;
        li[ind][1] = j;
        li[ind][2] = i+j;
        ind++;
      }
      cnt[i]++;cnt[j]++;cnt[i+j]++;
    }
  }
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    sum = 0;
    for(int i = 1; i <= 9; i++) {
      scanf("%d", &num[i]);
      if(num[i] > cnt[i]) num[i] = cnt[i];
      sum += num[i];
    }
    ans = 0;
    dfs(1,0);
    printf("Case #%d: %d\n", cas, ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

