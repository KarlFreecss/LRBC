#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 100;
char a[MAXN * 3];
int n;

void vers(int pos) {
  if (a[pos] == '0')
    a[pos] = '1';
  else
    a[pos] = '0';
  pos ++;
  if (a[pos] == '0')
    a[pos] = '1';
  else
    a[pos] = '0';
  return;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("K.in","r",stdin);
#endif
  while(cin >> (a + 1) ) {
    a[0] = '2';
    n = (strlen(a) - 1);
    int m = n / 3 * 2;
    int count = 0;
    for (int i = 1; i <= n; i ++) {
      if (a[i] != a[i - 1])
        count ++;
    }
    if (count >= m) {
      printf("0\n\n");
      continue;
    }
    vector<int> res;
    res.clear();
    for (int i = 0; i < n; i += 3) {
      if (a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
        res.push_back(i + 2);
        vers(i + 2);
      } else if (a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] != a[i + 3]) {
        res.push_back(i + 3);
        vers(i + 3);
      } else if (a[i] == a[i + 1] && a[i] != a[i + 2] && a[i] == a[i + 3]) {

      } else if (a[i] == a[i + 1] && a[i] != a[i + 2] && a[i] != a[i + 3]) {
        res.push_back(i + 2);
        vers(i + 2);
      } else if (a[i] != a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {

      } else if (a[i] != a[i + 1] && a[i] == a[i + 2] && a[i] != a[i + 3]) {

      } else if (a[i] != a[i + 1] && a[i] != a[i + 2] && a[i] == a[i + 3]) {

      } else if (a[i] != a[i + 1] && a[i] != a[i + 2] && a[i] != a[i + 3]) {
        res.push_back(i + 3);
        vers(i + 3);
      } 
    }
    printf("%d\n", res.size());
    if (res.size() != 0)
      printf("%d", res[0]);
    for (int i = 1; i < res.size(); i ++) {
      printf(" %d", res[i]);
    }
    if (res.size() != 0)
      printf("\n");
  }

  

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

