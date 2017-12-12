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

int work(){
  int n;
  if (scanf("%d", &n) != 1) return false;
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  for (int j = 0; j < n; ++j) {
    int x;
    scanf("%d", &x);
    b.push_back(x);
  }
  long long ans[3] = {0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[(i + j + 1 + 1) % 3] += a[i] * b[j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    printf("%lld%c", ans[i], i+1==3?'\n':' ');
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif

  while (work());
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

