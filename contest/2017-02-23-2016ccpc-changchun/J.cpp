#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXLEN = 1010;
const int MAXANSNUM = 100;

char s[MAXLEN];
int slen;
int a[MAXLEN], alen;
int ans[MAXANSNUM][MAXLEN], ansNum;

int getLen(int a[MAXLEN]) {
  per(i, 0, MAXLEN)
    if (a[i] != 0)
      return i;
  return -1;
}
void output(int a[MAXLEN]) {
  int alen = getLen(a);
  per(i, 0, alen + 1)
    printf("%d", a[i]);
  printf("\n");
}
int findNotZero(int a[MAXLEN], int startPos) {
  per(i, 0, startPos)
    if (a[i] != 0)
      return i;
  return -1;
}
void Subtract(int a[MAXLEN], int b[MAXLEN]) {
  rep(i, 0, MAXLEN - 1) {
    if (a[i] < b[i]) {
      a[i] = a[i] + 10 - b[i];
      a[i + 1] --;
    } else {
      a[i] = a[i] - b[i];
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  int T, t = 0, notZero;
  scanf("%d", &T);
  while (T--) {
    memset(a, 0, sizeof(a));
    t ++;
    scanf("%s", s);
    printf("Case #%d:\n", t);
    slen = strlen(s);
    rep(i, 0, slen) {
      a[i] = s[slen - i - 1] - '0';
    }
    ansNum = 0;
    while (true) {
//      cout << "=============" <<endl;
//      cout << "pre a" << endl;
//      output(a);
      alen = getLen(a);
      if (alen == -1)
        break;
      if (alen == 0) {
        rep(i, 0, MAXLEN)
          ans[ansNum][i] = a[i];
        ansNum ++;
        break;
      }
      notZero = findNotZero(a, alen);
      if (notZero == -1) {
        memset(ans[ansNum], 0, sizeof(ans[ansNum]));
        if (a[alen] == 1) {
          rep(i, 0, alen)
            ans[ansNum][i] = 9;
        } else {
          rep(i, 0, alen)
            ans[ansNum][i] = 10 - a[alen] + 1;
        }
        Subtract(a, ans[ansNum]);
        ansNum ++;
      } else {
        if (notZero >= (alen + 1) / 2) {
          rep(i, (alen + 1)/2, alen + 1) {
            if (a[i] != 0) {
              notZero = i;
              break;
            }
          }
          memset(ans[ansNum], 0, sizeof(ans[ansNum]));
          rep(i, notZero + 1, alen + 1)
            ans[ansNum][i] = a[i];
          ans[ansNum][notZero] = a[notZero] - 1;
          rep(i, 0, alen / 2 + 1) {
            ans[ansNum][i] = ans[ansNum][alen - i];
          }
          Subtract(a, ans[ansNum]);
          ansNum ++;
        } else {
          memset(ans[ansNum], 0, sizeof(ans[ansNum]));
          if (notZero == 0)
            ans[ansNum][alen] = min(a[0], a[alen]);
          else ans[ansNum][alen] = a[alen];
          ans[ansNum][0] = ans[ansNum][alen];
          Subtract(a, ans[ansNum]);
          ansNum ++;
        }
      }
//      cout << "subNum" << endl;
//        output(ans[ansNum]);
//      cout << "last a" <<endl;
//        output(a);
    }
    if (ansNum > 50)
      while (true);
    printf("%d\n", ansNum);
    rep(i, 0, ansNum)
      output(ans[i]);
  }

  return 0;
}

