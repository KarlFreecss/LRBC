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

const int maxN = 100000 + 13;

int N, K, R;
int s[maxN],loc[maxN];
queue<int>q;

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  scanf("%d%d%d", &N, &K, &R);
  memset(loc, 0, sizeof(loc));
  memset(s, 0, sizeof(s));
  for(int i = 1; i <= K; i++) {
    int tt = 0;
    scanf("%d", &tt);
    loc[tt] = 1;
  }
  int ans = 0;
  for(int i = 1; i <= R; i++) {
    if(loc[i] == 1) 
      q.push(i);
  }
  if(q.size() == 0) {
    q.push(R-1); q.push(R);
    ans = 2;
  } else if(q.size() == 1) {
    if(q.front() == R) {
      q.pop();
      q.push(R-1);
      q.push(R);
    }
    else 
      q.push(R);
    ans=1;
  }
  for(int i = R+1; i <= N; i++) {
    if(q.front() == (i-R)) q.pop();
    if(loc[i] == 1) q.push(i);
    if(q.size() == 1) {
      ans++;
      q.push(i);
    }
  }
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

