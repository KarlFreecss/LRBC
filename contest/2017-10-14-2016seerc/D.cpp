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

char buff[1024 * 1024];
char kstr[1024 * 1024];

const int co = 1024 * 1024;

int work(){
  char * ps = buff, * pt = kstr;
  int n, k;
  if (scanf("%d%d", &n, &k) != 2) return 0;
  gets(buff);
  gets(buff);
  int l = strlen(buff);
  for (int i = 0; i < n; ++i) {
    int index = 0;
    for (int j = 0; j < l; j += 2) {
      int repeat = ps[j] - '0';
      char c = ps[j+1];
      for (int k = 0; k < repeat; ++k) {
        pt[index++] = c;
      }
    }
    pt[index] = 0;
    l = index;
    swap(pt, ps);
  }
  putchar(ps[k]);
  putchar('\n');
 
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("D.in","r",stdin);
#endif
  while (work());
  // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

