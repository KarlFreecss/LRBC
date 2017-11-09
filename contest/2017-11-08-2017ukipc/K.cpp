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

const int maxN = 110;

struct building {
  int p,r;
  int id;
  friend bool operator < (const building& a, const building& b) {
    return a.r > b.r;
  }
};

priority_queue<pii> q;
int N, M;
building b[maxN];
building s[maxN];

bool work() {
  if (scanf("%d", &N) != 1) return false;
  for(int i = 1; i <= N; i++) 
    scanf("%d%d", &s[i].p, &s[i].r);
  for(int i = 1; i <= N; i++) 
    s[i].id = i;
  scanf("%d", &M);
  for(int i = 1; i <= M; i++) 
    scanf("%d", &b[i].r);
  for(int i = 1; i <= M; i++) 
    b[i].id = i;
  sort(s+1, s+1+N);
  vector<vector<int>> ans;
  ans.resize(M+1);
  while(!q.empty()) q.pop();
  for (int i = 1; i <= M; i ++) {
    q.push(make_pair(b[i].r, b[i].id));
  }
  for (int i = 1; i <= N; i ++) {
    if (s[i].p >= s[i].r)
      continue;
    pii tt = q.top(); q.pop();
    if (tt.first > s[i].r) {
      printf("impossible\n");
      return true;
    } else if (tt.first <= s[i].p)
      continue;
    b[tt.second].r = s[i].p;
    ans[tt.second].push_back(s[i].id);

    q.push(make_pair(s[i].p, tt.second));
  }
  for (int i = 1; i <= M; i ++) {
    if (b[i].r > 0) {
      printf("impossible\n");
      return true;
    }
  }
  for (int i = 1; i <= M; i ++) {
    for (int j = ans[i].size() - 1; j > 0; j --)
      printf("%d ", ans[i][j]);
    printf("%d\n", ans[i][0]);
  }
  return true;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  (work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


