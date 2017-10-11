#include <bits/stdc++.h>

using namespace std;

const int MAXN = 120;
const int MAXM = 120;

int n, m;

char img[MAXN][MAXM];

vector<vector<int>> transT(const vector<vector<int>> & T){
  vector<vector<int>> res(T[0].size());
  for (int i = 0; i < res.size(); ++i) {
    res[i].resize(T.size());
  }
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res[0].size(); ++j) {
      res[i][j] = T[j][res.size() - i - 1];      
    }
  }
  return res;
}

int work(){
  //freopen("a.in", "r", stdin);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      img[i][j] = getchar();
      if (img[i][j] != '.' && img[i][j] != '#' && img[i][j] != '+') {
        j--;
        continue;
      }
    }
  }
  //for (int i = 0; i < n; ++i){
  //  for (int j = 0; j < m; ++j) cout << img[i][j];
  //  cout  << endl;
  //}
  int rl = 0, cl = 0;
  for (int i = 1; i < n; ++i) {
    if (img[i][1] == '#') ++rl;
  }
  for (int i = 1; i < m; ++i) {
    if (img[1][i] == '#') ++cl;
  }

  int r = (n-1) / rl;
  int c = (m-1) / cl;

  set<vector<vector<int>>> S;
  int ans = 0;
  for (int i = 0; i < rl; ++i) {
    for (int j = 0; j < cl; ++j) {
      vector<vector<int>> tmp(r-1);
      for (int ri = 0; ri < r-1; ++ri) {
        for (int ci = 0; ci < c-1; ++ci) {
          char ch = img[i * r + ri + 1][j * c + ci + 1]; 
          tmp[ri].push_back((int)(ch == '+'));
        }
      }
      vector<vector<vector<int>>> stored(4);
      int flag = 1;
      for (int k = 0; k < 4; ++k) {
        unsigned long long res = 0;
        if (S.find(tmp) != S.end()) flag = 0;
        stored[k] = tmp;
        tmp = transT(tmp);
      }

      if (flag) {
        ++ans;
        for (int k = 0; k < 4; ++k) {
          S.insert(stored[k]);
        }
      }
    }
  }
  return ans;
}

int main(){
  while(scanf("%d%d", &n, &m) != EOF) {
    cout << work() << endl;
  }
 // cout << work() << endl;
  return 0;
}



/*
 *1 2 3
 *4 5 6
 *7 8 9
 *
 *3 6 9
 *2 5 8
 *1 4 7

 *
 */
