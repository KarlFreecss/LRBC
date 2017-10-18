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

const int MAXN = 5010;

char s[MAXN], t[MAXN];
int sVal[MAXN], tVal[MAXN];
int resX[5], resY[5];
int next1[MAXN], flag[MAXN];
int tt;

vector<int> EKMP_pre_suf(int sVal[], int sx, int sy, int tVal[], int tx, int ty) {
  int len = sy - sx + 1;
  for (int i = 0; i <= len; i ++)
    next1[i] = 0;
  int j = next1[0] = -1;
  int i = 0;
  while (i + 1 < len) {
    while (sVal[sx + i + 1] != sVal[sx + j + 1]) {
      if (j == -1) {
        j = -2;
        break;
      }
      j = next1[j];
    }
    next1[++ i] =  ++ j;
  }
  j = -1;
  for (int i = 0; i < len; i ++) {
    while (sVal[sx + j + 1] != tVal[tx + i]) {
      if (j == -1) {
        j = -2;
        break;
      }
      j = next1[j];
    }
    j ++;
  }
  vector<int> res;
  while (j != -1) {
    res.push_back(j + 1);
    j = next1[j];
  }
  return res;
}

int check(int sVal[], int sx, int sy, int tVal[], int tx, int ty, int id1, int id2) {
  int len = sy - sx + 1;
  if (len < 2)
    return 0;
  vector<int> s_pre = EKMP_pre_suf(sVal, sx, sy, tVal, tx, ty);
  vector<int> t_pre = EKMP_pre_suf(tVal, tx, ty, sVal, sx, sy);
  int kk;
  for (kk = 0; kk < len; kk ++) {
    if (sVal[sx + kk] != tVal[tx + kk])
      break;
  }
//  cout << kk << endl;
//  cout << sx << " " << sy << " " << tx << " " << ty << " " << len << endl;
  if (kk >= len) {
    resX[id1] = tx; resY[id1] = tx;
    resX[id2] = tx + 1; resY[id2] = ty;
//      cout << resX[id1] << " " << resY[id1] << endl;
//      cout << resX[id2] << " " << resY[id2] << endl;
    return -1;
  }
  for (int i = 0; i < s_pre.size(); i ++)
    flag[s_pre[i]] = tt;
  for (int i = 0; i < t_pre.size(); i ++) {
    if (flag[len - t_pre[i]] == tt) {
      resX[id1] = tx + t_pre[i];
      resY[id1] = ty;
      resX[id2] = tx;
      resY[id2] = tx + t_pre[i] - 1;
//      cout << "! " << t_pre[i] << " " << id1 << " " << id2 << endl;
//      cout << resX[id1] << " " << resY[id1] << endl;
//      cout << resX[id2] << " " << resY[id2] << endl;
      return -1;  
    }
  }
  tt ++;
  return 0;
}

void outputS(char s[], int x, int y) {
//  cout << s << " " << x << " " << y << endl;
  for (int i = x; i <= y; i ++) {
    printf("%c", s[i]);
  }
  printf("\n");
}
void output() {
  printf("YES\n");
  outputS(t, resX[0], resY[0]);
  outputS(t, resX[1], resY[1]);
  outputS(t, resX[2], resY[2]);
  return;
}

void work() {
  memset(flag, 0, sizeof(flag));
  tt = 1;
  int sx, sy, tx, ty, len, res;
  scanf("%s%s", &s, &t);
  sx = 0; sy = strlen(s) - 1;
  tx = 0; ty = strlen(t) - 1;
  len = strlen(s);
  for (int i = 0; i < len; i ++) {
    if ('a' <= s[i] && s[i] <= 'z') {
      sVal[i] = s[i] - 'a';
    } else {
      sVal[i] = s[i] - 'A';
    }
    if ('a' <= t[i] && t[i] <= 'z') {
      tVal[i] = t[i] - 'a';
    } else {
      tVal[i] = t[i] - 'A';
    }
  }
  if (len < 3) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < len; i ++) {
    if (sVal[i] != tVal[i]) break;
    resX[0] = 0; resY[0] = i;
    res = check(sVal, i + 1, sy, tVal, i + 1, ty, 1, 2);
    if (res == -1) {
//      cout << resX[2] << " " << resY[2] << endl;
      output();
      return;
    }
  }
  for (int i = len - 1; i >= 0; i --) {
    if (sVal[i] != tVal[i]) break;
    resX[2] = i; resY[2] = len - 1;
    res = check(sVal, 0, i - 1, tVal, 0, i - 1, 0, 1);
    if (res == -1) {
      output();
      return;
    }
  }
  vector<int> v;
  
  v = EKMP_pre_suf(sVal, 0, sy, tVal, 0, ty);
//  for (int i = 0; i < v.size(); i ++)
//    cout << v[i] << " ";
//  cout << endl;
  for (int i = 0; i < v.size(); i ++) {
    resX[0] = ty - v[i] + 1;
    resY[0] = ty; 
    res = check(sVal, v[i], sy, tVal, 0, ty - v[i], 1, 2);
    if (res == - 1) {
      output();
      return;
    }
  }

  v = EKMP_pre_suf(tVal, 0, ty, sVal, 0, sy);
//  for (int i = 0; i < v.size(); i ++)
//    cout << v[i] << " ";
//  cout << endl;

  for (int i = 0; i < v.size(); i ++) {
    resX[2] = 0; resY[2] = v[i] - 1;
    res = check(sVal, 0, sy - v[i], tVal, v[i], ty, 0, 1);
    if (res == -1) {
      output();
      return;
    }
  }

  printf("NO\n");
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
  work();
  return 0;
}

