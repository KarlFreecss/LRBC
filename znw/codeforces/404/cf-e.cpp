#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

const int maxN=200000+13;
const int maxNode=4*maxN;

typedef long long ll;
typedef unsigned long long ull;

#define oddr     (l+r | l!=r)
#define val      value_[oddr]
#define laz      lazy_[oddr]
#define num      num_[oddr]
#define m        ( l+r >>1 )
#define init_laz 0

typedef int Val;
struct SegmentTree
{
  Val value_[maxNode];
  int num_[maxNode];
  void build(int l,int r)
  {
    num = r-l+1;
    if(l==r){val = l; return ;}
    build(l,m); build(m+1,r);
    update(l,r);
  }
  void update(int l,int r)
  {
    val=max(get(l,m,l,r),get(m+1,r,l,r));
  }
  void set(int l,int r,int ql,int qr,int c)
  {
    if(l==r) {val = c; return ;}
    if(ql<=m) set(l,m,ql,qr,c);
    if(m <qr) set(m+1,r,ql,qr,c);
    update(l,r);
  }
  int get(int l,int r,int ql,int qr)
  {
    return val;
  }
  int get(int l,int r,int ql,int qr,int c)
  {
    cout<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<c<<endl;
    if(val < c) return (qr-ql+1);
    if(ql<=l && r<=qr && val<c) return num;
    if(l == r) return val<c;
    if(qr<=m) return get(l,m,ql,qr,c);
    if(m<ql)  return get(m+1,r,ql,qr,c);
    return get(l,m,ql,qr,c)+get(m+1,r,ql,qr,c);
  }
  Val &operator[](int x)
  {
    return value_[x+x];
  }
}T;

int N,Q;

int main()
{
  scanf("%d%d", &N, &Q);
  T.build(1,N);
  int ans = 0;
  rep(i,1,Q+1) {
    int l,r;
    scanf("%d%d",&l,&r);
    int tl = T[l], tr = T[r];
    if(l == r) {
      printf("%d\n",ans);
      continue;
    }
    if(l == r-1) {
      if(tl < tr) ans++;
      printf("%d\n",ans);
      T.set(1,N,l,l,tr);
      T.set(1,N,r,r,tl);
      continue;
    }
    cout<<"id= " << i <<endl;
    rep(j,1,1+N) { cout<<T[j] << ' ';}
    cout<<endl;
    if(l > r) swap(l,r);
    int tt = 0;
    cout<< l+1 <<' '<< r-1 << ' ' << tl << ' '<< T.get(1,N,l+1,r-1,tl) <<endl;
    cout<< l+1 <<' '<< r-1 << ' ' << tr << ' '<< T.get(1,N,l+1,r-1,tr) <<endl;
    tt -= T.get(1,N,l+1,r-1,tl);
    tt += (r-1-l)-T.get(1,N,l+1,r-1,tr);
    if(tl < tr) tt++;
    ans += tt;
    T.set(1,N,l,l,tr);
    T.set(1,N,r,r,tl);
    printf("%d\n",ans);
  }
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

