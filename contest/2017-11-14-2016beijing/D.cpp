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

const int maxN = 200+13;

int a[maxN];

int work() {
  int N;
  scanf("%d", &N);
  if(N == 0) return 0;
  memset(a, 0, sizeof(a));
  for(int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
    a[i+N] = a[i];
  }
  int ans = 1;
  for(int i = 1; i <= N; i++) {
    int ta = 1;
    for(int j = i+1; j < i+N; j++) {
      if(a[j] > a[j-1]) ta++;
      else ta = 1;
      ans = max(ans, ta);
    }
    ta = 1;
    for(int j = i+1; j < i+N; j++) {
      if(a[j] < a[j-1]) ta++;
      else ta = 1;
      ans = max(ans, ta);
    }
  }
  printf("%d\n", ans-1);
  return 1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  while(work());

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

