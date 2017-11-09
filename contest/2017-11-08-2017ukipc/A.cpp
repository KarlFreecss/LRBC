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

struct DAY{
  int hour, sunrise, sunset;
};

void getSunTable(const DAY & d, vector<int> & t, const int maxD){
  t.clear();
  if (d.sunrise < d.sunset) t.push_back(0);
  else t.push_back(1);
  if (d.sunrise == 0) t[0] = -1;
  int count = 0;
  for (int i = 1; i < maxD; ++i) {
    if (t[i-1] != 0) t.push_back(1);
    else t.push_back(0);
    ++count;
    if (count >= d.hour) {
      count -= d.hour;
    }
    if (d.sunrise == count) {
      t[i] = -1;
    }
    if (d.sunset == count) {
      t[i] = 0;
    }
  }

 // cout << t.size() << endl;
 /* for (int i = 0; i < t.size(); ++i) {
    cout << t[i] << ' ' ;
  } cout << endl;*/
}

int getAns(const vector<vector<int>> & t, const int maxD){
  int ans = -1;
  for (int d = 0; d < maxD; ++d) {
    int flag = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (t[i].size() <= d) {
        return -1;
      }
      flag |= (t[i][d] == 1);
    }
    if (!flag) return d;
  }
  return ans;
}

int work(){
  int N;
  if (scanf("%d", &N) != 1) return 0;
  vector<DAY> d;
  vector<vector<int>> sunTable;
  d.resize(N);
  sunTable.resize(N);
  int maxD = 0;
  for (int i = 0; i < N; ++i) {
    cin >> d[i].hour >> d[i].sunrise >> d[i].sunset;
    maxD = max(maxD, d[i].hour * 1825);
  }
  for (int i = 0; i < N; ++i) {
    getSunTable(d[i], sunTable[i], maxD);
  }
  int ans = getAns(sunTable, maxD);
  if (ans != -1) cout << ans << endl;
  else cout << "impossible" << endl;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif
  while (work());
  return 0;
}

