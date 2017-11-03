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

const int MAXL = 4045;

set<ull> S;

char str1[MAXL];
char str2[MAXL];

ull getMask(int a[26]){
    ull ftnn = 4399;
    ull exp = 4399;
    ull mask = 0;
    for (int i = 0; i < 26; ++i) {
      mask = mask * ftnn + a[i];
    }
    return mask;
}

int work(int & flag){
  if (scanf("%s", str1) < 1) {
    flag = 0;
    return 0;
  } 
  if (scanf("%s", str2) < 0) {
    flag = 0;
    return 0;
  }
  int l1 = strlen(str1);
  int l2 = strlen(str2);
  for (int i = l1-1; i >= 0; --i) {
    S.clear();
    int c1[26] = {0};
    for (int j = 0; j <= i; ++j) {
      ++c1[str1[j] - 'a'];
    }
    if (i == -1) {
      for (int o = 0; o < 26; ++o) {
        cout << c1[o] << ' ';
      }
      cout << getMask(c1) << endl;
    }
    S.insert(getMask(c1));
    for (int k = 1; k + i < l1; ++k) {
      --c1[str1[k-1] - 'a'];
      ++c1[str1[k+i] - 'a'];
      S.insert(getMask(c1));

      if (i == -1) {
        for (int o = 0; o < 26; ++o) {
          cout << c1[o] << ' ';
        }
        cout << getMask(c1) << endl;
      }
    }

    if (i == -1) cout << endl;
    int c2[26] = {0};
    for (int j = 0; j <= i; ++j) {
      ++c2[str2[j] - 'a'];
    }

    if (i == -1) {
      for (int o = 0; o < 26; ++o) {
        cout << c2[o] << ' ';
      }
      cout << getMask(c2) << ' ';
    }

    if (S.count(getMask(c2))) {
      return i;
    }


    for (int k = 1; k + i < l2; ++k) {
      --c2[str2[k-1] - 'a'];
      ++c2[str2[k+i] - 'a'];

      if (i == -1) {
        for (int o = 0; o < 26; ++o) {
          cout << c2[o] << ' ';
        }
        cout << getMask(c2) << ' ';
      }

      if (S.count(getMask(c2))) {
        return i;
      }
    }
    if (i == -1)cout << endl;
  }
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("D.in","r",stdin);
#endif
  int flag = 1;
  while (flag) {
    int ans = work(flag);
    if (flag) cout << ans+1 << endl;
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

