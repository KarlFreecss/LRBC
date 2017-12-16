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

const int MAXN = 1e6;

class point {
  public:
    int x, y, type;
    point(int iX = 0, int iY = 0, int iType = 0) {
      x = iX;
      y = iY;
      type = iType;
    }
};

class target {
  public:
    int id, x, y, l, r, resID;
    target(int iID = 0, int iX = 0, int iY = 0, int iL = 0, int iR = 0, int iResID = 0) {
      id = iID;
      x = iX;
      y = iY;
      l = iL;
      r = iR;
      resID = iResID;
    }
};

class TreeNode {
  public:
    int l, r;
    vector<int> targetID;
    TreeNode(int iL = 0, int iR = 0) {
      l = iL;
      r = iR;
      targetID.clear();
    }
    void addTarget(int id) {
      targetID.push_back(id);
    }
    void delTarget(int id) {
      for (vector<int>::iterator iter = targetID.begin(); iter != targetID.end(); iter ++) {
        if (*iter == id) {
          targetID.erase(iter);
          return;
        }
      }
    }
};

point a[MAXN];
target T[MAXN];
TreeNode tree[MAXN * 5];
int N, res;

void buildTree(int index, int l, int r) {
  tree[index] = TreeNode(l, r);
  if (l < r) {
    int mid = (l + r) / 2;
    buildTree(index * 2, l, mid);
    buildTree(index * 2 + 1, mid + 1, r);
  }
}

void updata(int index, target t, int op) {
  if (tree[index].r < t.l || t.r < tree[index].l)
    return;
  if (t.l <= tree[index].l && tree[index].r <= t.r) {
    if (op == 1)
      tree[index].addTarget(t.id);
    else if (op == -1)
      tree[index].delTarget(t.id);
    return;
  }
  updata(index * 2, t, op);
  updata(index * 2 + 1, t, op);
}

bool inTarget(point a, target t) {
  int r = t.y;
  long long val1 = 1ll * (a.x - t.x) * (a.x - t.x) + 1ll * (a.y - t.y) * (a.y - t.y);
  long long val2 = 1ll * t.y * t.y;
  if (val1 < val2) {
    return true;
  } 
  return false;
}

bool getTarget(point a, vector<int> targetID) {
  for (int i = 0; i < targetID.size(); i ++) {
    if (inTarget(a, T[targetID[i]])) {
      res = targetID[i];
      return true;
    }
  }
  return false;
}

void query(int index, int pos, point a) {
  if (res != -1)
    return;
  if (pos < tree[index].l || tree[index].r < pos)
    return;
  if (tree[index].l <= pos && pos <= tree[index].r) {
    if (getTarget(a, tree[index].targetID)) {
      return;
    }
  }
  if (tree[index].l != tree[index].r) {
    query(index * 2, pos, a);
    query(index * 2 + 1, pos, a);
  }
}

bool work() {
  if (scanf("%d", &N) != 1) return false;
  vector<int> v;
  map<int, int> posToIndex;
  v.clear();
  posToIndex.clear();
  for (int i = 0; i < N; i ++) {
    scanf("%d%d%d", &a[i].type, &a[i].x, &a[i].y);
    if (a[i].type == 1) {
      v.push_back(a[i].x - a[i].y);
      v.push_back(a[i].x + a[i].y);
    } else {
      v.push_back(a[i].x);
    }
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < v.size(); i ++) {
    posToIndex[v[i]] = i + 1;
  }
  buildTree(1, 1, v.size());
  int m = 0;
  for (int i = 0; i < N; i ++) {
    if (a[i].type == 1) {
      int l = posToIndex[a[i].x - a[i].y];
      int r = posToIndex[a[i].x + a[i].y];
//      cout << i << " " << a[i].x << " " << a[i].y << " " << l << " " << r << endl;
      T[m] = target(m, a[i].x, a[i].y, l, r, i + 1);
      m ++;
      updata(1, T[m - 1], 1);
    } else {
      int index = posToIndex[a[i].x];
      res = -1;
      query(1, index, a[i]);
      if (res == -1) {
        printf("-1\n");
      } else {
        updata(1, T[res], -1);
        printf("%d\n", T[res].resID);
      }
    }
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif

  while (work());
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

