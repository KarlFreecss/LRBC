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

const int maxN = 21 + 13;

int N;
string ball[maxN];
map<string, int> sc;

int main() {
  sc["red"] = 1;
  sc["yellow"] = 2;
  sc["green"] = 3;
  sc["brown"] = 4;
  sc["blue"] = 5;
  sc["pink"] = 6;
  sc["black"] = 7;

#ifndef ONLINE_JUDGE
//  freopen("C.in","r",stdin);
#endif
  cin >> N;
  int countRed = 0;
  int ans = 0;
  int imax = 0;
  for(int i = 1; i <= N; i++) {
    cin >> ball[i];
    ans += sc[ball[i]];
    imax = max(imax, sc[ball[i]]);
    if(ball[i] == "red") countRed ++;
  }
  if(countRed == 0) {
    cout << ans << endl;
    return 0;
  }
  if(countRed == N) {
    cout << 1 << endl;
    return 0;
  }
  ans += imax * countRed;
  cout << ans << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

