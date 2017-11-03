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

const int maxN = 100 + 13;

struct Point {
  int x,y,dis;
  int id;
  friend bool operator < (const Point& a, const Point& b) {
    return a.dis < b.dis;
  }
};

int N, R, r;
int T;
Point p[maxN];

inline int sqr(int x) {
  return x*x;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("M.in","r",stdin);
#endif
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d", &N,&R,&r);
    rep(i, 1, N+1) {
      scanf("%d%d", &p[i].x, &p[i].y);
      p[i].dis = sqr(p[i].x) + sqr(p[i].y);
      p[i].id = i;
    }
    sort(p+1, p+1+N);
    int new_r;
    new_r = sqr(R-r-r);
    r = sqr(r);
    R = sqr(R);
    int ans = 0;
    vector<int> ans_id;
    ans_id.clear();
    bool ok = false;
    int min_dis = 200000000;
    rep(i, 1, N+1) {
      if(p[i].dis <= new_r) p[i].dis = 0;
    }
    rep(i, 1, N+1) {
      if(ok) {
        if(p[i].dis == p[i-1].dis) {
          ans++;
          ans_id.pb(p[i].id);
        } else break;
      } else {
        ok = true;
        ans++;
        ans_id.pb(p[i].id);
      }
    }
    sort(all(ans_id));
    printf("%d\n", ans);
    printf("%d", ans_id[0]);
    rep(i, 1, ans) {
      printf(" %d", ans_id[i]);
    }
    printf("\n");
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

