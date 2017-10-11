#include<bits/stdc++.h>

using namespace std;

int n;
int per[12];
map<int, int> intToInt;

typedef vector<int> EDGE;
vector<EDGE> net;

int expD[10];

inline void swapD(int & tmp, int x){
  int a = tmp % 10;
  int b = tmp / expD[x] % 10;
  tmp += a * expD[x] - a + b - b * expD[x];
}

void init(int n){
  expD[0] = 1;
  for (int i = 1; i < 10; ++i) {
    expD[i] = expD[i-1] * 10;
  }
  string tmp;
  for (int i = 0; i < n; ++i) {
    per[i] = i + 1;
  }
  int count = 0;
  do {
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      tmp = tmp * 10 + per[i];
    }
    intToInt[tmp] = count++;
  } while (next_permutation(per, per + n));

  int tot = 1;
  for (int i = 1; i <= n; ++i) tot *= i;
  net.resize(tot);
  for (int i = 0; i < n; ++i) {
    per[i] = i + 1;
  }
  do {
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      tmp = tmp * 10 + per[i];
    }
    int mark = intToInt[tmp];
    net[mark].resize(n-1);
    for (int i = 0; i < net[mark].size(); ++i) {
      swapD(tmp, i+1);
      net[mark][i] = intToInt[tmp];
      cout << mark << " -> " << intToInt[tmp] << endl;
      swapD(tmp, i+1);
    }
  } while (next_permutation(per, per + n));

}

int main(){
  scanf("%d", &n);
  //n = 9;
  init(n);
  cout<<"time: "<<(long long)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}

