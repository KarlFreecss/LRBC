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

int main() {
#ifndef ONLINE_JUDGE
#endif

  int n;
  scanf("%d", &n);
  set<int> count;
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    count.insert(c);
  }
  printf("%d\n", (int)(n - count.size()));
  return 0;
}

