#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)
#define red(i,k,n) for(int i=(k);i>=(n);i--)
#define sqr(x) ((x)*(x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define pb push_back
#define mod 1000000007
const int maxn=400010;
int n,m,dp[maxn][2],f[maxn],g[maxn];
pair<int,int> h[maxn];
vector<int> e[maxn];
struct node
{
    int x,y,z;
    inline void read()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
    bool operator < (const node &a) const
    {
        return y==a.y?x<a.x:y<a.y;
    }
}qry[maxn];

void dfs(int x)
{
    for(int i=0;i<e[x].size();i++)
    {
        int v=e[x][i];
        dfs(v);
        dp[x][0]+=max(dp[v][0],dp[v][1]);
        dp[x][1]+=dp[v][1];
    }
}

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        rep(i,1,n-1){scanf("%d",&h[i].first);h[i].second=i;}
        rep(i,1,m)qry[i].read();
        printf("Case #%d: ",++cas);
        sort(qry+1,qry+1+m);
        sort(h+1,h+n);
        rep(i,1,n)
        {
            f[i]=g[i]=i;
            e[i].clear();
            dp[i][0]=dp[i][1]=0;
        }
        int cntn=1,cntm=1,now=n;
        qry[0].y=-1;
        while(cntn<n||cntm<=m)
        {
            if(cntm>m||(cntn<n&&h[cntn].first<=qry[cntm].y))
            {
                e[++now].clear();dp[now][0]=dp[now][1]=0;
                int pos=h[cntn].second;
                e[now].pb(g[getf(pos)]);
                e[now].pb(g[getf(pos+1)]);
                f[getf(pos)]=getf(pos+1);
                g[getf(pos)]=now;
                cntn++;
            }
            else
            {
                int tmp=g[getf(qry[cntm].x)];
                if(qry[cntm].y==qry[cntm-1].y&&tmp==g[getf(qry[cntm-1].x)])
                {
                    dp[tmp][qry[cntm].z]++;

                }
                else
                {
                    e[++now].clear();dp[now][0]=dp[now][1]=0;
                    e[now].pb(g[getf(qry[cntm].x)]);
                    g[getf(qry[cntm].x)]=now;
                    dp[now][qry[cntm].z]++;
                }
                cntm++;
            }
        }
        dfs(now);
        printf("%d\n",max(dp[now][0],dp[now][1]));
    }

    return 0;
}
