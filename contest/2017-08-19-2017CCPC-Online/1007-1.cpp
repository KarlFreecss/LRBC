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

ll build(vector<int> a, int base,int n) {
  int sz = a.size();
  vector<int> tt; tt.clear();
  for(int i = 0; i < sz; i++) 
    tt.push_back(a[i]);
  for(int i = 1; i <= sz; i++) 
    tt.push_back(a[sz-i]);
  ll ret = 0ll;
  sz = tt.size();
  if(tt[sz-1] == 0) return Mod;
  for(int i = 0; i < sz; i++) {
    if(tpow[base][i] == 0ll) {ret = Mod;break;}
    ret += tt[i] * tpow[base][i];
  }
  if(ret <= UP) v[base].push_back(n);
  tt.clear();
  sz = a.size();
  for(int i = 0; i < sz; i++) 
    tt.push_back(a[i]);
  tt.push_back(0);
  for(int i = 1; i <= sz; i++) 
    tt.push_back(a[sz-i]);
  sz = tt.size();
  if(tt[sz-1] == 0) return Mod;
  ret = 0;
  for(int i = 0; i < sz; i++) {
    if(tpow[base][i] == 0ll) {ret = Mod;break;}
    ret += tt[i] * tpow[base][i];
  }
  sz = a.size();
  for(int i = 0; i <= 9; i ++) {
    ret += tpow[base][sz];
    if(ret > UP) break;
    if(ret <= UP) v[base].push_back(n);
  }
  return ret;
}
void add(int n, int base) {
  vector<int> a;
  a.clear();
  int ind = 0;
  for(int i = 0; i <= 100; i++) {
    if(n == 0) {ind = i;break;}
    a.push_back(n % base);
    n /= base;
  }
  build(a,base,n);
  return ;
}

int L,R,l,r;

int main() {
#ifndef ONLINE_JUDGE
  freopen("1007.in","r",stdin);
#endif
  for(int i = 2; i <= 36; i++) {
    tpow[i][0] = 1;
    for(int j = 1; j <= 100; j++) {
      tpow[i][j] = tpow[i][j-1] * i;
      if(tpow[i][j] > Mod) break;
    }
  }
  for(int i = 1; i <= 30000; i ++) {
    for(int j = 2; j <= 36; j++) {
      add(i,j);
    }
  }
  for(int j =2 ; j<= 36; j++) {
    for(int i = 1; i < j ; i++) v[j].push_back(i);
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
      ans += (ed-st) * (i-1);
      ans += (R-L+1);
    }
    printf("%I64d\n",ans);
  }
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

