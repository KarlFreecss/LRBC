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

int check(const long long Q, long long & P, const long long & LFL, const long long & stdBase){
  P = sqrt(LFL * 1. / stdBase * Q * Q);
  int low = max(0ll, P - 5);
  int high = P + 5;
  for (P = low; P < high; ++P) {
    long long C = ((P * P * 1./ (Q * Q)) * stdBase + 0.5);
    //cout << P << ' ' << Q << ' ' << C << endl;
    if (C == LFL) return 1;
  }
  return 0;
}

int t = 0;

int work(){
  double F;
  char buff[256];
  if (scanf("%s", buff) != 1) return 0;
  sscanf(buff, "%lf", &F);
  int len = strlen(buff) - 2;
  long long stdBase = 1;
  for (int i = 0; i < len; ++i) {
    stdBase *= 10; 
  }
  long long LFL = F * stdBase;
  long long Q = 1, P;
  t++;
  printf("Case #%d: ", t);
  for (int i = 1; i < 20; ++i) {
    Q = i;
    if (check(Q, P, LFL, stdBase)) {
      printf("%lld/%lld\n", P, Q);
      return 1;
    }
  }
  assert(false);
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif

  while (work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

