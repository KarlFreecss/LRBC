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

const int maxN = 100000+13;

int ans[maxN];
char ansc[20];
int T;

void work() {
  int N;
  scanf("%d", &N);
  printf("%d %c\n", N, ansc[ans[N]]);
  return ;
}

struct fenshu{
  ull fz, fm;
  fenshu(){};
  fenshu(ull fz, ull fm) : fz(fz), fm(fm){};
  fenshu operator - (const fenshu& b) {
    ull tz, tm;
    tm = fm / __gcd(b.fm, fm) * b.fm;
    tz = tm/fm * fz - tm/b.fm * b.fz;
    fenshu ret; 
    ret.fz = tz;
    ret.fm = tm;
    ret.yuefen();
    return ret;
  }
  void yuefen() {
    ull gcd = __gcd(fz, fm);
    fz /= gcd;
    fm /= gcd;
    return ;
  }
  int get() {
    fz *= 16;
    int ret = fz / fm;
    fz %= fm;
    return ret;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  for(int i = 0; i <= 9; i++) 
    ansc[i] = '0' + i;
  for(int i = 10; i <= 15; i++) 
    ansc[i] = 'A' + i - 10;
  fenshu xs = fenshu(1,1) - fenshu(1,2) - fenshu(1,5) - fenshu(1,6);
  cout << xs.fz << ' ' << xs.fm << endl;
  for(int i = 1; i <= 100000; i++) {
    int i8 = i*8;
    ans[i] = xs.get();
    xs = xs - (fenshu(4, i8+1) - fenshu(2, i8+4) - fenshu(1,i8+5) - fenshu(1,i8+6));
    if(i < 20) {
      cout << ansc[ans[i]];
    }
  }
  cout << endl;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: ", cas);
    work();
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

