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

const int maxN = 300000 + 13;
const int maxM = 1000000 + 13;
const int inf = 0x3f;

struct fuck {
  int val, num;
  friend bool operator < (const fuck& a, const fuck& b) {
    if(a.num == b.num) 
      return a.val < a.val;
    return a.num < b.num;
  }
};

int a[maxM];
int ans1[maxN], ans2[maxN];

fuck n[maxN];

ll lcm(ll t1, ll t2) {
  if(t1 == (ll)maxM) return (ll)maxM;
  ll ret;
  ret = t1 / __gcd(t1, t2) * t2;
  if(ret > 1000000) ret = (ll)maxM;
  return ret;
}

int work() {
  int N;
  memset(ans1, inf, sizeof(ans1));
  memset(ans2, inf, sizeof(ans2));
  memset(a, 0, sizeof(a));
  if(scanf("%d", &N) != 1) return 0;
  for(int i = 1; i <= N; i++) {
    int xx; scanf("%d", &xx);
    a[xx] ++;
  }
  int ind = 0;
  int imax = 0; 
  ll lcm_num = 1ll;
  for(int i = 1; i <= 1000000; i++) {
    if(a[i] == 0) continue;
    ++ind;
    n[ind].val = i;
    n[ind].num = a[i];
    imax = max(imax, i);
    lcm_num = lcm(lcm_num, i);
  }
  if(ind == 1) {
    printf("1");
    for(int i = 0; i < N; i++)
      printf(" %d", 1);
    printf("\n");
    return 1;
  }
  sort(n+1, n+1+ind);

  ans1[0] = ans2[0] = ind;

  int ta = ind;
  int stj = 2;
  if(lcm_num == maxM || a[lcm_num] == 0) {
    for(int i = 1; i < n[1].num; i++) 
      ans1[i] = ta+1;
    ans1[n[1].num] = ta;
  } else {
    if(n[1].val == lcm_num) stj++;
    for(int i = 1; i < n[stj-1].num; i++) 
      ans1[i] = ta;
    ans1[n[stj-1].num] = ta-1;
    ta--;
  }
  for(int i = n[stj-1].num,j = stj; i <= N, j <= ind;j++) {
    if(ta == 0) ta = 1;
    if(n[j].val == lcm_num) continue;
    int st = i+1, ed = i + n[j].num;
    for(int k = st; k <= ed; k++) {
      ans1[k] = ta;
    }
    ta --;
    i = ed;
    ans1[i] = ta;
  }
  for(int i = 1; i <= N; i++) 
    if(ans1[i] == ans1[maxN-1]) ans1[i] = ans1[i-1];
  //for(int i = 0; i <= N; i++) 
  //  cout << ans1[i] << ' ';
  //cout << endl;
  ta = ind;
  //ans2
  for(int i = 0,j = 1; i <= N, j <= ind;j++) {
    int xx = -1;
    for(int k = imax / n[j].val * n[j].val; k > n[j].val; k -= n[j].val) {
      if(a[k] != 0) {
        xx = k;
        break;
      }
    }
    if(xx == -1) continue;
    if(ta == 0) ta = 1;
    int st = i+1, ed = i + n[j].num;
    for(int k = st; k <= ed; k++) {
      ans2[k] = ta;
    }
    ta --;
    i = ed;
    ans2[i] = ta;
  }
  for(int i = 1; i <= N; i++) 
    if(ans2[i] == ans2[maxN-1]) ans2[i] = ans2[i-1];
  //for(int i = 0; i <= N; i++) 
  //  cout << ans2[i] << ' ';
  //cout << endl;
  printf("%d", min(ans1[0], ans2[0]));
  for(int i = 1; i <= N; i++) {
    printf(" %d", min(ans1[i], ans2[i]));
  }
  printf("\n");
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
#ifdef ONLINE_JUDGE
  freopen("equal.in","r",stdin);
  freopen("equal.out","w",stdout);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

