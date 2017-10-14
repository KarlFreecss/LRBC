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

vector<int> num;

void work(){
  int n;
  scanf("%d", &n);
  num.resize(n + 1);
  for (int i = 0; i < num.size(); ++i) {
    num[i] = 0;
  }
  int flag = 1;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x >= 0 && x < n) {
      num[x]++;
      count++;
    }
  }
  if (count != n) {
    puts("invalid");
    return ;
  }
  int cur = 0;
  vector<char> ans;
  for (int i = 0; i < count; ++i) {
    if (num[cur+1] > 0) {
      ans.push_back('(');
      ++cur;
      num[cur]--;
    } else if (cur > 0 && num[cur-1] > 0) {
      ans.push_back(')');
      --cur;
      num[cur]--;
    } else {
      puts("invalid");
      return ;
    }
  }
  if (cur) {
    puts("invalid");
    return ;
  }
  for (int i = 0; i < ans.size(); ++i) {
    putchar(ans[i]);
  }
  putchar('\n');
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("E.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    printf("Case %d: ", i);
    work();
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

