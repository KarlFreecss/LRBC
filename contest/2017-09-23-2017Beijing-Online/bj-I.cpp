#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const ll MY_MIN = 99999999;
const ll MY_MAX = -99999999;

inline ll iabs(ll a) {
  if(a < 0) return -a;
  return a;
}
struct CNode
{
  int L,R;
  ll nMin,nMax,absMin;
  CNode * pLeft, * pRight;
};
ll nMax, nMin,absMin;
CNode Tree[1000000];
int nCount = 0;
void BuildTree(CNode * pRoot, int L,int R)
{
  pRoot->L = L;
  pRoot->R = R;

  pRoot->nMin = MY_MIN;
  pRoot->nMax = MY_MAX;
  pRoot->absMin = MY_MIN;

  if ( L != R) {
    nCount ++;
    pRoot->pLeft = Tree + nCount;
    nCount ++;
    pRoot->pRight = Tree + nCount;
    BuildTree( pRoot->pLeft, L, ( L + R )/2);
    BuildTree( pRoot->pRight, (L + R) / 2 + 1,R);
  }
}
void Insert( CNode * pRoot , int i,ll v)
{
  if( pRoot->L == i &&  pRoot->R == i ) {
    pRoot->nMin = pRoot->nMax = v;
    pRoot->absMin = iabs(v);
    return;
  }
  pRoot->nMin =  min(pRoot->nMin,v);
  pRoot->nMax =  max(pRoot->nMax,v);
  pRoot->absMin =  min(pRoot->absMin,iabs(v));
  if( i <= (pRoot->L + pRoot->R )/2 )
    Insert( pRoot->pLeft,i,v);
  else
    Insert( pRoot->pRight,i,v);
}
void Update( CNode * pRoot , int i,ll v)
{
  if( pRoot->L == i &&  pRoot->R == i ) {
    pRoot->nMin = pRoot->nMax = v;
    pRoot->absMin = iabs(v);
    return;
  }
  if( i <= (pRoot->L + pRoot->R )/2 )
    Update( pRoot->pLeft,i,v);
  else
    Update( pRoot->pRight,i,v);
  pRoot->nMin =  min(pRoot->pLeft->nMin,pRoot->pRight->nMin);
  pRoot->nMax=   max(pRoot->pLeft->nMax,pRoot->pRight->nMax);
  pRoot->absMin= min(pRoot->pLeft->absMin,pRoot->pRight->absMin);
}

void Query(CNode * pRoot, int s, int e)
{
  if( pRoot->nMin >= nMin && pRoot->nMax <= nMax && pRoot->absMin >= absMin )
    return;
  if( s == pRoot->L && e == pRoot->R) {
    nMin =  min(pRoot->nMin,nMin);
    nMax =  max(pRoot->nMax,nMax);
    absMin =  min(pRoot->absMin,absMin);
    return ;
  }
  if( e <=  (pRoot->L + pRoot->R) / 2 )
    Query(pRoot->pLeft, s,e);
  else if( s >= (pRoot->L + pRoot->R) / 2 + 1)
    Query(pRoot->pRight, s,e);
  else {
    Query(pRoot->pLeft, s,(pRoot->L + pRoot->R) / 2);
    Query(pRoot->pRight, (pRoot->L + pRoot->R) / 2 + 1 ,e);
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("bj-i.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  rep(cas, 1 , T+1) {
    int n,q;
    int i,j,k;
    scanf("%d",&n);
    int N = 1<<n;
    //cout << N << endl;
    nCount = 0;
    BuildTree(Tree,1,N);    
    for( i = 1;i <= N;i ++ ) {
      int h;
      scanf("%d",&h);
    //  cout << h << ' ';
      Insert(Tree,i,h);
    }
    //cout << endl;
    scanf("%d", &q);
    //cout << q<< endl;
    for( i = 0;i < q;i ++ ) {
      int s,e,c;
      scanf("%d%d%d",&c, &s,&e);
      //cout << c << ' ' << s << ' ' << e << endl;
      if(c == 1) {
        s++, e++;
        nMax = MY_MAX;
        nMin = MY_MIN;
        absMin = MY_MIN;
        Query(Tree,s,e);
        ll ans = 1ll<<36;
        //cout << s <<' ' << e << ':'<< endl;
        //cout << nMin <<' ' << nMax  << ' '<< absMin << endl;
        //cout << ans << endl;
        ans = nMin * nMax;
        ans = min(ans, absMin * absMin);
        printf("%lld\n", ans);
      } else {
        s++;
        Update(Tree,s,e);
      }
    }
  }
  return 0;
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
}
