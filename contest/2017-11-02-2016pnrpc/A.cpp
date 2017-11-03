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

const int maxN = 100;

string s;
string s0;
int f[maxN][maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  s0 = "";
  for(int i = 0; i < 26; i++) {
    s0+= (char)('a'+i);
  }
  s0 = "0" + s0;
  cin >> s;
  int len = s.length();
  s = "0" + s;
  int ans = 0;
  memset(f,0,sizeof(f));
  for(int i = 1; i <= len; i++) {
    for(int j = 1; j <= 26; j++) {
      f[i][j] = max(f[i-1][j], f[i][j-1]);
      f[i][j] = max(f[i][j], f[i-1][j-1] + (s[i] == s0[j]));
      ans = max(ans, f[i][j]);
    }
  }
  cout << 26 - ans << endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

