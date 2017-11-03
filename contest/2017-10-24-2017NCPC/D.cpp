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

const int maxN = 1000000+13;
const int maxM = (1<<21) + 13;
const int maxB = 20 + 13;

bool v[maxM];
int N, K;
int p2[maxB];
queue<int> q;
char s[maxB];

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  p2[0] = 1;
  rep(i, 1, 21) p2[i] = p2[i-1] << 1;
  scanf("%d%d", &N, &K);
  rep(i ,1 , N+1) {
    scanf("%s", s);
    int ta = 0;
    rep(j, 0, K) 
      ta += (s[j]-'0') * p2[j];
    q.push(ta);
    v[ta] = 1;
  }
  int ans = -1;
  while(!q.empty()) {
    int id = q.front();q.pop();
    ans = id;
    rep(i,0,K) {
      int tid = id^p2[i];
      if(v[tid]) continue;
      q.push(tid);
      v[tid] = 1;
    }
  }
  rep(i, 0, K) {
    printf("%d", ans&1);
    ans >>= 1;
  }
  printf("\n");
  return 0;
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

