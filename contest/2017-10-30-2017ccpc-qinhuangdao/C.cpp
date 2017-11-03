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

string pattern[3] = {"aaa", "ggg", "ooo"};
string alp[3] = {"a", "g", "o"};
char buff[12];

int work(){
  scanf("%s", buff);
  string str = buff;
  int ans = 1;
  for (int i = 0; i < 3; ++i) {
    if (str.find(pattern[i]) != string::npos) {
      string strBuf = str;
      strBuf.erase(str.find(pattern[i]), 3);
      int a1 = strBuf.find(pattern[(i+1)%3]) != string::npos;
      int a2 = strBuf.find(pattern[(i+2)%3]) != string::npos;
      int anst = max(a1 + 2, a2 + 2);
      ans = max(ans, anst);
    }
  }
  for (int i = 0; i < 3; ++i) {
    string tryStr = str;
    for (int k = 0; k < 3; ++k) {
      tryStr.erase(tryStr.find(alp[i]), 1);
    }
    int t = 1;
    for (int k = 0; k < 3; ++k) {
      if (tryStr.find(pattern[k]) != string::npos) t = 2;
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

