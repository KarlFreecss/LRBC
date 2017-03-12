#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

void rotate(int a[]){
  int tmp[4] = {a[2], a[0], a[3], a[1]};
  for (int i = 0; i < 4; ++i) a[i] = tmp[i];
}

int a[4], b[4];

int check(int a[], int b[]){
  for (int i = 0; i < 4; ++i) if (a[i] != b[i]) return 0;
  return 1;
}

int work(int std){
  for (int i = 0; i < 4; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < 4; ++i) {
    scanf("%d", &b[i]);
  }

  for (int i = 0; i < 4; ++i) {
    if (check(a, b)) return 1;
    rotate(a);
    /*for (int k = 0; k < 2; ++k) {
      for (int l = 0; l < 2; ++l) {
      
      }puts("");
    }*/
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen("a.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    if (work(cas)) printf("Case #%d: %s\n", cas, "POSSIBLE");
    else printf("Case #%d: %s\n", cas, "IMPOSSIBLE");
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

