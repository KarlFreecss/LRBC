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

const int MAXN = 1e6 + 100;
const int MAXVAL = 6e5;

int f[MAXN];
int n;

int nextInt() {
  int ret = 0;
  char tc = getchar();
  while(tc < '0' || tc > '9') tc = getchar();
  while('0' <= tc && tc <= '9') {
    ret = ret*10 + tc -'0';
    tc = getchar();
  }
  return ret;
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("G.in","r",stdin);
//  freopen("G.out", "w", stdout);
#endif
  int count = 0;
  int val;
  memset(f, 0, sizeof(f));
  scanf("%d", &n);
  int maxVal = 0;
  int minVal = 0;
  for (int i = 0; i < n; i ++) {
//    count ++;
//    if (count > 1e8)
//      return 0;
    //scanf("%d", &val);
    val = nextInt();
    if (val > MAXVAL)
      val = MAXVAL;
    maxVal = max(maxVal, val);
    int flag = 1;
    int j = val;
    while (flag != 0 && j > minVal) {
//      count ++;
//      if (count > 1e8)
//        return 0;
      flag += f[j];
      //flag /= 2;
      flag >>= 1;
      j --;
    }
    if (j <= minVal && flag == 1) {
      minVal = max(val, minVal);
      if (val == maxVal) {
        printf("Yes\n");
        for (int k = i + 1; k < n; k ++) {
          //scanf("%d", &val);
          val = nextInt();
//          printf("No\n");
          puts("No");
        }
        break;
      } else {
//        printf("No\n");
        puts("No");
      }
    } else {
//      printf("Yes\n");
      puts("Yes");
      j = val;
      f[j] ++;
      while (f[j] > 1 && j > 0) {
//        count ++;
//        if (count > 1e8)
//          return 0;
        //f[j - 1] += f[j] / 2;
        f[j - 1] += f[j] >> 1;
        //f[j] %= 2;
        f[j] &= 1;
        j --;
        if (f[maxVal] == 0)
          maxVal --;
      }
    }
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

