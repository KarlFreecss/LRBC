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
typedef pair<int, int> pii;

const int MAXN = 1e4+5;

unsigned char buff[MAXN];

void handle(vector<int> & v){
  unsigned long long ans = 0;
  int beg = v.size() - 1;
  for (int i = beg; i >= 0; --i) {
    ans = ans * 128 + v[i];
  }
  if (ans & 1) {
    long long out = (ans) / 2 + 1;
    out *= -1;
    printf("%lld\n", out);
  } else {
    long long out = ans / 2; 
    printf("%lld\n", out);
  }
}

int work(){
  int n;
  if (scanf("%d", &n) != 1) return 0;
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    buff[i] = (unsigned char)c;
  }
  vector<int> buf;
  for (int i = 0; i < n; ++i) {
    if (buff[i] >= 128) {
      buf.push_back(buff[i] - 128);
    } else {
      buf.push_back(buff[i]);
      handle(buf);
      buf.clear();
    }
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  while (work());

 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

