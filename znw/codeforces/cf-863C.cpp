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

const int maxN = 13;

inline int check(int a, int b) {
  if((a + 2) % 3 == b % 3) return 1;
  return 0;
}

int a[maxN][maxN], b[maxN][maxN];
int v[maxN][maxN];
ll alice = 0, bob = 0;
int pac[maxN], pbb[maxN];
int nowa, nowb;
ll K;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-863C.in","r",stdin);
#endif
  cin >> K >> nowa >> nowb;
  //cout << K << endl;
  rep(i, 1, 4)
    rep(j, 1, 4) cin >> a[i][j];
  rep(i, 1, 4)
    rep(j, 1, 4) cin >> b[i][j];
  ll ind = 1;
  while(ind <= K) {
    if(v[nowa][nowb] != 0) break;
  //  cout << ind << ":" << endl;
  //  cout << nowa << ' ' << nowb << endl;
    v[nowa][nowb] = ind;
    alice += check(nowa, nowb);
    bob += check(nowb, nowa);
  //  cout << alice << ' ' << bob << endl;
    pac[ind] = alice;
    pbb[ind] = bob;
    int ta = a[nowa][nowb], tb = b[nowa][nowb];
    nowa = ta; nowb = tb;
    ind ++;
  }
  int re = ind - v[nowa][nowb];
  //cout << "re = " << re << endl;
  int pre = v[nowa][nowb]-1;
  //cout << "pre = " << pre << endl;
  ll N = (K - pre) / re - 1;
  alice += N * (alice - pac[pre]);
  bob += N * (bob - pbb[pre]);
  ind +=  re * N;
  //cout << "ind = " << ind << endl;
  while(ind <= K) {
    alice += check(nowa, nowb);
    bob += check(nowb, nowa);
    int ta = a[nowa][nowb], tb = b[nowa][nowb];
    nowa = ta; nowb = tb;
    ind ++;
  }
  cout << alice << ' ' << bob << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

