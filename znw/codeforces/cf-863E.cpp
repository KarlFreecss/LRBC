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

const int maxN = 8e5 + 13;

int N;
int s[maxN];
vector<int> xx;
int st[maxN], ed[maxN];
map <int,int> hs;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("cf-863E.in","r",stdin);
#endif
  scanf("%d", &N);
  xx.clear(); hs.clear();
  rep(i, 1, N+1) {
    int l,r;
    scanf("%d%d", &l, &r);
    st[i] = l, ed[i] = r;
    xx.pb(l); xx.pb(r);
    xx.pb(l-1); xx.pb(r);
  }
  sort(all(xx));
  xx.erase(unique(all(xx)),xx.end());
  rep(i,1,xx.size()+1) {
    hs[xx[i-1]] = i;
  }
  rep(i, 1, N+1) {
    s[hs[st[i]]] += 1;
    s[hs[ed[i]]+1] -= 1;
  }
  s[0] = 0;
  rep(i, 1, xx.size()+1) 
    s[i] += s[i-1];
  rep(i, 1, xx.size()+1) {
    if(s[i] == 1 || s[i] == 0) s[i] = 1;
    else s[i] = 0;
  }
  rep(i, 1, xx.size()+1) 
    s[i] += s[i-1];
  rep(i, 1, N+1) {
    int tl = hs[st[i]]-1;
    int tr = hs[ed[i]];
  //  cout << tl << ' ' << tr << endl;
    if(s[tr] - s[tl] == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}

