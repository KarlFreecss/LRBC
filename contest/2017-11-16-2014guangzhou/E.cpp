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

struct people{
  string name;
  int n;
  friend bool operator < (const people& a, const people& b) {
    if(a.n != b.n)
      return a.n > b.n;
    return a.name < b.name;
  }
};

const int maxN = 500+13;
int cnt[maxN];
map<string, int> hs;
people xx[maxN];

int work() {
  memset(cnt, 0, sizeof(cnt));
  hs.clear();

  int N, M;
  scanf("%d", &N);
  if(N == 0) return 0;
  char name[maxN];
  for(int i = 1; i <= N; i++) {
    int tk = 0;
    scanf("%s%d", name, &tk);
    xx[i].name = string(name);
    xx[i].n = tk;
    cnt[tk]++;
    hs[string(name)] = tk;
  }
  sort(xx+1, xx+1+N);
  for(int i = 1; i <= N; i++) {
    printf("%s %d\n", xx[i].name.c_str(), xx[i].n);
  }
  scanf("%d", &M);
  for(int i = 1; i <= M; i++) {
    scanf("%s", name);
    string sname = name;
    int tk = hs[sname];
    //cout <<sname << endl;
    //cout << tk << endl;
    int major = 1, minor = 1;;
    for(int j = 1; j <= N; j++) {
      if(xx[j].n > tk) major++;
      if(xx[j].name == sname) 
        break;
      if(xx[j].n == tk) minor++;
    }
    if(minor == 1) {
      printf("%d\n", major);
    } else {
      printf("%d %d\n", major, minor);
    }
  }
  return 1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  while(work()) ;
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

