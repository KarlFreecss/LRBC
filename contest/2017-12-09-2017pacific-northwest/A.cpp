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

string a;

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  cin >> a;
  int l = a.length();
  bool ok = true;
  for(int i = 1; i < l; i++) {
    if(a[i] == a[i-1]) {
      ok = false;
    }
  }
  if(ok) 
    cout << "Odd." << endl;
  else 
    cout << "Or not." << endl;

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

