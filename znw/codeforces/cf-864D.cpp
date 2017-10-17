#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 200000+13;

typedef pair<int,int> pii;

int N; 
int a[maxN];
int b[maxN];
int v[maxN];

queue<pii> q;

int main() {
#ifndef ONLINE_JUDGE
  //freopen("D.in","r",stdin);
#endif
  scanf("%d", &N) ;
  memset(v,0,sizeof(v));
  memset(b,0,sizeof(b));
  rep(i ,1 , N+1) {
    scanf("%d", &a[i]);
    v[a[i]]++;
  }
  int ans = 0;
  int tt = 1;
  while(v[tt] >= 1) tt++;
  rep(i ,1 , N+1) {
    if(v[a[i]] > 1) 
      q.push(make_pair(i, a[i]));
    else {
      b[a[i]] = v[a[i]];
    }
  }
  while(!q.empty()) {
    pii tp = q.front();q.pop();
    int ta = tp.second;
    if(v[ta] == 1) continue;
    if(ta < tt && b[ta] == 0) {
      b[ta] = 1;
      continue;
    }
    ans ++;
    v[ta] --;
    a[tp.first] = tt;
    v[tt] = 1;
    while(v[tt] >= 1) tt++;
  }
  printf("%d\n",ans);
  rep(i ,1 , N+1) {
    printf("%d ", a[i]);
  }
  printf("\n");

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}
