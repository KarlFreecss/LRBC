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

const int MAXN = 1010;

int cn[MAXN], rn[MAXN], tmpn[MAXN];
ll table[MAXN][MAXN];
ll tmpTable[MAXN][MAXN];

int completeTableRow(const int R, const int C, const int row){
  pair<int, int> t;
  for (int i = 0; i < C; ++i) {
    if (table[row][i]) {
      if (t.first) {
        t.second = i;
        break;
      } else {
        t.first = i;
      }
    }
  }
  if (t.second == 0) return true;
  int dx = t.second - t.first;
  assert(dx > 0);
  ll dv = table[row][t.second] - table[row][t.first];
  if (dv % dx) return false;
  dv /= dx;
  if (dv < row + 1) return false;
  ll baseV = table[row][t.first];
  for (int i = 0; i < C; ++i) {
    ll colValue = (i - t.first) * dv + baseV;
    if (colValue <= 0) return false;
    if (table[row][i]) {
      if (colValue != table[row][i]) return false;
    } else table[row][i] = colValue;
  }
  return true;
}

void translate(int & R, int & C, ll table[MAXN][MAXN]){
  int _R = C, _C = R;
  memcpy(tmpTable, table, sizeof(tmpTable));
  memcpy(tmpn, rn, sizeof(tmpn));
  memcpy(rn, cn, sizeof(rn));
  memcpy(cn, tmpn, sizeof(cn));
  for (int i = 0; i < _R; ++i) {
    for (int j = 0; j < _C; ++j) {
      table[i][j] = tmpTable[j][i];
    }
  }
  R = _R;
  C = _C;
}

int tryFunc(int R, int C, ll table[MAXN][MAXN]){
  for (int i = 0; i < R; ++i) {
     if (rn[i] > 1) {
       if (!completeTableRow(R, C, i)) return -1;
       translate(R, C, table);
       for (int i = 0; i < R; ++i) {
         if (!completeTableRow(R, C, i)) return -1;
       }
       return 1;
     }
   }
  return 0;
}

struct NODE{
  ll v;
  int r, c;
};
vector<NODE> vec;

int judge(const ll rp, const ll cp, const int row, const int col, const vector<NODE> & vec){
  //cout << rp << ' ' << cp << endl;
  for (int i = 0; i < (int)vec.size(); ++i) {
    ll _rp = rp - row + vec[i].r;
    ll _cp = cp - col + vec[i].c;
    //cout << " $ " << _rp << ' ' << _cp << endl;
    if (_rp < vec[i].r) return false;
    if (_cp < vec[i].c) return false;
    if (_rp * _cp != vec[i].v) return false;
  }
  return true;
}

int work(){
  int R, C;
  memset(table, 0, sizeof(table));
  memset(cn, 0, sizeof(cn));
  memset(rn, 0, sizeof(rn));

 // int flag = 1;
  scanf("%d%d", &R, &C);
  vec.clear();
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      char buff[128];
      scanf("%s", buff);
      if (string(buff) != "?") {
        table[i][j] = atoi(buff);
   //     ++cn[j];
    //    ++rn[i];
        vec.push_back((NODE){table[i][j], i+1, j+1});
    //    if (rn[i] > 1) flag = 0;
    //    if (cn[j] > 1) flag = 0;
      }
    }
  }
  /*if (!flag) {
   int flag = tryFunc(R, C, table);
   if (flag != 0) return flag == 1;
   translate(R, C, table);
   flag = tryFunc(R, C, table);
   if (flag != 0) return flag == 1;
   assert(flag != 0);
  } else*/
  {
    if (vec.size() == 0) return true;
    ll baseV = vec[0].v;
    int baseR = vec[0].r, baseC = vec[0].c;
    for (ll i = 1; i * i <= baseV; ++ i) {
      if (baseV % i != 0) continue;
      ll rp = i;
      ll cp = baseV / i;
      if (judge(rp, cp, baseR, baseC, vec)) return true;
      if (judge(cp, rp, baseR, baseC, vec)) return true;
    }
    return false;
  }
  assert(false);
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("L.in","r",stdin);
#endif

  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    int flag = work();
    printf("Case #%d: %s\n", i, flag ? "Yes" : "No");
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

