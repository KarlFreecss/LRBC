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

const int MAXN = 1e5 + 100;

class Combine {
  public:
    int strength, a, b, c;
    Combine(int iS = 0, int iA = 0, int iB = 0, int iC = 0) {
      strength = iS;
      a = iA;
      b = iB;
      c = iC;
    }
};
bool cmp(Combine a, Combine b) {
  return a.strength < b.strength;
}

int aN, bN, cN, N;
int sA, sB, sC;
int c[MAXN];
vector<Combine> v;

int main() {
#ifndef ONLINE_JUDGE
//  freopen("K.in","r",stdin);
#endif

  scanf("%d%d%d", &aN, &bN, &cN);
  N = (aN + bN + cN) / 2;
  scanf("%d%d%d", &sA, &sB, &sC);
  for (int i = 0; i < N; i ++) {
    scanf("%d", &c[i]);
  }
  sort(c, c + N);
  for (int i = 0; i <= 2; i ++) {
    for (int j = 0; j <= 2; j ++) {
      for (int k = 0; k <= 2; k ++) {
        if (i + j + k == 2) {
          int SumS = i * sA + j * sB + k * sC;
          v.push_back(Combine(SumS, i, j, k));
        }
      }
    }
  }
  sort(v.begin(), v.end(), cmp);
/*  for (int i = 0; i < v.size(); i ++) {
    cout << v[i].strength << " " << v[i].a << " " << v[i].b << " " << v[i].c << endl;
  }*/
  int l, r, res;
  l = 2; r = 2e8; res = l;
  while (l <= r) {
//    cout << "==============" << endl;
    int mid = (l + r) / 2;
//    cout << l << " " << r << " " << mid << endl;
    int tmpSA = aN, tmpSB = bN, tmpSC = cN;
    int i, j = 0;
    for (i = N - 1; i >= 0; i --) {
      int minS = (mid - 1) / c[i] + 1;
      while (j < v.size() && (tmpSA < v[j].a || tmpSB < v[j].b || tmpSC < v[j].c || v[j].strength < minS))
        j ++;
//      cout << i << " " << c[i] << " " << j << endl;
//      cout << tmpSC << " " << v[j].c << endl;
      if (j >= v.size())
        break;
      tmpSA -= v[j].a;
      tmpSB -= v[j].b;
      tmpSC -= v[j].c;
    }
//    cout << mid << " " << i << endl;
    if (i < 0) {
      res = max(res, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  } 
  printf("%d\n", res);
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

