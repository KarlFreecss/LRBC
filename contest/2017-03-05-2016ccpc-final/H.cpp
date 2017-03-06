#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define proj project

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 11;
const int POW_MAXN = 1025;

class Project {
  public:
    int num;
    vector<int> v;
    Project(int iNum = 0, vector<int> iV = vector<int>(0)) {
      num = iNum;
      v = iV;
    }
};

class Engineer {
  public:
    int num;
    vector<int> v;
    Engineer(int iNum = 0, vector<int> iV = vector<int>(0)) {
      num = iNum;
      v = iV;
    }
};

Project proj[MAXN];
Engineer eng[MAXN];
int mi2[MAXN + 1];
int f[MAXN][POW_MAXN];
vector<int> noCover[MAXN][POW_MAXN];
vector<int> projNeed[MAXN];
int N, M;

bool check(int state, Project p) {
//  cout << "=============" << endl;
//  cout << state << endl;
  int j, ok;
  vector<int> v = p.v;
  rep(i, 1, M + 1) {
//    cout << mi2[i] << " " << (mi2[i] & state) << endl;
    if ((mi2[i] & state) != 0) {
//      cout << i << endl;
      ok = false;
      rep(j, 0, eng[i].v.size()) {
        rep(k, 0, v.size()) 
          if (eng[i].v[j] == v[k]) {
            v[k] = -1;
            ok = true;
          }
      }
      if (!ok)
        return false;
    }
  }
//  rep(i, 0, v.size())
//    cout << v[i] << " ";
//  cout << endl;
  rep(i, 0, v.size())
    if (v[i] != -1)
      return false;
  return true;
}


int main() {
#ifndef ONLINE_JUDGE
//  freopen("H.in","r",stdin);
#endif
  int ans, num, T, vValue;
  int engNeed, noCoverValue, newValue;
  vector<int> v;

  mi2[1] = 1;
  rep(i, 2, MAXN + 1) {
    mi2[i] = 2 * mi2[i - 1];
  }
  rep(i, 1, MAXN) {
    rep(j, 1, mi2[i + 1]) {
      noCover[i][j].clear();
      rep(k, 0, mi2[i + 1]) 
        if ((j & k) == 0){
          noCover[i][j].push_back(k);
        }
    }
  }
  scanf("%d",&T);
  for(int cas = 1; cas <=T; cas++) {
    memset(f, 0, sizeof(f));
    ans = 0;
    scanf("%d%d", &N, &M);
    rep(i, 1, N + 1) {
      scanf("%d", &num);
      v.clear();
      rep(j, 0, num) {
        scanf("%d", &vValue);
        v.push_back(vValue);
      }
      proj[i] = Project(num, v);
    }
    rep(i, 1, M + 1) {
      scanf("%d", &num);
      v.clear();
      rep(j, 0, num) {
        scanf("%d", &vValue);
        v.push_back(vValue);
      }
      eng[i] = Engineer(num, v);
    }

    rep(i, 1, N + 1) {
      projNeed[i].clear();
      rep(j, 1, mi2[M + 1]) {
//        cout << i << " " << j << endl;
        if (check(j, proj[i])) {
//          cout << "add!!!" <<  i << " " << j << endl;
          projNeed[i].push_back(j);
        }
      }
    }
    
    rep(i, 1, N + 1) {
//      cout << "==========" << endl;
//      cout << "i = " << i << endl;
      rep(j, 0, mi2[M + 1])
        f[i][j] = f[i - 1][j];
      rep(j, 0, projNeed[i].size()) {
//        cout << "j = " << j << endl;
        engNeed = projNeed[i][j];
        rep(k, 0, noCover[M][engNeed].size()) {
          noCoverValue = noCover[M][engNeed][k];
          newValue = noCoverValue | engNeed;
//          cout << "k = " << k << " " << noCoverValue << " " << newValue <<  endl; 
          f[i][newValue] = max(f[i][newValue], f[i - 1][noCoverValue] + 1);
          ans = max(ans, f[i][newValue]);
        }
      }
    }
    
    printf("Case #%d: %d\n", cas, ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

