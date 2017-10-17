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

const int maxN = 1e6 + 13;
const ll Mod = 1e9+7;

inline int readInt() {
  int s = 1, c = getchar();
  int x = 0;
  while ( c <'0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return x;
}

int N, L, M;
ll temp[maxN];

void mul(ll *a , ll *b) {
  rep(i, 0, M) temp[i] = 0;
  rep(i, 0, M) {
    rep(j, 0, M) {
      int tt = (i+j) % M;
      temp[tt] = (temp[tt] + (a[i] * b[j]) % Mod) % Mod;
    }
  }
  rep(i, 0, M) a[i] = temp[i];
  return ;
}
ll a[maxN] , b[maxN], c[maxN];
ll s1[maxN] , t1[maxN];
ll ret[maxN]; 
void quickpow(int n) {
  //cout << n << endl;
  rep(i, 0, M) ret[i] = c[i];
  n--;
  while(n) {
  //  cout << n << endl;
    if(n & 1) mul(ret,c);
    mul(c,c);
    n >>= 1;
  }
  rep(i, 0, M) c[i] = ret[i];
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
  //freopen("cf-852B.in","r",stdin);
#endif
  N=readInt(); L = readInt(); M=readInt();
  L -= 2;
  rep(i ,1 , N+1) {
    int tt = readInt();
    tt %= M;
    s1[tt] ++;
  }
  rep(i ,1 , N+1) {
    int tt = readInt();
    a[i] = tt;
    tt %= M;
    c[tt] ++;
  }
  rep(i ,1 , N+1) {
    int tt = readInt();
    tt = (tt + a[i]) % M;
    t1[tt] ++;
  }
  //rep(i,0,M) 
  //  cout << i << ' ' ;
  //cout << endl;
  //rep(i,0,M) 
  //  cout << s1[i] << ' ' ;
  //cout << endl;
  mul(s1,t1);
  //rep(i,0,M) 
  //  cout << i << ' ' ;
  //cout << endl;
  //rep(i,0,M) 
  //  cout << s1[i] << ' ' ;
  //cout << endl;
  if(L > 0) {
    //cout << "xx" << endl;
    quickpow(L);
    mul(s1,c);
  }
  //rep(i,0,M) 
  //  cout << s1[i] << ' ' ;
  //cout << endl;
  ll ans = s1[0];
  cout << ans << endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

