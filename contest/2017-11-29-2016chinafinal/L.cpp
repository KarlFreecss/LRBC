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

map<pair<pair<int, int>, pair<int, int>>, int> dic;

void dfs(int l, int r, int score[]){
  if (r > 4) {
    ++l;
    r = l + 1;
  }
  if (l == 4) {
        dic[make_pair(make_pair(score[1], score[2]), 
                       make_pair(score[3], score[4])
                      )
            ]++;
    return;
  }
  static int scoreL[] = {3, 0, 1};
  static int scoreR[] = {0, 3, 1};
  for (int k = 0; k < 3; ++k) {
    score[l] += scoreL[k];
    score[r] += scoreR[k];
    dfs(l, r+1, score);
    score[l] -= scoreL[k];
    score[r] -= scoreR[k];
  }
}

void init(){
  int a[5] = {0};
  dfs(1, 2, a);
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("L.in","r",stdin);
#endif
  init();
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    int score[5];
    for (int k = 1; k <= 4; ++k) {
      scanf("%d", &score[k]);
    }
    pair<pair<int, int>, pair<int, int>> status = make_pair(
        make_pair(score[1], score[2]),
        make_pair(score[3], score[4]));
    int nums = dic[status];
    printf("Case #%d: ", i); 
    if (nums == 0) {
      puts("Wrong Scoreboard");
    } else if (nums == 1) {
      puts("Yes");
    } else {
      puts("No");
    } 
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

