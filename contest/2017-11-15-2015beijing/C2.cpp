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

const int MAXN = 200; 
const int MAXSTATE = pow(7, 6);

char sa[MAXN], sb[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int f[MAXSTATE];
int stateArray[10], newStateArray[10];
int res, n;
void calRes(int state) {
  int tmpRes = f[state];
  int x = state;
  for (int i = 6; i >= 1; i --) {
    stateArray[i] = x % 7;
    x /= 7;
  }
  for (int i = 0; i < n; i ++) {
    c[i] = stateArray[b[i]];
    if (c[i] != a[i])
      tmpRes ++;
  }
  res = min(res, tmpRes);
  return;
}
void work() {
  res = 0;
  for (int i = 0; i < n; i ++) {
    a[i] = sa[i] - '0';
    b[i] = sb[i] - '0';
    if (a[i] != b[i])
      res ++;
  }
  for (int i = 0; i < MAXSTATE; i ++) {
    if (f[i] != MAXN) {
      calRes(i);
    }
  }
  printf("%d\n", res);
}
void pre() {

  for (int i = 0; i < MAXSTATE; i ++)
    f[i] = MAXN;
  int state = 0;
  for (int i = 1; i <= 6; i ++) {
    state *= 7;
    state += i;
  }
  f[state] = 0;
  queue<int> q;
  q.push(state);
  while (!q.empty()) {
    int state = q.front();
    int x = state;
    q.pop();
    for (int i = 6; i >= 1; i --) {
      stateArray[i] = x % 7;
      x /= 7;
    }
    for (int i = 1; i <= 6; i ++) {
      for (int j = 1; j <= 6; j ++) {
        if (i != j) {
          int newState = 0;
          for (int k = 1; k <= 6; k ++) {
            if (stateArray[k] == i)
              newStateArray[k] = j;
            else
              newStateArray[k] = stateArray[k];
            newState *= 7;
            newState += newStateArray[k];
          }
          if (f[newState] == MAXN) {
            f[newState] = f[state] + 1;
            q.push(newState);
          }
        }
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  pre();
  while (scanf("%s", sa) != EOF) {
    scanf("%s", sb);
    n = strlen(sb);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}



