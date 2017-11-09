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

char s[MAXN], str[MAXN];
int n;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("D.in","r",stdin);
#endif

  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i ++) {
    str[i] = s[i];
  }
  str[n] = s[n];
  sort(str, str + n);
  for (int i = 0; i < n; i ++) {
//    cout << s << endl;
//    cout << str << endl;
    if (str[i] != s[i]) {
      for (int j = i + 1; j < n; j ++) {
        if (str[j] == s[i]) {
          if (str[j] > str[i]) {
            printf("%d %d\n", j + 1, i + 1);
          } else {
            printf("%d %d\n", i + 1, j + 1);
          }
          swap(str[i], str[j]);
          break;
        }
      }
    }
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

