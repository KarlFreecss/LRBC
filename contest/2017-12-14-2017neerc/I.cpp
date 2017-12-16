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

const int MAXN = 1e4 + 5;

int d[MAXN];
int o[MAXN], e[MAXN];

int work(){
  int n;
  if (scanf("%d", &n) != 1) return false;

  int confirm = 0;
  memset(d, 0, sizeof(d));
  memset(o, 0xff, sizeof(o));
  memset(e, 0xff, sizeof(e));
  vector<vector<int>> net(n+1);
  while (confirm < n) {
    vector<int> que;
    set<int> judge;
    for (int i = 1; i <= n/2; ++i) {
     // printf("d[%d] = %d, e[%d] = %d\n", i, d[i], i, e[i]);
      if (d[i] == 0 && e[i] == -1) {
        que.push_back(i);
      }
    }
    int lastStd = 0;
    int m = (n - 1) / 2 + 1;
    for (int i = 1; i <= m; ++i) {
      if (o[i] == -1) {
        judge.insert(i);
      }
    }
    if (judge.size() == 1) {
      for (auto x : judge) o[x] = ++confirm;
      continue; 
    }
    assert(que.size() > 0);
    for (int i = 0; i < (int)que.size(); ++i) {
      swap(que[i], que[rand() % que.size()]);
    }
    for (int i = 0; i < (int)que.size(); ++i) {
      vector<int> eraseList;
      for (auto x : judge) {
        printf("? %d %d\n", que[i], x);
        fflush(stdout);
        char c = getchar();
        while (c != '<' && c != '>') c = getchar();
        if (c == '<') eraseList.push_back(x);
      }
      if (eraseList.size() > 0) {
        net[que[i]].push_back(lastStd);
        ++d[lastStd];
        lastStd = que[i];
      } else {
        if (lastStd == 0) {
          lastStd = que[i];
        } else {
          ++d[que[i]];
          net[lastStd].push_back(que[i]);
        }
      }
      for (int i = 0; i < (int)eraseList.size(); ++i) {
        //cout << eraseList[i] << endl;
        judge.erase(eraseList[i]);
      }
      if (judge.size() == 1) {
        for (auto x : judge) {
          o[x] = ++confirm;
        }
        e[que[i]] = ++confirm;
        int v = que[i];
        for (int k = 0; k < (int)net[v].size(); ++k) {
          --d[net[v][k]];
        }
        break;
      }
    }
  }
  printf("! ");
  for (int i = 1; i <= n / 2; ++i) {
    printf("%d ", e[i]);
  }
  int m = (n - 1) / 2 + 1;
  for (int i = 1; i <= m; ++i) {
    printf("%d%c", o[i], i==m?'\n':' ');
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("I.in","r",stdin);
#endif
  work();
 // while (work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

