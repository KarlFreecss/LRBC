#include <bits/stdc++.h>

using namespace std;

vector<int> p;

void work(int id){
  int n;
  scanf("%d", &n);
  p.clear();
  for (int i = 0; i < n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    p.push_back(tmp);
  }
  sort(p.begin(), p.end());
  int sum = 0, k = 1;
  for (int i = n-1; i >= 0; i--, ++k){
    if (k % 3 == 0) continue;
    sum += p[i];
  }
  printf("Case #%d: %d\n", id, sum);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    work(i);
  }
  return 0;
}

