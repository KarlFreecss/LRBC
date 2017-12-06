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

int A, B;

void read(int& a) {
  double tf;
  scanf("%lf", &tf);
  a = (int)(tf * 100.0 + 0.5);
  return ;
}

map<int, int> hs;
string work() {
  string ret = "0.01";
  read(A); read(B);
  //cout << A << ' ' << B << endl;
  //cout << "-----" << hs[B] << endl;
  if(hs[B] == 1) {
    if(A == 2 * B) {
      return ret;
    } 
    return "0.02";
  }
  return ret;
}

int main() {
  for(int i = 1; i <= 10000; i*= 10) hs[i] = 1;
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: %s\n", cas, work().c_str());
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

