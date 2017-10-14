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

const int MAXP = 1024;
vector<int> P;
int Pb[MAXP];

void initP(){
  Pb[1] = 1;
  Pb[0] = 1;
  for (int i = 2; i <= 1000; ++i) {
    if (Pb[i]) continue;
    P.push_back(i);
    for (int k = i + i; k <= 1000; k += i) {
      Pb[k] = 1;
    }
  }
}

const int MAXN = 1e5 + 5;
const int MAXX = 1e6 + 6;
int f[MAXX];
int a[MAXN];
vector<int> s;

int find(int x){
  if (x != f[x]) return f[x] = find(f[x]);
  return x;
}

void work(){
  int n;
  s.clear();
  scanf("%d", &n);
  int maxX = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
    if (a[i] == 1) ++ans;
    maxX = max(maxX, a[i]);
  }
  for (int i = 1; i <= maxX; ++i) {
    f[i] =  i;
  }
  for (int i = 0; i < n; ++i) {
    int lastN = 1;
    for (int k = 0; k < P.size(); ++k) {
      if (a[i] % P[k] == 0) {
        if (lastN != 1) {
          int fa = find(lastN);
          int fb = find(P[k]);
          if (fa != fb) {
            f[fa] = fb;
          }
        }
        s.push_back(P[k]);
        lastN = P[k];
        a[i] /= P[k];
        while (a[i] % P[k] == 0) a[i] /= P[k];
      }
    }
    if (a[i] != 1 && lastN != 1) {
      int fa = find(a[i]);
      int fb = find(lastN);
      if (fa != fb) {
        f[fa] = fb;
      }
    }
    if (a[i] != 1)
      s.push_back(a[i]); 
  }
  set<int> count;
  for (int i = 0; i < s.size(); ++i) {
    count.insert(find(s[i]));
  }
  ans += count.size();
  printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("F.in","r",stdin);
#endif
  initP();
  //cout << P.size() << endl;
  //for (int i = 0; i < P.size(); ++i) {
  //  cout << P[i] << endl;
  //}
  //
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i){
    printf("Case %d: ", i);
    work();
  }
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

