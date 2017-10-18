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

int N;
ll len[10];

int ans(int n, int l) {
  int ret = 0;
  rep(i, 1, l+1) {
    ret = n % 26;
    n /= 26;
  }
  return ret;
}
int main() {
  rep(i, 1, 9) {
    len[i] = i;
    rep(j , 0, i) len[i] *= 26;
  //  cout << i << " : " << len[i] << endl;
  }
  while(scanf("%d", &N) != EOF) {
    int ll = -1;
    for(int i = 1; i <=9; i++) {
      if(len[i] > N) {
        ll = i;
        break;
      }
      N -= len[i];
    }
    int ind = N / ll;
    //cout << "index : " << ind << endl;
    //cout << ll << endl;
    printf("%c\n", (char)(ans(ind, ll - N%ll) + 'A'));;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

