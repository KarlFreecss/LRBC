#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 2000000+13;
const int Mod = 1e9 + 7;

int fail[maxN];
char s[maxN];
char s1[maxN], s2[maxN];
int T;
int c[maxN];

int main() {
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    int ans = 0 ;
    memset(c,0,sizeof(c));
    scanf("%s%s", s1,s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    for(int i = 1; i <= l2; i++) {
      s[i-1] = s2[l2-i];
    }
    int crt=fail[0]=-1;
    for(int i=1;i<=l2;i++)
    {
      while(crt>=0 && s[crt]!=s[i-1]) crt=fail[crt];
      fail[i]=++crt;
    }
    //for(int i = 1; i <= l2; i++) 
    //  cout << fail[i] << ' ';
    //cout << endl;
    for(int i=1; i<=l2; i++) {
      c[i] = i;
      c[i] = (c[i] + c[fail[i]]) % Mod;
    }
    //for(int i = 1; i <= l2; i++) 
    //  cout << c[i] << ' ';
    //cout << endl;
    for(int i=l1-1,j=0;i>=0;i--)
    {
      //cout << i << ":" << endl;
      while(j>=0 && s1[i]!=s[j]) j=fail[j];
      ++j;
      //cout << j << endl;
      ans = (ans + c[j]) % Mod;
      if(j==l2)
        j=fail[j];
    }
    printf("%d\n",ans);
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

