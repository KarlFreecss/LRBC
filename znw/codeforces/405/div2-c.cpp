#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 50+13;

int N,K;
string ta[maxN];
string ans[maxN];
int sta[maxN];

int main()
{
  int ind = 0;
  for(int i = 1; i<=26 && ind<=60;i++) {
    for(int j = 1; j<=26 && ind<=60; j++) {
      string ts = "";
      ts = (char)(i+'A'-1) ;
      ts += (char) (j+'a'-1) ;
      ind++;
      ta[ind] = ts;
    }
  }
  cin>>N>>K;
  for(int i = 1; i <= N-K+1; i++) {
    string ts;
    cin >> ts;
    if(ts == "NO") sta[i] = 0;
    else sta[i] = 1;
  }
  int end = 1;
  ans[1] = ta[1];
  ind = 1;
  bool fi = true;
  for(int i =1; i <= N-K+1; i++) {
    if(sta[i] == 0) {
      end++;
      ans[end] = ans[i];
    }
    else{
      if(fi) {
        fi = false;
        for(int j = end+1; j<=i+K-1; j++) ans[j] = ta[++ind];
        end = i+K-1;
      }
      else {
        end++;
        ans[end] = ta[++ind];
      }
    }
  }
  while(end < N) {
    end++;
    ans[end] = ta[++ind];
  }
  cout << ans[1];
  rep(i,2,N+1) {
    cout << ' ' << ans[i];
  }
  cout<<endl;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

