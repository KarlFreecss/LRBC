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



int main() {

  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    int N;
    scanf("%d", &N);
    printf("Case #%d: %d\n", cas, N / 3);
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

