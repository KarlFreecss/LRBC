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

int N; 
int s[100];

int main() {
#ifndef ONLINE_JUDGE
//  freopen("J.in","r",stdin);
#endif
  cin >> N;
  s[0] = 32; 
  for(int i = 1; i <= 16; i++) s[i] = 16/i;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int xx; cin >> xx;
    ans += s[xx];
  }
  printf("%.8lf\n", (double) ans / 16.0);

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

