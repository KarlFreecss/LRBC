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

long long n, price, num, money;
long long p[10000];

int main() {
#ifndef ONLINE_JUDGE
//  freopen("D.in","r",stdin);
#endif
  scanf("%I64d", &n);
  price = 1000;
  num = 0;
  money = 100;
  for (int i = 0; i < n; i ++) {
    scanf("%I64d", &p[i]);
    if (p[i] < price) {
      money += price * num;
      num = money / p[i];
      if (num > 1e5)
        num = 1e5;
      price = p[i];
      money -= num * price;
    } else {
      price = p[i];
    }
  }
  money += price * num;
  printf("%I64d\n", money);
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

