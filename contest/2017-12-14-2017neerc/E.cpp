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

int work(){
  int n;
  if (scanf("%d", &n) != 1) return false;
  map<int, int> items;
  vector<int> a, ans;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  int flag = true;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] < 0) {
      if (items[-a[i]] > 0) {
        --items[-a[i]];
        continue;
      } else {
        if (items[0] > 0) {
          --items[0];
          ans.push_back(-a[i]);
        } else {
          flag = false;
          break;
        }
      }
    } else ++items[a[i]];
  }
  if (flag) {
    puts("Yes");
    while (items[0] > 0) {
      ans.push_back(1);
      --items[0];
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
      printf("%d%c", ans[i], i+1==(int)ans.size()?'\n':' ');
    }
  } else {
    puts("No");
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  
  while(work());

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

