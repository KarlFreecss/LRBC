#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  freopen("1003.in","w",stdout);
  int N = 60;
  printf("%d\n",N);
  for(int i = 1; i <= N; i++) {
    int tt = rand() % 100000 + 1;
    cout << tt << ' ' ;
  }
  cout << endl;
  printf("%d\n",N);
  for(int i = 1; i <= N; i++) {
    int tt = rand() % 100000 + 1;
    cout << tt << ' ' ;
  }
  cout << endl;

  return 0;
}

