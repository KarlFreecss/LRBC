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

const int maxQ = 2e5 + 13;
const int maxN = 2e5 + 13;
struct op {
  int type, st, ed;
};

int N, Q, M;
op q[maxQ];
int a[maxN], b[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-863D.in","r",stdin);
#endif
  scanf("%d%d%d", &N, &Q, &M);
  //cout << N << ' ' << Q << ' ' << M << endl;
  rep(i, 1, N+1) scanf("%d", &a[i]);
  rep(i, 1, Q+1) {
    scanf("%d%d%d", &q[i].type, &q[i].st, &q[i].ed);
  }
  rep(i, 1, M+1) {
    scanf("%d", &b[i]);
    per(j, 1, Q+1) {
      if(b[i] > q[j].ed || b[i] < q[j].st) continue;
      if(q[j].type == 1) {
        if(b[i] == q[j].st) b[i] = q[j].ed;
        else b[i] --;
      } else {
        b[i] = q[j].ed - (b[i] - q[j].st);
      }
    }
  }
  rep(i, 1, M+1) 
    printf("%d ", a[b[i]]);
  printf("\n");

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

