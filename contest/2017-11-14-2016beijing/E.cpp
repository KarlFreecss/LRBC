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

int f[maxN][5][5];

queue<int> qi, qn;

int work() {
  int N;
  if(scanf("%d", &N) != 1) return 0;
  int ans = 10000;;
  for(int i = 0; i <= 3; i++) {
    for(int j = 0 ; j <= 2; j++) {
      if(f[N][i][j] != -1)
        ans = min(ans, f[N][i][j]);
    }
  }
  if(ans == 10000) ans = -1;
  printf("%d\n", ans);
  return 1;
}

int p10[10];
int s[maxN];

int transfer() {
  int ret  = 0 ;
  for(int i = 1; i <= 5; i++) 
    ret += s[i] * p10[i-1];
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
//  freopen("E.out","w",stdout);
#endif
  p10[0] = 1;
  for(int i = 1; i <= 7; i++) p10[i] = p10[i-1] * 10;
  memset(f, -1 , sizeof(f));
  f[12345][0][0] = 0;
  qi.push(12345);qn.push(0);
  while(!qi.empty()) {
    int id = qi.front(); qi.pop();
    int n = qn.front()/100; 
    int n2 = (qn.front()%100) / 10; 
    int n3 = qn.front()%10; qn.pop();
    int tt = id;
    for(int i = 1; i <= 5; i++) {
      s[i] = tt % 10;
      tt /= 10;
    }
    for(int i = 1; i <5; i++) {
      swap(s[i], s[(i+1)]);
      tt = transfer();
      if(f[tt][n2][n3] == -1) {
        f[tt][n2][n3] = (n+1);
        qi.push(tt);
        qn.push((n+1) * 100 + n2*10 + n3);
      }
      //swap(s[i], s[(i+1) % 6 + 1]);
      swap(s[i], s[i+1]);
    }
    if(n2 < 3) {
      for(int i = 1; i <= 5; i++) {
        int ts = s[i];
        s[i] = (s[i] + 1) % 10;
        tt = transfer();
        if(f[tt][n2+1][n3] == -1) {
          f[tt][n2+1][n3] = (n+1);
          qi.push(tt);
          //cout << id << " -> " << tt << endl;
          qn.push((n+1) * 100 + (n2+1)*10 + n3);
          //cout << n2+1 << ' ' << n3 << endl;
        }
        s[i] = ts;
      }
    }
    if(n3 < 2) {
      for(int i = 1; i <= 5; i++) {
        int ts = s[i];
        s[i] = (s[i] * 2) % 10;
        tt = transfer();
        if(f[tt][n2][n3+1] == -1) {
          f[tt][n2][n3+1] = (n+1);
          qi.push(tt);
          //cout << id << " -> " << tt << endl;
          //cout << n2 << ' ' << n3+1 << endl;
          qn.push((n+1) * 100 + n2*10 + n3+1);
        }
        s[i] = ts;
      }
    }
  }
  while(work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

