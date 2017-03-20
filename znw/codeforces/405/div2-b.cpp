#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;
const int maxN=150000+13;


int p[maxN];
inline void init(int n) {for(int i=0;i<=n;++i) p[i]=i; }
inline int root(int i){for(;i!=p[i];i=p[i]) p[i]=p[p[i]]; return i;} 
inline void unite(int a, int b){p[root(b)]=root(a);}
inline bool query(int a, int b){return root(a)==root(b);}

int N,M;
int in[maxN];
int a[maxN],b[maxN];
int rk[maxN];
ll se[maxN],s[maxN];
map<int,int> hs;

int main()
{
  scanf("%d%d",&N,&M);
  init(N+1);
  rep(i,0,M) {
    scanf("%d%d",&a[i],&b[i]);
    in[a[i]]++;in[b[i]]++;
    if(!query(a[i],b[i])) unite(a[i],b[i]);
  }
  int ind = 0;
  rep(i,1,N+1) {
    int rt = root(i);
    int tt = hs[rt];
    if(hs[rt] == 0) {
      ++ind;
      hs[rt] = ind;
      tt = ind;
    }
    se[tt]+=in[i];
    s[tt]++;
  }
  bool ans = true;
  rep(i,1,ind+1) {
    if(se[i] != s[i]*(s[i]-1) ) {
      ans = false;
    }
  }
  if(ans) 
    printf("YES\n");
  else 
    printf("NO\n");
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

