#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e9 + 2;

const int MAXP = 1e6;

int p[MAXP];
int b[MAXP];
int Pcount;

void initP(){
  b[0] = 1;
  b[1] = 0;
  for (int i = 2; i < MAXP; ++i) {
    if (b[i]) continue;
    p[Pcount++] = i;
    for (int k = i + i; k < MAXP; k += i) {
      b[k] = 1;
    }
  }
}

inline
bool check(int x){
  for (int i = 0; p[i] * p[i] <= x; ++i) {
    if (x % p[i] == 0) return 0;
  }
  return 1;
}

int main()
{
  initP();
  int lastP = 2;
  int maxD = 1, fuck, woc;
  for (int i = 3; i < MAXN; ++i) {
    if (check(i)) {
      if (i - lastP > maxD) {
        maxD = i - lastP;
        fuck = i;
        woc = lastP;
      }
      lastP = i;
    }
    if (i % 10000000 == 0) printf("N = %d  maxD = %d  fuck = %d  woc = %d\n", i, maxD, fuck, woc);
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

