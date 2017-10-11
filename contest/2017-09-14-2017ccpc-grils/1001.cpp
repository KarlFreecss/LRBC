#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

void fuck(int id){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> wrT;
  vector<int> acT;
  set<int> S;
  for (int i = 0; i <= n; ++i){
    wrT.push_back(0);
    acT.push_back(-1);
  }
  for (int i = 0; i < m; ++i) {
    int id, hour, minu;
    char res[256];
    scanf("%d%d:%d%s", &id, &hour, &minu, res);
    id -= 1000;
    if (S.find(id) != S.end()) continue;
    if (string(res) == string("AC")) {
      S.insert(id);
      acT[id] = hour * 60 + minu;
    } else {
      wrT[id] += 20;
    }
  }
  int totT = 0;
  for (int i = 1; i <= n; ++i) {
    totT += wrT[i];
    if (acT[i] > 0) totT += acT[i];
  }
  cout << S.size() << ' ' << totT << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("a.in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i){
    fuck(i);
  }
  

  return 0;
}

