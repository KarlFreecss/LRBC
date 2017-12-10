#include<bits/stdc++.h>

using namespace std;

int getTable(int n){
  const static int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
  const static int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
  set<pair<int, int> > land;
  queue<int> qx, qy, qt;
  pair<int, int> S(0, 0);
  land.insert(S);
  qx.push(0);
  qy.push(0);
  qt.push(0);
  while (!qx.empty()){
    int x = qx.front(); qx.pop();
    int y = qy.front(); qy.pop();
    int t = qt.front(); qt.pop();
    if (t == n) continue;
    for (int k = 0; k < 8; ++k) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      pair<int, int> T(tx, ty);
      if (land.find(T) == land.end()) {
	land.insert(T);
	qx.push(tx);
	qy.push(ty);
	qt.push(t+1);
      }
    }
  }
  cout << land.size() << endl;
  return land.size();
}


const int MAXN = 60;
int table[MAXN];

int main(){
  for (int i = 0; i < MAXN; ++i)
    table[i] = getTable(i);
  for (int i = 5; i < MAXN; ++i) {
    int a = table[i] - table[i-1];
    int b = table[i-1] - table[i-2];
    cout << "table " << table[i] << ' ' << table[i-1] << ' ' << table[i-2] << "\ndiff  " << a << ' ' << b << ' ' << a - b << endl;
  }
  return 0;
}
