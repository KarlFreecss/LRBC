#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 1e5+13;

int T,N;
int a[maxN];
int incEnd[maxN], decEnd[maxN];
int incBegin[maxN], decBegin[maxN];

int main() {

  scanf("%d", &T);
  rep(cas, 0, T) {
    scanf("%d", &N);
    rep(i, 1, N+1) {
      scanf("%d", &a[i]);
    }
    incEnd[1] = decEnd[1] = 1;
    rep(i, 2, N+1) {
      decEnd[i] = decEnd[i-1] + 1;
      incEnd[i] = incEnd[i-1] + 1;
      if(a[i] > a[i-1]) {
        decEnd[i] = 1;
      }
      if(a[i] < a[i-1]) {
        incEnd[i] = 1;
      }
    }
    if(incEnd[N-1] == N-1 || decEnd[N-1] == N-1) {
      printf("YES\n");
      continue;
    }
    incBegin[N] = decBegin[N] = 1;
    per(i, 1, N) {
      incBegin[i] = incBegin[i+1] + 1;
      decBegin[i] = decBegin[i+1] + 1;
      if(a[i] > a[i+1]) {
        incBegin[i] = 1;
      }
      if(a[i] < a[i+1]) {
        decBegin[i] = 1;
      }
    }
    if(incBegin[2] == N-1 || decBegin[2] == N-1) {
      printf("YES\n");
      continue;
    }
    bool ok = false;
    rep(i, 2, N) {
      if(a[i-1] <= a[i+1]) {
        if(incEnd[i-1] + incBegin[i+1] == N-1) {
          ok = true;
          break;
        }
      }
      if(a[i-1] >= a[i+1]) {
        if(decEnd[i-1] + decBegin[i+1] == N-1) {
          ok = true;
          break;
        }
      }
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    /*
    cout << "incBegin:" << endl;
    rep(i,1,N+1) 
      cout << incBegin[i] << ' ';
    cout<<endl;
    cout << "incEnd:" << endl;
    rep(i,1,N+1) 
      cout << incEnd[i] << ' ';
    cout<<endl;
    cout << "decBegin:" << endl;
    rep(i,1,N+1) 
      cout << decBegin[i] << ' ';
    cout<<endl;
    cout << "decEnd:" << endl;
    rep(i,1,N+1) 
      cout << decEnd[i] << ' ';
    cout<<endl;
    */
  }

  return 0;
}

