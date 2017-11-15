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
  vector<priority_queue<int>> que(n+1);
  vector<int> num(n+1);
  que[0].push(-n);
  for (int i = 1; i <= n; ++i) {
    num[i] = n;
    for (int j = 1; j <= n; ++j) {
      if (i != j) que[i].push(-j);
    }
  }
  num[n]--;
  num[0] = 1;
  int index = n;
  printf("%d %d %d\n", n, n, 0);
  int opt = 1;
  while (true) {
    int x = -que[index].top(); que[index].pop();
    if (num[x] == 1) break;
    printf("%d %d %d\n", x, x, index);
    --num[x];
    index = x;
    ++opt;
  }
  assert(opt == n * (n - 1));
  assert(n != index);
  printf("%d %d %d\n", 0, n, index);
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif

  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

