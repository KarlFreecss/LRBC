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
const int maxK = 40;
const ll Mod = 1e13;
const ll UP = 1e9;

ll tpow[maxK][maxN];
vector<int> v[maxK];
int T;

ll tans = 0,rans = 0;
ll build(int sz, int base, int flag) {
  if(flag) {
    ll ret = tans * tpow[base][sz-1];
    ret += rans;
    return ret;
  } else {
    ll ret = tans * tpow[base][sz];
    ret += rans;
    return ret;
  }
}

void dfs(int now, int all,int base) {
  if(now == all+1) {
    return ;
  }
  for(int i = 0 + (now == 1); i < base; i++) {
    tans = tans * base + i;
    ll b = build(now,base,1);
    if(b < UP) v[base].push_back(b);
    rans = rans + tpow[base][now-1] * i;
    b = build(now,base,0);
    if(b < UP) v[base].push_back(b);
    dfs(now+1, all,base);
    tans /= base;
    rans = rans - tpow[base][now-1] * i;
  }
  return ;
}

int L,R,l,r;
int len[maxK];

int main() {
#ifndef ONLINE_JUDGE
  //freopen("1007.in","r",stdin);
#endif
  for(int i = 2; i <= 36; i++) {
    tpow[i][0] = 1;
    for(int j = 1; j <= 100; j++) {
      tpow[i][j] = tpow[i][j-1] * i;
      if(tpow[i][j] > UP){len[i] = (j+1)/2; break;}
    }
  }
  for(int j = 2; j <= 36; j++) {
    dfs(1,len[j], j);
  }
  for(int j =2 ; j<= 36; j++) {
    sort(v[j].begin(), v[j].end());
  }
  scanf("%d", &T);
  rep(cas , 1, T+1) {
    printf("Case #%d: ", cas);
    scanf("%d%d%d%d", &L, &R, &l, &r);
    ll ans = 0 ;
    for(int i = l; i <= r; i++) {
      int st = lower_bound(v[i].begin(), v[i].end(), L) - v[i].begin();
      //if(v[i][st] == L) st--;
      int ed = upper_bound(v[i].begin(), v[i].end(), R) - v[i].begin();
      //cout << i << ' ' << st << ' ' << ed << endl;
      ans += (ed-st) * (i-1);
      ans += (R-L+1);
    }
    printf("%I64d\n",ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

