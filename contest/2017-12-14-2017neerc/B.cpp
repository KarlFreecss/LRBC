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

long long a[5];
long long N, M;

bool ok(int w, int h) {
  if(w > h) swap(w, h);
  if(w <= N && h <= M) return true;
  return false;
}

bool check(int x, int y, int z) {
  int tw, th;
  //1
  th = 2 * x + 2 * z;
  tw = y + 2 * z; 
  if(ok(th, tw)) return true;
  //2, 4
  th = 2 * x + 2 * z;
  tw = 2 * x + y; 
  if(ok(th, tw)) return true;
  //3 , 5 , 6
  th = 2 * x + 2 * z;
  tw = x + y + z; 
  if(ok(th, tw)) return true;
  if(ok(th, tw)) return true;
  //7
  th = 2 * x + y + z;
  tw = y + 2 * z;
  if(ok(th, tw)) return true;
  //8
  th = x + y + z;
  tw = x + z + y + z;
  if(ok(th, tw)) return true;
  //9
  th = x + z;
  tw = 3 * y + x + z;
  if(ok(th, tw)) return true;
  //10
  th = x + 2 * y + z;
  tw = x + y + z;
  if(ok(th, tw)) return true;
  //11
  th = x + y + 2 * z;
  tw = 2 * x + y;
  if(ok(th, tw)) return true;
  return false;
}

bool work() {
  if (scanf("%lld%lld%lld", &a[0], &a[1], &a[2]) != 3) return false;
  scanf("%lld%lld", &N, &M);
  if(N > M) swap(N, M);
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) if(i != j) {
      for (int k = 0; k < 3; k ++) if(k != i && k != j){
        if(check(a[i], a[j], a[k])) {
//          cout << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
          printf("Yes\n");
          return true;
        }
      } 
    }
  }
  printf("No\n");
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif

  while (work());
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

