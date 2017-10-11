
#include <bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
#define MODN 1000000007

long long powmod(int a,int b)
{
    long long res=1,temp=a;
    while(b)
    {
        if(b&1)
        {
            res*=temp;
            res%=MODN;
        }
        b>>=1;
        temp*=temp;
        temp%=MODN;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y,ym2x;
        int p,q,k;
        scanf("%d%d%d",&p,&q,&k);
        y=powmod(p,k);
        ym2x=powmod(p-2*q,k);
        x=y-ym2x+MODN;
        x%=MODN;
        x*=powmod(2,MODN-2);
        x%=MODN;
        x=y-x+MODN;
        x%=MODN;
        long long res=x;
        res*=powmod(y,MODN-2);
        res%=MODN;
        //cout<<x<<"\t"<<y<<"\t"<<ym2x<<endl;
        cout<<res<<endl;
    }
    return 0;
}

