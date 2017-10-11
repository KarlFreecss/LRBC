#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

int T, N;

int main() {
 // cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    scanf("%d", &N);
    int tt = 0;
    while(N) {tt++; N/=10;}
    printf("1");
    for(int i =1 ;i <233; i++) {
      for(int j = 1; j < tt; j++) printf("0");
      printf("1");
    }
    printf("\n");
  }
  int Mo = 1e9 + 7;
  for(int i = 2;  i <= sqrt(Mo) ;i++) 
    if(Mo % i == 0) cout << i << endl;

  return 0;
}

