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

const int maxN = 2000 + 13;
const int inf = 0x3f3f3f3f;

int f[maxN][maxN];
char s[maxN][maxN];
int N, K;
deque<pii> q[maxN];
deque<pii> qh;

int work() {
  if(scanf("%d%d", &N, &K) != 2) return 0;
  for(int i = 1; i <= N; i++) {
    scanf("%s", &s[i][1]);
 //   cout << s[i]+1 << endl;
  }
  for(int i = 1; i <= N; i++) 
    while(!q[i].empty()) 
      q[i].pop_back();
  memset(f, inf, sizeof(f));
  f[1][1] = 0;
  q[1].push_back(make_pair(1, f[1][1]));
  for(int j = 2; j <= N; j++) {
    for(int k = j-1; k >= 1 && j - k <= K; k--) 
      f[1][j] = min(f[1][j], f[1][k] + 1);
    if(s[1][j] == '#') f[1][j] = f[0][0];
    q[j].push_back(make_pair(1, f[1][j]));
  }
  for(int i = 2; i <= N; i++) {
    while(!qh.empty()) qh.pop_back();
    for(int j = 1; j <= N; j++) {
      int temp = q[j].front().second + 1;
      if(!qh.empty()) 
        temp = min(temp , qh.front().second + 1);
      if(s[i][j] == '#' || temp > f[0][0]) 
        temp = f[0][0];
      f[i][j] = temp;
      while(!q[j].empty() && q[j].front().first < i - K + 1) q[j].pop_front();
      while(!q[j].empty() && q[j].back().second > temp) q[j].pop_back();
      q[j].push_back(make_pair(i, temp));
      while(!qh.empty() && qh.front().first < j - K + 1) qh.pop_front();
      while(!qh.empty() && qh.back().second > temp) qh.pop_back();
      qh.push_back(make_pair(j, temp));
    }
  }
  if(f[N][N] == f[0][0]) {
    printf("-1\n");
  } else {
    printf("%d\n", f[N][N]);
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

