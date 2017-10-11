#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const ll MO = 1e9+7;
const int MAXN = 1e4+5;

int table[MAXN][6];

void init(){
  for (int i = 1; i < MAXN; ++i) {
    table[i][0] = 1;
    for (int k = 1; k < 6; ++k) {
      table[i][k] = (ll)table[i][k-1] * i % MO;
    }
  }
  for (int i = 1; i < MAXN; ++i) {
    for (int k = 0; k < 6; ++k) {
      table[i][k] = (table[i][k] + table[i-1][k]) % MO;
    }
  }
}

void party_always_exist(int id){
  int n, k;
  int ans = 0;
  scanf("%d%d", &n, &k);
  cout << table[n][k] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("e.in","r",stdin);
#endif
  int T;
  init();
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    party_always_exist(i);
  }
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

