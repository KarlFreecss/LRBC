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

char s[maxN];
map<char, int> hs;
int v[30]; 
int ss[30][30];

int work() {
  if(scanf("%s", s) != 1) return 0;
  int endNum = 1<<19;
  int ans = 0, method = 0;
  int len = strlen(s);
  memset(ss,0,sizeof(ss));
  for(int i = 1; i < len; i++) {
    //cout << s[i-1] << ' ' << s[i] << endl;;
    if(hs[s[i]] == -1 || hs[s[i-1]] == -1) continue;
    ss[hs[s[i]]][hs[s[i-1]]] ++;
    //cout << "ok" << endl;
  }
  for(int i = 0; i < endNum; i++) {
    int tt = i;
    for(int i = 1; i < 20; i++) {
      v[i] = tt&1;
      tt >>= 1;
    }
    int ta = 0;
    for(int i = 1; i < 20; i++) {
      for(int j = 1; j < 20; j++) {
        if(v[i] + v[j] == 1) {
          ta += ss[i][j];
          ta += ss[i][j];
        }
      }
    }
    if(ta > ans) {
      ans = ta;
      method = i;
    }
  }
  for(int i = 1; i < 20; i++) {
    v[i] = method&1;
    method>>= 1;
  }
  for(int i = 0; i < len; i++) {
    if(hs[s[i]] == -1) continue;
    if(v[hs[s[i]]] == 1) {
      s[i] -= 32;
    }
  }
  printf("%s\n", s);
}
int main() {
  hs['a'] = -1;
  hs['e'] = -1;
  hs['i'] = -1;
  hs['o'] = -1;
  hs['u'] = -1;
  hs['w'] = -1;
  hs['y'] = -1;
  int ind = 1;
  for(int i = 0; i < 26; i++) {
    if(hs['a'+i] != -1) hs['a'+i] = ind++;
  }
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
#ifdef ONLINE_JUDGE
  freopen("consonant.in","r",stdin);
  freopen("consonant.out","w",stdout);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

