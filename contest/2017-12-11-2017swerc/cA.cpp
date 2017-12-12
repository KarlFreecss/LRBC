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

const int maxN = 2000;

map<int, int> hs;
int st[maxN], ed[maxN];
int N, M;

int work() {
  if(scanf("%d", &N) != 1) return 0;
  scanf("%d", &M);
  vector<int> a;a.clear();
  hs.clear();
  for(int i = 1; i <= N; i++) 
    scanf("%d", &st[i]);
  for(int i = 1; i <= M; i++) 
    scanf("%d", &ed[i]);
  for(int i = 1; i <= N; i++) 
    for(int j = 1; j <= M; j++) 
      if(ed[j] >= st[i]) 
        a.push_back(ed[j] - st[i]);
  hs.clear();
  int num = 0, ans = 0;;
  for(auto tt : a) {
    hs[tt]++;
    if(hs[tt] == num) {
      if(ans > tt) ans = tt;
    }
    if(hs[tt] > num) {
      num = hs[tt];
      ans = tt;
    }
  }
  printf("%d\n", ans);
  return 1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

