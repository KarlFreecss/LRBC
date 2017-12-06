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

const int MAXN = 1e3+3;
int a[MAXN];
int c[MAXN];
int b[MAXN];

int work(){
  int n;
  scanf("%d", &n);
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(c, 0xff, sizeof(c));
  for (int i = 0; i < n; ++i) {
    if (c[i] == -1) {
      for (int j = i; j < n; ++j) {
        if (a[i] == a[j]) c[j] = i;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    memset(b, 0, sizeof(b));
    for (int j = i; j < n; ++j) {
      if (b[c[j]]) break;
      ans = max(ans, j - i + 1);
      b[c[j]] = 1;
      if (ans > n - i) break;
      int beg = n-1;
      for (int k = n-1; k > j; --k) {
        ++b[c[k]];
        while (beg >= k && b[c[k]] > 1) {
        //printf("i = %d, j = %d, k = %d, c[k] = %d\n", i, j, k, c[k]);
          --b[c[beg--]];
        }
        //cout << beg << endl;
        //printf("i = %d, j = %d, beg = %d, k = %d\n", i, j, beg, k);
        ans = max(ans, j - i + 1 + beg - k + 1);
      }
    }
  }
  cout << ans << endl;
  ans = -1;
  for(int st1 = 0; st1 < n; st1++) {
    for(int ed1 = st1; ed1 < n; ed1 ++) {
      memset(b, 0, sizeof(b));
      bool ok = true;
      for(int i = st1; i <= ed1 ; i++){
        if(b[c[i]] == 1) {
          ok = false;
          break;
        }
        b[c[i]] = 1;
      }
      if(!ok) continue;
      ans = max(ans, ed1 - st1 + 1);
      for(int st2 = ed1 + 1; st2 < n; st2++) {
        for(int ed2 = st2; ed2 < n; ed2 ++) {
          bool ok = true;
          for(int i = st2; i <= ed2 ; i++) {
            if(b[c[i]] == 1) {
              ok = false;
              break;
            }
            b[c[i]] = 1;
          }
          if(ok) {
            ans = max(ans, ed1-st1+ed2-st2+2);
          }
        }
      }
    }
  }
  cout << ans << endl;
  /*
  for(int i = 0; i < n; i++) {
    memset(b, 0, sizeof(b));
    int ed = i;
    for(int j = i; j < n; j++) {
      if(b[c[j]]) break;
      ans = max(ans, j - i + 1);
      b[c[j]] = 1;
      ed = j;
    }
    int st2 = n;
    for(int j = ed + 1; j < n; j++) {
      if(b[c[j]]) continue;
      st2 = j;
      break;
    }
    int ed2 = n+1;
    for(;ed >= i; ed--) {
      while(ed2 <= n) {
        if(b[c[ed2]]) break;
        ed2++;
        ans = max(ans, ed2 - st2 + ed - i + 1);
      }
    }
  }
  */
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif

  int Cas;
  scanf("%d", &Cas);
  for (int i = 1; i <= Cas; ++i) {
    printf("Case #%d: %d\n", i, work());
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

