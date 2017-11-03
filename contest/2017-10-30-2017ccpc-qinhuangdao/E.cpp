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

const int MAXN = 2e5 + 10;

char s[MAXN];
int n;

bool check(int x, int mid, int y) {
  if (x < 0) x = 0;
  if (y >= n) y = n - 1;
  int count0 = 0, count1 = 0, count2 = 0;
  for (int i = x; i <= y - 3; i ++) {
      if (s[i] == 'C' && s[i+1] == 'C' && s[i+2] == 'P' && s[i+3] == 'C') {
        count0 ++;
      }
  }
  string tmpS = "";
  int len;
  for (int i = x; i < mid; i ++)
    tmpS += s[i];
  tmpS += 'C';
  for (int i = mid; i <= y; i ++)
    tmpS += s[i];
  len = tmpS.size();
  for (int i = 0; i < len - 3; i ++) {
      if (tmpS[i] == 'C' && tmpS[i+1] == 'C' && tmpS[i+2] == 'P' && tmpS[i+3] == 'C') {
        count1 ++;
      }
  }
  tmpS = "";
  for (int i = x; i < mid; i ++)
    tmpS += s[i];
  tmpS += 'P';
  for (int i = mid; i <= y; i ++)
    tmpS += s[i];
  len = tmpS.size();
  for (int i = 0; i < len - 3; i ++) {
      if (tmpS[i] == 'C' && tmpS[i+1] == 'C' && tmpS[i+2] == 'P' && tmpS[i+3] == 'C') {
        count2 ++;
      }
  }
  if (count0 + 1 == count1 || count0 + 1 == count2) {
    return true;
  }
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("E.in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T --) {
    scanf("%d", &n);
    scanf("%s", s);
    int res = 0;
    for (int i = 0; i < n - 3; i ++) {
      if (s[i] == 'C' && s[i+1] == 'C' && s[i+2] == 'P' && s[i+3] == 'C') {
        res ++;
      }
    }
    for (int i = 0; i <= n; i ++) {
      if (check(i - 4, i, i + 3)) {
        res ++;
        break;
      }
    }
    printf("%d\n", res);
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

