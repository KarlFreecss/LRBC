#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int N;
string s;
int v[100];

int main() {
#ifndef ONLINE_JUDGE
  //freopen("B.in","r",stdin);
#endif
  cin >> N >> s;
  int ans = 0;
  int ta = 0;
  for(int i = 0; i < N; i++) {
    if(isupper(s[i])) {
      memset(v,0,sizeof(v));
      ta = 0;
      continue;
    }
    if(v[s[i] - 'a'] == 0) {
      v[s[i] - 'a'] = 1;
      ta ++;
    }
    ans = max(ans,ta);
  }
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}
