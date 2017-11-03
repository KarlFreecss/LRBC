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

int N,M;

int main() {
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif
  scanf("%d %d", &N,&M);
  set<int> s;
  stack<int> st;
  rep(i, 1, M+1) {
    int tt; scanf("%d", &tt);
    st.push(tt);
  }
  while(!st.empty()) {
    int tt = st.top();st.pop();
    if(s.find(tt) == s.end()) {
      printf("%d\n", tt);
      s.insert(tt);
    }
  }
  rep(i, 1, N+1) {
    int tt = i;
    if(s.find(tt) == s.end()) {
      printf("%d\n", tt);
      s.insert(tt);
    }
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

