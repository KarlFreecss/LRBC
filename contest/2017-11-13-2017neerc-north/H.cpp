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

const int MAXN = 1e5 + 100;

int fa[MAXN], sonN[MAXN], num[MAXN], rootNum[MAXN];
vector<int> son[MAXN];
queue<int> qSon[MAXN];
int n;

void dfs(int x, int root) {
  if (num[x] == 1)
    qSon[root].push(x);
  for (int i = 0; i < son[x].size(); i ++) {
    int y = son[x][i];
    dfs(y, root);
  }
}

bool work() {
  int res = 0;
  if (scanf("%d", &n) != 1) return false;
  for (int i = 1; i <= n; i ++) {
    son[i].clear();
    sonN[i] = 0;
    num[i] = 1;
    while (!qSon[i].empty()) {
      qSon[i].pop();
    }
  }
  fa[1] = 0;
  for (int i = 2; i <= n; i ++) {
    scanf("%d", &fa[i]);
    if (fa[i] != 0) {
      son[fa[i]].push_back(i);
      sonN[fa[i]] ++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i ++) {
    if (sonN[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    int y = fa[x];
    if (y == 0)
      continue;
    sonN[y] --;
    if (sonN[y] == 0) {
      q.push(y);
    }
    if (num[x] == 1 && num[y] == 1) {
      num[x] --;
      num[y] --;
      res ++;
    }
  }
  for (int i = 2; i <= n; i ++) {
    if (num[i] == 0 && fa[i] == 0) {
      fa[i] = 1;
      son[1].push_back(i);
    }
  }
  for (int i = 1; i <= n; i ++) {
    if (fa[i] == 0) {
      dfs(i, i);
    }
  }
  for (int i = 2; i <= n; i ++) {
    if (fa[i] == 0 && qSon[i].size() >= 2) {
      if (qSon[1].empty()) {
        fa[i] = 1;
      } else {
        int x = qSon[1].front();
        qSon[1].pop();
        fa[i] = x;
        qSon[i].pop();
        res ++;
      }
      while (!qSon[i].empty()) {
        qSon[1].push(qSon[i].front());
        qSon[i].pop();
      }
    }
  }
  for (int i = 2; i <= n; i ++) {
    if (fa[i] == 0) {
      if (qSon[1].empty()) {
        fa[i] = 1;
      } else {
        int x = qSon[1].front();
        qSon[1].pop();
        fa[i] = x;
        qSon[i].pop();
        res ++;
      }
      while (!qSon[i].empty()) {
        qSon[1].push(qSon[i].front());
        qSon[i].pop();
      }
    }
  }
  printf("%d\n", res);
  for (int i = 2; i <= n; i ++) {
    printf("%d", fa[i]);
    if (i == n)
      printf("\n");
    else printf(" ");
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen(".in","r",stdin);
#endif
  freopen("hidden.in", "r", stdin);
  freopen("hidden.out", "w", stdout);
  while (work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

