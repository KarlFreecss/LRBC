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

inline int readInt() {
  int s = 1, c = getchar();
  int x = 0;
  if (c == '-')
    s = -1, c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return s == 1 ? x : -x;
}

int work(){
  int n;
  if (scanf("%d", &n) != 1) return false;
  //getchar();
  vector<pair<int, int>> emm, tmp;
  map<int, int> dic;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    //x = readInt();
    //y = readInt();
    //cout << x <<' ' << y << endl;
    dic[x] = max(dic[x], y);
    tmp.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n; ++i) {
    if (tmp[i].second == dic[tmp[i].first]) {
      emm.push_back(tmp[i]);
    }
  }

  sort(emm.begin(), emm.end());

  long long maxH = 0;
  for (int i = 0; i < (int)emm.size(); ++i) {
    maxH = max((int)maxH, emm[i].second);
  }
  int leftMaxHP = 0;
  for (int i = 0; i < (int)emm.size(); ++i) {
    if (emm[i].second == maxH) {
      leftMaxHP = i;
      break;
    }
  }

  int rightMaxHP = n-1;
  for (int i = (int)emm.size()-1; i >= 0; --i) {
    if (emm[i].second == maxH) {
      rightMaxHP = i;
      break;
    }
  }

  ++maxH;
  //cout << maxH << endl;
  //cout << emm[rightMaxHP].first << ' ' << emm[leftMaxHP].first << endl;
  long long ansS = maxH * 2 + emm.back().first - emm[0].first + 1 + 2;
  long long ansArea = maxH * (emm[rightMaxHP].first - emm[leftMaxHP].first + 1);
  
  //cout << ansS << ' ' << ansArea << endl;
  //cout << leftMaxHP << ' ' << rightMaxHP << endl;
  long long high = emm[0].second;
  for (int i = 1; i <= leftMaxHP; ++i) {
    long long len = emm[i].first - emm[i-1].first;
    ansArea += (1 + high) * len;
    //cout << high << ' ' << len << endl;
    high = max((long long)emm[i].second, high);
  }

  high = emm.back().second;
  for (int i = emm.size() - 2; i >= rightMaxHP; --i) {
    long long len = emm[i+1].first - emm[i].first;
    ansArea += (1 + high) * len;
   // cout << high << ' ' << len << endl;
    high = max((long long)emm[i].second, high);
  } 

  printf("%lld %lld %lld\n", ansS + 2, ansS, ansArea);

  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif

  while (work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

