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

const int maxB = 2500+13;
const int maxN = 100+13;
const double eps = 0.5;

struct BigInt {
  int n, a[maxB];
  BigInt(int x=0) {
    memset(a,0,sizeof(a));
    n = 0;
    int block = 10000;
    while(x) {
      a[n] = x % block;
      n++;
      x /= block;
    }
  }
  void trunc() {
    for(--n; n >= 0 && a[n] == 0; --n);
    n++;
    return ;
  }
  void carry(int tn = 0) {
    int temp = 0, i;
    for(i = tn; i < n || temp > 0; i++) {
      temp += a[i];
      a[i] = temp % 10000;
      temp /= 10000;
    }
    if(i >= n) n = i;
    return ;
  }
  void show() {
    if(n == 0) {cout << "0"; return ;}
    cout << a[n-1];
    for(int i = n-2; i >= 0; i--) {
      cout.fill('0'), cout.width(4), cout << a[i];
    }
  }
  friend BigInt operator + (const BigInt& x, const BigInt& y) {
    BigInt ret;
    ret.n = 0;
    ret.n = max(x.n, y.n) + 1;
    int temp = 0;
    for(int i = 0; i <= ret.n; i++) {
      if(i < x.n) temp += x.a[i];
      if(i < y.n) temp += y.a[i];
      ret.a[i] = temp % 10000;
      temp /= 10000;
    }
    ret.trunc();
    return ret;
  }
  friend BigInt operator * (const BigInt& x, const BigInt& y) {
    BigInt ret;
    ret.n = 0;
    ret.n = x.n + y.n + 1;
    for(int i = 0; i < x.n; i++) {
      for(int j = 0; j < y.n; j++) {
        ret.a[i+j] += x.a[i] * y.a[j];
        if(ret.a[i+j] > 100000000) ret.carry(i+j);
      }
    }
    ret.carry(0);
    ret.trunc();
    return ret;
  }
  friend bool operator < (const BigInt& x, const BigInt& y) {
    if(x.n == y.n) {
      for(int i = x.n-1; i >= 0; i--) {
        if(x.a[i] == y.a[i]) continue;
        return x.a[i] < y.a[i];
      }
      return false;
    } else {
      return x.n < y.n;
    }
  }
};

struct fenshu {
  BigInt fz, fm;
  fenshu(){};
  friend fenshu operator + (const fenshu& a, const fenshu& b) {
    fenshu ret;
    ret.fz = a.fz * b.fm + b.fz * a.fm;
    //ret.fz.show();
    ret.fm = a.fm * b.fm;
    //ret.fm.show();
    return ret;
  }
  bool ok() {
    return fz < fm;
  }
  friend bool operator < (const fenshu& a, const fenshu& b) {
    return a.fz*b.fm < a.fm*b.fz;
  }
  void show() {
    fz.show();
    cout << "/"; 
    fm.show();
    cout << endl;
  }
};

char s[maxN];
vector<fenshu> a;

int work() {
  int N;
  int ret = 0;
  fenshu tt;
  a.clear();
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%s", s);
    //double ta = 0.0;
    string ss = string(s);
    string s1 = "", s2 = "";
    int len = strlen(s);
    int findcolon = ss.find(":");
    for(int i = 0; i < findcolon; i++) {
      s1 += s[i];
    }
    for(int i = findcolon+1; i < len; i++) {
      s2 += s[i];
    }
    int t1= (atof(s1.c_str()) * 1000.0 + eps);
    int t2= (atof(s2.c_str()) * 1000.0 + eps);
    tt.fz = BigInt(t1);
    tt.fm = BigInt(t1+t2);
    a.push_back(tt);
  }
  sort(all(a));
  //for(int i = 0; i < N; i++) {
  //  a[i].show();
  //}
  tt.fz = BigInt(0);
  tt.fm = BigInt(1);
  //cout << "tt = "; tt.show();
  fenshu tf;
  for(int i = 0; i < N; i++) {
    tf = tt + a[i];
    //cout << "a[i] = ";a[i].show();
    //cout << "tf = "; tf.show();
    if(tf.ok()) {
      ret++;
      tt = tf;
    } else {
      return ret;
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    printf("Case #%d: %d\n", cas, work());
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

