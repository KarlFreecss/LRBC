#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back
#define fi first 
#define se second 
#define mk(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int MAXN = 1010;

int count1[200][2];
char s[MAXN];
long long res;

int main() {
  freopen("boolean.in","r",stdin);
  freopen("boolean.out","w",stdout);
  memset(count1, 0, sizeof(count1));
  res = 1;
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i ++) {
    int tmp = s[i] - 'A';
    if ('a' <= s[i] && s[i] <= 'z') {
      if (i != 0 && s[i - 1] == '~')
        count1[tmp][1] = 1;
      else
        count1[tmp][0] = 1;
    } else if ('A' <= s[i] && s[i] <= 'Z') {
      if (i != 0 && s[i - 1] == '~')
        count1[tmp][1] = 1;
      else
        count1[tmp][0] = 1;      
    }
  }
  for (int i = 0; i < 200; i ++) {
    if (count1[i][0] == 1 || count1[i][1] == 1) {
      res *= 2;
      char c = 'A' + i;
//      cout << c << endl;
    }
  }
  int i;
  for (i = 0; i < 200; i ++) {
    if (count1[i][0] == 1 && count1[i][1] == 1) {
      break;
    }
  }
  if (i >= 200)
    res --;
  printf("%I64d\n", res);


//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

