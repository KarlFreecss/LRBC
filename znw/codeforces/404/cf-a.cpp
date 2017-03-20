#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int N,ans=0;
string s;

int main()
{
  cin>>N;
  rep(i,1,N+1) {
    cin>>s;
    if(s[0] == 'T') ans+= 4;
    if(s[0] == 'C') ans+= 6;
    if(s[0] == 'O') ans+= 8;
    if(s[0] == 'D') ans+= 12;
    if(s[0] == 'I') ans+= 20;
  }
  cout<<ans<<endl;
  return 0;
}

