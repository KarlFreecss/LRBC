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

string s;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("I.in","r",stdin);
#endif
  cin >> s;
  int level = s.length();
  int x = 0; int y = 0;
  int dd = 1<<(level-1);
  for(int i = 0; i < level; i++) {
    int tt = s[i] - '0';
    x += (tt%2) * dd;
    y += (tt/2) * dd;
    dd >>= 1;
  }
  cout << level << ' ' << x << ' ' << y << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

