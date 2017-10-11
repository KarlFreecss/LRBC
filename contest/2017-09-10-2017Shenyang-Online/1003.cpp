#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100;

set<int> f[46][91];
int N,a[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("1003.in","r",stdin);
#endif
  while(scanf("%d", &N) != EOF) {
    rep(i ,1 , N+1) 
      scanf("%d", &a[i]);
    rep(i, 0, N/2+1) {
      rep(j , 0, N+1) f[i][j].clear();
    }
    //cout <<__FILE__ << ":" << __LINE__ << endl;
    f[0][0].clear();
    f[0][0].insert(0);
    rep(i, 0, N/2+1) {
      rep(j,0,i*2 + 1) {
 //       cout << i << ' ' << j << endl;
        int tl = 0, tr = 0;
        int dl = 0, dr = 0;
        if(a[j+1] >= a[N-i*2+j]) {
          tl = tr = -a[j+1];
          dl = j+2; dr = j+1;
          tl += a[dl]; tr += a[N-i*2+j];
        } else {
          tl = tr = -a[N-i*2+j];
          dl = j+1; dr = j;
          tl += a[dl]; tr += a[N-i*2+j-1];
        }
        for(set<int>::iterator it=f[i][j].begin(); it!=f[i][j].end(); it++) {
          //cout << i << ' ' << j << ' ' << *it << endl;
          int tt = *it + tl;
          if(tt >= -100000 && tt <= 100000) 
            f[i+1][dl].insert(tt);
          tt = *it + tr;
          if(tt >= -100000 && tt <= 100000) 
            f[i+1][dr].insert(tt);
        }
      }
    }
    int ans = -10000000;
    //cout << " find ans " << endl;
    rep(i,0,N+1) {
      for(set<int>::iterator it=f[N/2][i].begin() ; it!=f[N/2][i].end(); it++) {
        //cout << N/2 << ' ' << i << ' ' << *it << endl;
        if(*it >= 0) break;
        if(ans < *it) ans = *it;
      }
    }
    if(ans == -10000000) {
      printf("The child will be unhappy...\n");
    } else {
      printf("%d\n", -ans);
    }
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

