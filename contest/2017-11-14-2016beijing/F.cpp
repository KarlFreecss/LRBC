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

struct NODE{
  char c;
  int num;

  bool operator < (const NODE & T) const {
    if (num != T.num) return num > T.num;
    return c < T.c;
  }
};

int work(){
  int n, m;
  scanf("%d%d", &n, &m);
  if ((n | m) == 0) return false;
 // cout << n << ' ' << m << endl;
  map<char, int> dic;
  for (int i = 0; i < n; ++i) {
    char buff[256];
    scanf("%s", buff);
    for (int j = 0; j < m; ++j) {
      dic[buff[j]]++;
    }
  }

  vector<NODE> v;
  for (auto x : dic) {
    v.push_back((NODE){x.first, x.second});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    if (i != 0) cout << ' '; 
    if (v[i].num) cout << v[i].c << ' ' << v[i].num;
  }
  cout << endl;

  return true;
}

int main() {
#ifndef ONLINE_JUDGE
 // freopen("F.in","r",stdin);
#endif

  while(work());

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

