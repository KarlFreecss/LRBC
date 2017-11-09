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

class D_point {
  public:
    int x, y, z;
    D_point(int iX = 0, int iY = 0, int iZ = 0) {
      x = iX;
      y = iY;
      z = iZ;
    }
    bool equal(D_point a) {
      if (a.x == x && a.y == y && a.z == z)
        return true;
      else 
        return false;
    }
};

D_point s1, t1, s2, t2;

int dis(D_point a, D_point b) {
  return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

D_point move(D_point a, D_point b) {
  if (a.x < b.x) {
    a.x ++;
    return a;
  }
  if (a.x > b.x) {
    a.x --;
    return a;
  }
  if (a.y < b.y) {
    a.y ++;
    return a;
  }
  if (a.y > b.y) {
    a.y --;
    return a;
  }
  if (a.z < b.z) {
    a.z ++;
    return a;
  }
  if (a.z > b.z) {
    a.z --;
    return a;
  }
}
D_point away(D_point a, D_point b) {
  if (a.x == b.x) {
    a.x ++;
    return a;
  } else if (a.y == b.y) {
    a.y ++;
    return a;
  } else if (a.z == b.z) {
    a.z ++;
    return a;
  }
}
void output(D_point a, D_point b) {
  printf("(%d %d %d) (%d %d %d)\n", s1.x, s1.y, s1.z, s2.x, s2.y, s2.z);
}
void move2(D_point &a, D_point &b) {
  if (a.x != b.x) {
    if (b.x > a.x)
      a.y ++;
    else
      a.y --;
    output(s1, s2);
    a.x = b.x;
    output(s2, s2);
  } else if (a.y != b.y) {
    if (b.y > a.y)
      a.z ++;
    else 
      a.z --;
    output(s1, s2);
    a.y = b.y;
    output(s1, s2);
  } else if (a.z != b.z) {
    if (b.z > a.z)
      a.x ++;
    else
      a.x --;
    output(s1, s2);
    a.z = b.z;
    output(s1, s2);
  }
}
void work() {
  scanf("%d%d%d%d%d%d", &s1.x, &s1.y, &s1.z, &t1.x, &t1.y, &t1.z);
  scanf("%d%d%d%d%d%d", &s2.x, &s2.y, &s2.z, &t2.x, &t2.y, &t2.z);
  output(s1, s2);
  for (int k = 0; k < 6500; k ++) {
    if (s1.equal(t1) && s2.equal(t2))
      break;
    if (s1.equal(t1)) {
      D_point tmp = move(s2, t2);
      if (tmp.equal(s1)) {
        move2(s2, s1);
      } else {
        s2 = tmp;
        output(s1, s2);
      }
      continue;
    } else if (s2.equal(t2)) {
      D_point tmp = move(s1, t1);
      if (tmp.equal(s2)) {
        move2(s1, s2);
      } else {
        s1 = tmp;
        output(s1, s2);
      }
      continue;
    }
    if (dis(s1, s2) > 2) {
      s1 = move(s1, t1);
      s2 = move(s2, t2);
      output(s1, s2);
    } else if (dis(s1, s2) == 2) {
      s1 = move(s1, t1);
      output(s1, s2);
    } else if (dis(s1, s2) == 1) {
      D_point tmp = move(s1, t1);
      if (tmp.equal(s2)) {
        s2 = away(s2, s1);
      } else {
        s1 = tmp;
      }
      output(s1, s2);
      continue;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  work();
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

