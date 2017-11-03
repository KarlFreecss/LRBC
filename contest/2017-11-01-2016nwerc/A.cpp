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

vector<pair<int, int>> v;

int work(){
  int n, m;
  if (scanf("%d%d", &n, &m) != 2) return 0;
  priority_queue<int> used, unlock;
  int ans = 0;
  v.clear();
  for (int i = 0; i < n; ++i){
    int a, s;
    scanf("%d%d", &a, &s);
    v.push_back(make_pair(a, s));
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i){
    int a, s;
    //scanf("%d%d", &a, &s);
    a = v[i].first;
    s = v[i].second;
    while (!used.empty()){
      if (-used.top() > a) break;
      unlock.push(-(-used.top()+m));
      used.pop();
    }
    while (!unlock.empty()) {
      if (-unlock.top() >= a) break;
      unlock.pop();
    }
    if (!unlock.empty()) {
      ans++;
      unlock.pop();
    }
    used.push(-(a + s));
  }
  cout << ans << endl;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen("a.in","r",stdin);
#endif

  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

