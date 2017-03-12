#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

#define n1(xx) 
#define n2(xx) 

const int maxN = 3000+13;

map<string,int>hs;
map<string,vector<int>>cnt;
string name[maxN][2];
string s[maxN];
vector<int> e[maxN];
int l[maxN],rl[maxN];
int v[maxN];

bool find(int id) {
  if(v[id]) return false;
  v[id] = 1;
  for(auto tt:e[id]) {
    if(!l[tt] || find(l[tt])) {
        l[tt] = id;
        rl[id] = tt;
        return true;
    }
  }
  return false;
}

int main()
{
  int N;
  cin>>N;
  int ind = 0;
  rep(i,1,1+N) {
    cin>>name[i][0]>>name[i][1];
    string n1 = name[i][0].substr(0,3);
    string n2 = name[i][0].substr(0,2)+name[i][1].substr(0,1);
    cnt[n1].push_back(i);
    if(!hs[n1]) {
      hs[n1] = ++ind;
      s[ind] = n1;
    }
    if(!hs[n2]) {
      hs[n2] = ++ind;
      s[ind] = n2;
    }
    e[i].push_back(hs[n2]);
    e[i].push_back(hs[n1]);
  }
//  rep(i,1,1+N) {
//    cout<<i<<":";
//    for(auto tt:e[i]) {
//      cout<<tt<<' ';
//    }
//  }
  for(auto ts:cnt) {
    if(ts.second.size() > 1) {
      for(auto tt:ts.second) {
        e[tt].pop_back();
      }
    }
  }
  int ans = 0;
  rep(i,1,N+1) {
    rep(j,1,N+1) v[j] = 0;
    if(find(i)) ans++;
  }
  //cout<<ans<<endl;
  if(ans == N) {
    cout<< "YES" << endl;
    rep(i,1,1+N) {
      cout << s[rl[i]] << endl;
    }
  }
  else {
    cout << "NO" << endl;
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

