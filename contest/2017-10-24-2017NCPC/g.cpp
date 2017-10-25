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

#define debug(x) printf("[%d] " #x " = %d\n", __LINE__, x)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int MAXN = 1e5+5;
struct score{
  int num;
  int pen;

  bool operator < (const score & T) const {
    if (num != T.num) return num > T.num;
    return pen <= T.pen;
  }

  bool operator > (const score & T) const {
    if (num != T.num) return num < T.num;
    return pen > T.pen;
  }
} team[MAXN];

vector<int> procession[MAXN];

int n;
int betterThanMe = 0;

int main() {
#ifndef ONLINE_JUDGE
  //freopen("g.in","r",stdin);
#endif
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 2; i < n; ++i){
    procession[0].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    int t, p;
    scanf("%d%d", &t, &p);
    if (t != 1) {
      int flag = false;

      if (team[1] < team[t]) flag = 1;
      team[t].num++;
      team[t].pen += p;
      procession[team[t].num].push_back(t);
      if (flag) {
        if (team[1] > team[t]) ++betterThanMe;
      }
    } else {
      int myNum = team[t].num;
      for (int k = 0; k < procession[myNum].size(); ++k) {
        int id = procession[myNum][k];
        if (team[1] > team[id]) {
          if (team[id].num == myNum) 
            --betterThanMe;
        }
      }
      team[t].num++;

      team[t].pen += p;
      myNum = team[t].num;

      for (int k = 0; k < procession[myNum].size(); ++k) {
        if (team[1] < team[procession[myNum][k]]) --betterThanMe;
      }
    }
    printf("%d\n", betterThanMe + 1);
  }
  
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

