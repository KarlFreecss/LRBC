#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 13;
const int p[12] = {0,1,5,10,20,50,100,200,500,1000,2000};
int T,P;
int c[maxN],used[maxN];

void deal(int i) {
  if(i == 5) {
    int change = (c[3] - used[3])/5;
    change = min(change,used[5]);
    used[3] += 5*change;
    used[5] -= change;
    change = min((c[3]-used[3])/3,(c[4]-used[4]));
    change = min(change,used[5]);
    used[3] += 3*change;
    used[4] += change ;
    used[5] -= change ;
    change = min((c[3]-used[3]),(c[4]-used[4])/2);
    change = min(change,used[5]);
    used[3] += change;
    used[4] += 2*change ;
    used[5] -= change ;
    return ;
  }
  if(i == 8) {
    int change = (c[6] - used[6])/5;
    change = min(change,used[8]);
    used[6] += 5*change;
    used[8] -= change;
    change = min((c[6]-used[6])/3,(c[7]-used[7]));
    change = min(change,used[8]);
    used[6] += 3*change;
    used[7] += change ;
    used[8] -= change ;
    change = min((c[6]-used[6]),(c[7]-used[7])/2);
    change = min(change,used[8]);
    used[6] += change;
    used[7] += 2*change ;
    used[8] -= change ;
    return ;
  }
  int tt = p[i] / p[i-1];
  if(c[i-1] - used[i-1] >= tt) {
    int change = (c[i-1] - used[i-1]) /tt;
    change = min(change , used[i]);
    used[i] -= change;
    used[i-1] += tt*change;
  }
  return ;
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("A.in","r",stdin);
#endif
  scanf("%d", &T);
  rep(cas, 0, T) {
    scanf("%d", &P);
    ll sum = 0;
    rep(i, 1, 11){
      scanf("%d", &c[i]);
      sum += c[i] * p[i];
    }
    if(sum < P) {
      printf("-1\n");
      continue;
    }
    bool ok = false;
    for(int s20 = 0;s20 <=4; s20++) {
      if(ok) break;
      if(s20 > c[4]) break;
      for(int s200 = 0; s200 <= 4; s200++) {
        if(ok) break;
        if(s200 > c[7])break;
        int tp = P-20*s20-200*s200;
        int tc[maxN];
        for(int i = 1; i <= 10; i++) tc[i] = c[i];
        for(int i = 1; i <= 10; i++) used[i] = 0;
        used[4] = s20;
        used[7] = s200;
        tc[4] -= s20;
        tc[6]+=tc[4]/5;
        tc[7] -= s200;
        tc[9]+=tc[7]/5;
        for(int i = 10;i >= 1; i--) if(i!=4 && i!=7) {
          if(tp > tc[i]*p[i]) {
            used[i] = tc[i];
            tp -= tc[i]*p[i];
          } else {
            int tt = tp/p[i];
            used[i] = tt;
            tp -= tt*p[i];
          }
        }
        if(tp == 0) {
          ok =true;
        }
      }
    }
    if(!ok) {
      printf("-1\n");
      continue;
    }
    if(used[6] > c[6]) {
      int tt = used[6] - c[6];
      used[4] += tt*5;
      used[6] = c[6];
    }
    if(used[9] > c[9]) {
      int tt = used[9] - c[9];
      used[7] += tt*5;
      used[9] = c[9];
    }
    for(int i = 2; i <= 10; i++) {
      for(int j = i; j>= 2; j--) deal(j);
    }
    int ans = 0;
    for(int i = 1; i <= 10; i++) 
      ans += used[i];
    printf("%d\n", ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

