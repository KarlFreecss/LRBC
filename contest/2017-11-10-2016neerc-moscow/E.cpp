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

const int MAXN = 2e5 + 100;

class line {
  public:
    int x, y, type;
    line(int iX = 0, int iY = 0, int iType = 0) {
      x = iX;
      y = iY;
      type = iType;
    }
};

int a[MAXN];

int work(){
  int n;
  if (scanf("%d", &n) != 1) return 0;
  vector<line> v;
  int m = 0;
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    if (v.size() == 0) {
      v.push_back(line(x, x, 0));
    } else {
      if (v[m].type == 0) {
        if (x > v[m].y + 2) {
          v.push_back(line(x, x, 0));
          m ++;
        } else if (x == v[m].y + 2) {
          v[m].type = 2;
          v[m].y = x;
        } else if (x == v[m].y + 1) {
          v[m].type = 1;
          v[m].y = x;
        }
      } else if (v[m].type == 1) {
        if (x == v[m].y + 1) {
          v[m].y ++;
        } else {
          v.push_back(line(x, x, 0));
          m ++;
        }
      } else if (v[m].type == 2) {
        if (x == v[m].y + 2) {
          v[m].y += 2;
        } else {
          v[m].y --;
          v.push_back(line(x - 1, x, 2));
        }
      }
    }
  }
  for (int i = 0; i < v.size(); i ++) {
    cout << v[i].x << " " << v[i].y << " " << v[i].type << endl;
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in","r",stdin);
#endif
  while(work());

  return 0;
}

