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

const int maxN = 5000+13;

struct building {
  int p,r;
  int id;
  friend bool operator < (const building& a, const building& b) {
    return a.p < b.p;
  }
};

priority_queue<pii> q;
int M;
building b[maxN];
building s[maxN];

bool work() {
  int N, M;
  if (scanf("%d%d", &N, &M) != 2) return false;
  for(int i = 1; i <= N; i++) 
    scanf("%d", &s[i].p);
  for(int i = 1; i <= N; i++) 
    s[i].id = i;
  for(int i = 1; i <= M; i++) 
    scanf("%d", &b[i].p);
  for(int i = 1; i <= M; i++) 
    scanf("%d", &b[i].r);
  for(int i = 1; i <= M; i++) 
    b[i].id = i;
  b[M+1].p = 0;
  b[M+1].r = 1000000;
  M++;
  sort(b+1, b+1+M); 
  sort(s+1, s+1+N);
  int id = N;
  vector<int> ans;
  ans.resize(N+1);
  while(!q.empty()) q.pop();
  for(int i = M; i >= 1 && id > 0; i--) {
    if(b[i].p >= s[id].p) 
      q.push(make_pair(-b[i].r, b[i].id));
    else {
      if(q.size() == 0) {
        ans.clear();
        break;
      } else {
        pii tt = q.top(); q.pop();
        ans[s[id].id] = tt.second;
        id --;
      }
      //q.push(make_pair(-b[i].r, b[i].id));
      i++;
    }
  }
  if(ans.size() == 0 || id != 0) {
    printf("impossible\n");
  } else {
    printf("%d", ans[1]);
    for(int i = 2; i <= N; i++) {
      printf(" %d", ans[i]);
    }
    printf("\n");
  }
  return true;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  while (work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

