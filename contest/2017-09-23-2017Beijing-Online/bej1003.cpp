#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 400+13;

int ma[maxN][maxN];
int dp[maxN][maxN][10][10];
int n,m,p;
int f[maxN][maxN][maxN];
template<class T>void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
int p2[maxN];
void init_rmq()
{
  for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
      dp[i][j][0][0]=ma[i][j];

  for(int i=0;(1<<i)<=n;i++) {
    for(int j=0;(1<<j)<=m;j++) {
      if(i==0 && j==0)
        continue;
      for(int row=1;row+(1<<i)-1<=n;row++) {
        for(int col=1;col+(1<<j)-1<=m;col++) {
          if(i==0) 
            dp[row][col][i][j] =
              min(dp[row][col][i][j-1],dp[row][col+(1<<(j-1))][i][j-1]);
          else
            dp[row][col][i][j] =
              min(dp[row][col][i-1][j],dp[row+(1<<(i-1))][col][i-1][j]);
        }
      }
    }
  }
  return ;
}

void init_rmq2()
{
  p2[0] = 1;
  for(int i=1;i<=20;i++) p2[i] = p2[i-1] << 1;
  for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
      dp[i][j][0][0]=ma[i][j];

  for(int i=0;p2[i]<=n;i++) {
    for(int j=0;p2[j]<=m;j++) {
      if(i==0 && j==0)
        continue;
      for(int row=1;row+p2[i]-1<=n;row++) {
        for(int col=1;col+p2[j]-1<=m;col++) {
          if(i==0) 
            dp[row][col][i][j] =
              min(dp[row][col][i][j-1],dp[row][col+p2[j-1]][i][j-1]);
          else
            dp[row][col][i][j] =
              min(dp[row][col][i-1][j],dp[row+p2[i-1]][col][i-1][j]);
        }
      }
    }
  }
  return ;
}

int lx[maxN];

int query(int x1,int y1,int x2,int y2) {
  //int kx=log(double(x2-x1+1))/log(2.0);
  //int ky=log(double(y2-y1+1))/log(2.0);
  int kx = lx[x2-x1+1];
  int ky = lx[y2-y1+1];
  int m1=dp[x1][y1][kx][ky];
  int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
  int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
  int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
  return min( min(m1,m2), min(m3,m4) );
}

int ms[maxN][maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("bej1003.in","r",stdin);
#endif
  for(int i = 0; i < maxN; i++) {
    lx[i] = log((double)i)/log(2.0);
  }
  while(scanf("%d%d%d", &n, &m, &p) != EOF) {
    //cout << n << m << p << endl;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        scanf("%d",&ma[i][j]);
        //cout << ma[i][j] << endl;
        ms[i][j] = ms[i][j-1] + ma[i][j];
      }
    init_rmq();
    //cout << "ok" << endl;
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += ms[i][m];
    //cout << query(1,1,n,m);
    ans = ans - query(1,1,n,m) + p;
   // cout << ans << endl;
    for(int i = 1; i <= m; i++) {
      for(int j = i; j <= m; j++) {
        int ts = 0,ta = 0;
        int tk = 1;
        for(int k = 1; k <= n; k++) {
          //cout << i << ' ' << j << ' ' << k << endl;
          if(ts < 0 && ta < 0){ ts = ta = 0;;tk=k;}
          ts += ms[k][j] - ms[k][i-1];
          int tt = query(tk,i,k,j);
          ta = ts - tt + p;
          ans = max(ta, ans);
          if(i == 1 && j == m && tk == 1 && k == n) continue;
          ans = max(ts, ans);
        }
      }
    }
    printf("%d\n",ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}
