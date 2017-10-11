#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100010;

const int BI_n=10;
const ll clw = 1e15;
struct BigInt
{
  private:
    ll a[BI_n];
    mutable int n;
    inline void trunc()const{for(--n;n>=0 && !a[n];--n);++n;}
    void carry(int start=0)
    {
      int i; ll tmp=0;
      for(i=start;i<n || tmp;++i)
      {
        tmp+=a[i]; a[i]=tmp%clw; tmp/=clw;
      }
      if(i>=n) n=i;
    }
  public:
    BigInt(int x=0)
    {
      memset(a, 0, sizeof(a));
      for(n=0;x;++n) a[n]=x%clw, x/=clw;
    }
    void output()
    {
      if(n == 0) {
        printf("%lld\n",0);
        return ;
      }
      printf("%lld",a[n-1]);
      for(int i=n-2;i>=0;--i) printf("%015lld",a[i]);
      printf("\n");
      return ;
    }

inline
    friend BigInt operator+(const BigInt& x, const BigInt& y)
    {
      BigInt ret;
      ret.n=max(x.n, y.n)+1;
      ll tmp=0;
      for(int i=0;i<ret.n;++i)
      {
        tmp+=x.a[i];
        tmp+=y.a[i];
        ret.a[i]=tmp%clw;  tmp/=clw;
        //if (tmp >= clw) {
	//		ret.a[i] = tmp - clw;
	//	tmp = 1;
	//}
      }
      ret.trunc();
      return ret;
    }
};

int a[MAXN];
int ranky[MAXN];
BigInt f[MAXN][26];
BigInt g[26];
int n;
BigInt one(1), zero(0);

void work(){
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    //scanf("%d", &a[i]);
    a[i] = i + 1;
    ranky[a[i]] = i + 1;
  }
  ranky[n+1] = 0;
  for (int i = 0; i < 26; ++i) {
    f[0][i] = one;
  }
  for (int i = 1; i < n; ++i) {
      f[i][0] = zero;
	g[0] = f[i-1][0];
    for (int j = 1; j < 26; ++j) {
      g[j] = f[i-1][j] + g[j-1];
    }
    if (ranky[a[i]+1] > ranky[a[i-1]+1]) {
      for (int j = 0; j < 26; ++j) {
        f[i][j] = g[j];
      }
    } else {
      for (int j = 1; j < 26; ++j) {
        f[i][j] = g[j-1];
      }
    }
  }
  BigInt tot = zero;
  for (int i = 0; i < 26; ++i) {
    tot = tot + f[n-1][i];
  }
  tot.output();
  return ;
}

int main(){
  freopen("bej1002.in","r",stdin);
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

