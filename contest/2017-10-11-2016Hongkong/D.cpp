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

const int maxN = 70 + 13;
const int maxM = 70 * 70 * 2 + 13;

int K, N;
int p[maxN], c[maxN];
set<int> S;
int sh[maxN];
ll ch[maxN][maxN * maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen(".in","r",stdin);
#endif
  scanf("%d%d", &N, &K);
  rep(i, 1, N+1) {
    scanf("%d%d", &p[i], &c[i]);
    rep(i, 0, N+1) S.insert(p[i]+i);
    rep(i, 0, N+1) if(p[i] > i) S.insert(p[i]-i);
  }
  int ind = 1;
  for(auto tt:S) {
    sh[tt] = ind;
    ind++;
    rep(i, 1, N+1) ch[i][ind] = (ll) c[i] * (tt - p[i]);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

