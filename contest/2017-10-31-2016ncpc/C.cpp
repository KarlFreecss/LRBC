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

const int maxN = 55;

int N;
int a[maxN];
int f[maxN][maxN];
char s[maxN];
vector<int> st;

map<char, int> huase;
map<char, int> shuzi;

vector<int> v[5];

int check() {
  int ret = 0;
  memset(f,0,sizeof(f));
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      f[i][j] = max(f[i][j-1], f[i-1][j]);
      f[i][j] = max(f[i][j], f[i-1][j-1]+(a[i] == st[j]));
      ret = max(ret, f[i][j]);
    }
  }
  return ret;
}

int main() {
  huase['s'] = 100;
  huase['h'] = 200;
  huase['d'] = 300;
  huase['c'] = 400;

  rep(i, 1, 10) shuzi[(char)(i+'0')] = i;
  shuzi['T'] = 10;
  shuzi['J'] = 11;
  shuzi['Q'] = 12;
  shuzi['K'] = 13;
  shuzi['A'] = 14;

#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  scanf("%d", &N);
  rep(i, 1, 5) v[i].clear();
  rep(i, 1, N+1) {
    char buffer[13];
    scanf("%s", buffer);
    int tt = shuzi[buffer[0]] + huase[buffer[1]];
    v[tt/100].push_back(tt);
    a[i] = tt;
  }
  rep(i, 1, 5) {
    if(v[i].size() > 0) 
      sort(all(v[i]));
  }
  int p[13];
  int ans = N;
  rep(i, 1, 5) p[i] = i;
  do {
    for(int i = 0; i < (1<<4); i++) {
      st.clear();
      st.pb(0);
      for(int j = 1; j < 5; j++) {
        if(i & (1<<(j-1))) {
          for(int k = 0; k < v[p[j]].size(); k++) 
            st.pb(v[p[j]][k]);
        } else {
          for(int k = (int)v[p[j]].size()-1; k >= 0; k--) 
            st.pb(v[p[j]][k]);
        }
      }
      int ta = N - check();
      if(ta < ans) ans = ta;
    }
  } while(next_permutation(p+1, p+1+4));
  cout << ans <<endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

