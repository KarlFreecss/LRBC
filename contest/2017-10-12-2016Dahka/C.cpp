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

int n, q;

struct point{
  unsigned int x, y;
};

struct Query{
  int ans;
  int id;
  unsigned int r;

  bool operator < (const Query & T) const {
    return r < T.r;
  }
} query[1010];


unsigned int dist(const point & A, const point & B){
  ll dx = A.x - B.x;
  ll dy = A.y - B.y;
  return dx * dx + dy * dy;
}

//vector<point> p;
//vector<unsigned int> dis[3000];
unsigned int dis[3000][3000];
point p[3000];
vector<unsigned int> empty(3000);
int buff_[1010];

inline int readChar() {
  int c = getchar();
  while (c <= 32)
    c = getchar();
  return c;
}

vector<int> ans(3000);

inline unsigned int readInt() {
  int x = 0;
  char c = getchar();
  while(c < '0' || c > '9') c = getchar();
//  if (c == '-')
//    s = 1, c = readChar();
  while ('0' <= c && c <= '9') 
    x = x * 10 + c - '0', c = getchar();
  return x;
}

void work(){
  for (int i = 0; i < n; ++i) {
    p[i].x = readInt();
    p[i].y = readInt();
  }
  for (int i = 0; i < q; ++i){
    unsigned int r;
    scanf("%u", &r);
    query[i].id = i;
    query[i].r = r * r;
    query[i].ans = 0;
  }
  sort(query, query + q);
  for (int i = 0; i < q; ++i) {
    buff_[i] = query[i].r;
   // cout << buff_[i] << ' ';
  }// cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      unsigned int d = dist(p[i], p[j]);
      int index = lower_bound(buff_, buff_ + q, d) - buff_;
      if (index >= q) continue;
    //  cout << index << ' ';
      query[index].ans++;
    }
  }
  //cout << endl;
  ans.resize(q);
  ans[query[0].id] = query[0].ans;
  for (int i = 1; i < q; ++i) {
    query[i].ans += query[i-1].ans; 
    ans[query[i].id] = query[i].ans;
    //cout << ans[query[i].id] << ' ';
  }
  //cout << endl;
  for (int i = 0; i < q; ++i) {
    printf("%.2lf\n", ans[i]*1./n);
  }
  printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("C.in","r",stdin);
#endif
  while (scanf("%d%d", &n, &q) == 2) {
    if (!(n || q)) break;
    work();
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}
