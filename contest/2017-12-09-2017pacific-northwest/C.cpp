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

__int128 calu2(const __int128 a){
  __int128 sum = 0;
  for (__int128 i = 1; i * i <= a; ++i) {
    __int128 y = a / i;
    if (i <= y)
      sum += i * (y - i + 1);
    if (i + 1 <= y)
      sum += (y + i + 1) * (y - i) / 2;
  }
 // cout << (long long)sum << endl;
  return sum;
}

__int128 calu(const __int128 a){
  __int128 sum = 0;
  for (__int128 k = 1; k * k <= a; ++k) {
  //  if (k > 3) break;
    __int128 num = a / k;
   // __int128 num2 = (num - k);
  //  cout << (long long) num << ' ' << (long long) num2 << endl;
    sum += num * k + num * (num + 1) / 2 * k;
    sum -= (k + 1) * k / 2 * k;
  }
  //cout << "#debug " << (long long)sum << endl;
  return sum;
}

int work(){
  long long a, b;
  if (scanf("%lld%lld", &a, &b) != 2) return false;
  
  __int128 sumLow = calu2(a-1);
  __int128 sumHigh = calu2(b);

  printf("%lld\n", (long long)(sumHigh - sumLow));

  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  while (work());

  return 0;
}

