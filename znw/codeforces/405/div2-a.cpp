#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int N,M;

int main()
{
  cin>>N>>M;
  int ans = 0;
  for(;N <= M;ans++) {
    N*=3;
    M*=2;
  }
  cout<<ans<<endl;

  return 0;
}

