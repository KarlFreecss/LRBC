#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN=40000+13;

int N,M;
vector<pair<int,int>> e[maxN];

int main() {
  int T;
  scanf("%d",&T);
  while(T--) {
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) e[i].clear();
    for(int i=1;i<N;i++) {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      e[x].push_back(make_pair(y,z));
      e[y].push_back(make_pair(x,z));
    }
    for(int k=1;k<=M;k++) {
      int tt,x,y,z;
      scanf("%d",&tt);
      if(tt==0) {
        scanf("%d",&x);
        int ans=0;
        for(auto v:e[x])
          ans+=v.second&1;
        ans%=2;
        if(ans==0)
          printf("Boys win!\n");
        else
          printf("Girls win!\n");
      //  cout<<(ans%2)<<endl;
      }
      else {
        scanf("%d%d%d",&x,&y,&z);
        //cout<<x<<' '<<y<<' '<<z<<endl;
        for(int i=0;i<siz(e[x]);i++) if(e[x][i].first==y){
          e[x][i].second=z;
        }
        for(int i=0;i<siz(e[y]);i++) if(e[y][i].first==x){
          e[y][i].second=z;
        }
      }
    }
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

