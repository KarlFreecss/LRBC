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

char sa[MAXN], sb[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int fa[10], son[10], faNum[10], cCount[10];
int n, res;
int tmpRes;

void calRes(emptyIndex) {
  fa[emptyIndex] = emptyIndex;
  faNum[emptyIndex] = 0;
  memset(son, 0, sizeof(son));
  son[emptyIndex] = 1;
  for (int i = 1; i <= 6; i ++) {
    if (i != emptyIndex) {
      memset(cCount, 0, sizeof(cCount));
      for (int j = 0; j < n; j ++)
        if (c[j] == i) {
          cCount[a[j]] ++;
        }
      fa[i] = i; faNum[i] = cCount[i];
      for (int j = 1; j <= 6; j ++) {
        if (cCount[j] > faNum[i]) {
          faNum[i] = cCount[j];
          fa[i] = j;
        }
      }
      son[fa[i]] ++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= 6; i ++) {
    if (son[i] == 0) {
      q.push(i);
    }
  }
}
void work() {
  res = 0;
  for (int i = 0; i < n; i ++) {
    a[i] = sa[i] - '0';
    b[i] = sb[i] - '0';
    if (a[i] != b[i])
      res ++;
  }
  for (int i = 1; i <= 6; i ++) {
    for (int j = 1; j <= 6; j ++) {
      if (i != j) {
        tmpRes = 1 + n;
        for (int k = 0; k < n; i ++) {
          if (b[k] == i)
            c[k] = j;
          else
            c[k] = b[k];
        }
        calRes(i);
        res = min(res, tmpRes);
      }
    }
  }
  printf("%d\n", res);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  while (scanf("%s", sa) != EOF) {
    cout << "============" << endl;
    scanf("%s", sb);
    n = strlen(sb);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


