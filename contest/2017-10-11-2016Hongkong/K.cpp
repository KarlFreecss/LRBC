#include <bits/stdc++.h>

using namespace std;

#define debug() cout << __LINE__ << ' ' 

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

int n, m, p;

vector<vector<int>> S;
vector<vector<int>> num;
vector<set<int>> exist;
vector<bool> used;
queue<int> waiting;
vector<vector<int>> ans;
vector<int> empty;

void work(){
  ans.clear();
  set<int> curr;
  int count = 0;
  //debug() << endl;
  while (1) {
    while (!waiting.empty()){
      int t = waiting.front();
      waiting.pop();
    //  debug() << "t = " << t << endl;
      if (used[t]) continue;
     // debug() << "t = " << t << endl;
      if (exist[t].size() == 0) return;
      int mark = 0;
      int index = 0;
     // debug() << "mark = " << mark << endl;
      for (auto x : exist[t]) {
       // debug() << "x = " << x << " " << " t = " << t << endl;
       // debug() << "S[x] = " << S[x].size() << endl;
        if (S[x].size() > mark) {
          mark = S[x].size();
          index = x;
        }
      }
   //   debug() << "mark = " << mark << endl;
    //  debug() << "index = " << index << endl;
      curr.insert(index);
      for (int i = 0; i < S[index].size(); ++i) {
        used[S[index][i]] = 1;
      }
    }
   // debug() << endl;

    ++count;
    ans.push_back(empty);
    vector<int> tmpDel;
    for (auto x : curr) {
     // debug() << x << ' ' << num[x].back() << endl;
      ans.back().push_back(num[x].back());
      num[x].pop_back();
      if (num[x].size() == 0) {
        for (int i = 0; i < S[x].size(); ++i) {
          int skillIndex = S[x][i];
          //debug() << "skill " << skillIndex << endl;
          //debug() << "x = " << x << endl;
          exist[skillIndex].erase(x);
          waiting.push(skillIndex);
          used[skillIndex] = false;
        }
        tmpDel.push_back(x);
      }
    }
    for (auto x : tmpDel) {
      curr.erase(x);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("K.in","r",stdin);
#endif

  scanf("%d%d%d", &n, &m, &p);
  //debug()<<endl;
  S.resize(m);
  exist.resize(n);
  used.resize(n, false);
  num.resize(m);
  //debug()<<endl;
  for (int i = 0; i < m; ++i){
    int t;
    scanf("%d", &t);
    //debug() << i << endl;
    for (int j = 0; j < t; ++j) {
      int s;
      scanf("%d", &s);
      --s;
      exist[s].insert(i);
      S[i].push_back(s);
    }
  }
  //debug()<<endl;
  for (int i = 0; i < p; ++i) {
    int t;
    scanf("%d", &t);
    num[t-1].push_back(i);
    //cout << t-1 << ' ' << num[t-1].back() << endl;
  }
  //debug()<<endl;
  for (int i = 0; i < m; ++i) {
    if (num[i].size()) continue;
    for (int k = 0; k < S[i].size(); ++k) {
      exist[S[i][k]].erase(i);
    }
  }
  //debug()<<endl;
  for (int i = 0; i < n; ++i) {
    waiting.push(i);
  }
  work();
  int ansNum = ans.size();
  cout << ansNum << endl;
  for (int i = 0; i < ansNum; ++i) {
    int numm = ans[i].size();
    printf("%d ", numm);
    for (int j = 0; j < ans[i].size(); ++j) {
      int t = ans[i][j] + 1;
      printf("%d%c", t, j+1==ans[i].size()?'\n':' ');
    }
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

