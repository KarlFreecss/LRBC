#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100010;

const int BI_n=14;
const int clw = 1e8;
struct BigInt
{
  private:
    int a[BI_n];
    mutable int n;
    inline void trunc()const{for(--n;n>=0 && !a[n];--n);++n;}
    void carry(int start=0)
    {
      int i; int tmp=0;
      for(i=start;i<n || tmp;++i)
      {
        tmp+=a[i]; a[i]=tmp%clw; tmp/=clw;
      }
      if(i>=n) n=i;
    }
  public:
    BigInt(){
      return ;
    }
    BigInt(int x)
    {
      memset(a, 0, sizeof(a));
      for(n=0;x;++n) a[n]=x%clw, x/=clw;
    }
    void output()
    {
      if(n == 0) {
        printf("%d\n",0);
        return ;
      }
      printf("%d",a[n-1]);
      for(int i=n-2;i>=0;--i) printf("%08d",a[i]);
      printf("\n");
      return ;
    }
    friend BigInt operator+(const BigInt& x, const BigInt& y)
    {
      BigInt ret;
      ret.n=max(x.n, y.n)+1;
      int tmp=0;
      for(int i=0;i<ret.n;++i)
      {
        if(i<x.n) tmp+=x.a[i];
        if(i<y.n) tmp+=y.a[i];
        //ret.a[i]=tmp;
        //if(ret.a[i] > clw) ret.a[i] -= clw;
        //tmp /= clw;
        ret.a[i]=tmp%clw;  tmp/=clw;
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
    for (int j = 0; j < 26; ++j) {
      f[i][j] = zero;
      g[j] = f[i-1][j];
      if (j > 0) {
        g[j] =g[j] + g[j-1];
      }
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

