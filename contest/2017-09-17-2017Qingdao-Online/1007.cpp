#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 200+13;
int N;
int f[maxN][maxN];
int a[maxN];
char s[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("1007.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    memset(f,0x3f,sizeof(f));
    scanf("%s", &s);
    //cout << s << endl;
    int l = strlen(s);
    rep(i, 0, l) a[i+1] = s[i] -'0';
    a[l+1] = -1;
    vector<int> tt; tt.clear();
    for(int i = 1; i <= l; i++) {
      if(tt.size() <= 1){
        tt.push_back(a[i]);
        continue;
      }
      if(a[i] == a[i+1]) {
        tt.push_back(a[i]);
        continue;
      }
      if(a[i] == tt.back() && a[i] == tt[tt.size() - 2]) {
        while(tt.back() == a[i]) tt.pop_back();
      } 
      tt.push_back(a[i]);
    }
    l = tt.size();
    for(int i = 1; i <= l; i++) a[i] = tt[i-1];

    for(int i = 1; i <= l; i++) { 
      f[i][i] = 2;
      if(a[i] == a[i+1]) f[i][i+1] = 1;
      else f[i][i+1] = 4;
      for(int j = i+2; j <= l; j++) {
        if(a[i] != a[i+1]) break;
        if(a[i] == a[j]) {
          f[i][j] = 0;
        } else break;
      }
    }
    //cout << l << endl;
    //for(int i = 1; i<= l; i++) cout << i <<' '; cout << endl;
    //for(int i = 1; i<= l; i++) cout << a[i] <<' '; cout << endl;
    for(int k = 3; k <= l; k++) {
      for(int i = 1; i <= l; i++) {
        if(i + k - 1 > l) break;
        int j = i + k - 1;
        if(f[i][j] <= 1) continue;
        int sl = i;for(;sl <=j; sl++) if(a[i] != a[sl]) break;
        int sr = j;for(;sr >=i; sr--) if(a[j] != a[sr]) break;
        //if(i == 3 && j == 6) {
        //  cout << __FILE__ << ":" << i << ' ' << j << endl;
        //  cout << sl << ' ' << sr << endl;
        //}
        if(a[i] == a[j]) {
          for(int tl = i; tl <= sl; tl++) {
            for(int tr = j; tr >= sr; tr--) {
              if(tl - i + j - tr == 0) continue;
              int ts = tl - i + j - tr;
              ts = 3 - ts;
              if(ts < 0) ts = 0;
              f[i][j] = min(f[i][j], f[tl][tr] + ts);
            }
          } 
        } else {
          for(int tl = i+1; tl <= sl; tl++) {
            for(int tr = j-1; tr >= sr; tr--) {
              int ts = max(3 - tl + i,0) + max(3 - j + tr, 0);
              f[i][j] = min(f[i][j], f[tl][tr] + ts);
            }
          }
          for(int tl = i; tl <= i; tl++) {
            for(int tr = j-1; tr >= sr; tr--) {
              int ts = max(3 - j + tr, 0);
              f[i][j] = min(f[i][j], f[tl][tr] + ts);
            }
          }
          for(int tl = i+1; tl <= sl; tl++) {
            for(int tr = j; tr >= j; tr--) {
              int ts = max(3 - tl + i,0) ;
              f[i][j] = min(f[i][j], f[tl][tr] + ts);
            }
          }
        }
        for(int in = i; in < j ; in++) 
          f[i][j] = min(f[i][j],f[i][in]+f[in+1][j]);
      }
    }
    //cout << f[4][5] << endl;
    //cout << f[3][6] << endl;
    //cout << f[2][8] << endl;
    //cout << f[1][9] << endl;
    //cout << f[9][9] << endl;
    //cout << f[7][13] << endl;
    printf("Case #%d: %d\n", cas, f[1][l]);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

