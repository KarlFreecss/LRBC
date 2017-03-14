#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 1e5+13;

int N;
int a[maxN];

int main()
{
  cin>>N;
  int ans = 0, sum = 0;
  rep(i,1,2*N+1) {
    int tt;
    cin>>tt;
    a[tt]++;
    if(a[tt] == 1) sum++;
    if(a[tt] == 2) sum--;
    if(sum > ans) ans =sum;
  }
  cout<<ans<<endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

