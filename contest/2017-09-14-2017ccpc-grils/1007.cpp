#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

vector<int> a;

void party_always_exist(){
  int n;
  a.clear();
  scanf("%d", &n);
  for (int i = 1; i < n; ++i){
    int t;
    scanf("%d", &t);
    a.push_back(t);
  }
  if (n % 2) {
    puts("No");
    return;
  }
  int one = a[n-2]==1;
  if (!one) {
    puts("No");
    return ;
  }
  for (int i = n-2; i > 0; --i) {
    if (a[i] == 1) ++one;
    else --one;
    if (one < 0) {
      puts("No");
      return;
    }
  }
  if (one < 0) {
    puts("No");
  } else {
    puts("Yes");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    party_always_exist();
  }

  return 0;
}

