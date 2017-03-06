#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxBit=2e5+1;
const int maxN=2e5+1;
//template<int maxBit>
struct TNode{
  bitset<maxBit> b;
  void update(){
  }
  void set(const TNode& x, const TNode& y){
    b = x.b | y.b;
  }
}ST[maxN*3];

int N,T,Q;
int rk[maxN],a[maxN];

void build(int l,int r,int k) {
  if(l==r) {
    ST[k].b[rk[a[l]]]=1;
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, k << 1);
  build(mid+1, r ,(k << 1) + 1);
  ST[k].set(ST[k << 1], ST[(k << 1) + 1]);
}

bitset<maxBit> query(const int L, const int R, const int l, const int r, const int k){
  if(r < L || R < l) return 0;
  if(L <= l && r <= R )return ST[k].b;
  int mid = (l + r) >> 1;
  return query(L, R, l, mid, k << 1) | query(L, R, mid + 1, r, (k << 1) + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif
  scanf("%d",&T);
  rep(cas, 1, T + 1) {
    int ind=0;
    memset(rk, 0, sizeof(rk));
    scanf("%d%d", &N, &Q);
    printf("Case #%d:",cas);
    rep(i, 1, N + 1) {
      scanf("%d", &a[i]);
      if(rk[a[i]] == 0) 
        rk[a[i]] = ind++;
    }
    build(1, N, 1);
    int ans=0;
    rep(i, 1, Q + 1){
      int l, r;
      scanf("%d%d", &l, &r);
      int tl = (l + ans) % N + 1;
      int tr = (r + ans) % N + 1;
      l = min(tl, tr), r=min(tl, tr);
      int sum=query(l, r, 1, N, 1).count();
      if(sum == 1){
        printf(" %d",l);
        ans=l;
        continue;
      }
      int tk = (sum + 1) >> 1;
      int bl = l - 1, br = r;
      while(br-bl>1)
      {
        int mid = (bl + br) >> 1;
        int tt=query(l, mid, 1, N, 1).count();
        if(tt < tk)
          bl=mid;
        else
          br=mid;
      }
    }
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

