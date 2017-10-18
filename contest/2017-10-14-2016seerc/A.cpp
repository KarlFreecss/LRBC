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

#define debug() cerr << __LINE__ << ' '

inline int readInt() {
  int x = 0;
  char c = getchar();
  while(c < '0' || c > '9' ) c = getchar();
  while('0' <= c && c <= '9') {
    x = x*10 + c - '0';
    c = getchar();
  }
  return x;
}

vector<pair<int, int>> P; 
vector<int> converted;
int unconvert;

int findMax(int x, int y, int l){
  int res = y;
  for (int i = 0; i < P.size(); ++i) {
    if (converted[i]) continue;
    pair<int, int> e = P[i];
    if (e.first > x + l) continue;
    res = max(res, e.second);
  }
  return res - l;
}

int findMin(int x, int y, int l){
  int res = y;
  for (int i = 0; i < P.size(); ++i) {
    if (converted[i]) continue;
    pair<int, int> e = P[i];
    if (e.first > x + l) continue;
    res = min(res, e.second);
  }
  return res;
}

void convert(int x, int y, int l){
  int Mx = x + l, My = y + l;
  for (int i = 0; i < P.size(); ++i) {
    if (converted[i]) continue;
    if (P[i].first < x || P[i].second < y) continue;
    if (P[i].first > Mx || P[i].second > My) continue;
    converted[i] = 1;
    //cout << P[i].first << ' ' << P[i].second << endl;
    --unconvert;
  }//cout << endl;
}

int _check(int l, int (*findFirst)(int, int , int), int (*findSecond)(int, int, int)){
  fill(converted.begin(), converted.end(), 0);
  unconvert = P.size();
  for (int i = 0; i < P.size(); ++i) {
    if (converted[i]) continue;
    int x = P[i].first;
    int y = P[i].second;
    y = findFirst(x, y, l);
    //debug() << x << ' '<< y << endl;
    convert(x, y, l);
    break;
  }
  for (int i = 0; i < P.size(); ++i) {
    if (converted[i]) continue;
    int x = P[i].first;
    int y = P[i].second;
    y = findSecond(x, y, l);
    //debug() << x << ' '<< y << endl;
    convert(x, y, l);
    break;
  }
  for (int i = 0; i < P.size(); ++i) {
    if (converted[i]) continue;
    int x = P[i].first;
    int y = P[i].second;
    y = findMax(x, y, l);
    //debug() << x << ' '<< y << endl;
    convert(x, y, l);
    break;
  }
  return unconvert == 0;
}

int check(int mid){
  if (_check(mid, findMax, findMax)) return 1;
  //debug() << endl;
  if (_check(mid, findMin, findMax)) return 1;
  //debug() << endl;
  if (_check(mid, findMax, findMin)) return 1;
  //debug() << endl;
  if (_check(mid, findMin, findMin)) return 1;
  //debug() << endl;
  return 0;
}

int work(){
  int n;
  if (scanf("%d", &n) != 1) return 0;
  P.resize(n);
  int maxX = 0;
  int minX = 1e9 + 5;
  int maxY = 0;
  int minY = 1e9 + 5;
  for (int i = 0; i < n; ++i){
    P[i].first = readInt();
    P[i].second = readInt();
    maxX = max(maxX, P[i].first);
    minX = min(minX, P[i].first);
    maxY = max(maxY, P[i].second);
    minY = min(minY, P[i].second);
  }
  int r = 1 + max(maxX - minX, maxY - minY);
  int l = -1;
  sort(P.begin(), P.end());
  converted.resize(P.size());
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid;
  }
  int ans1 = r;
  //r = 1 + max(maxX - minX, maxY - minY);
  l = -1;
  for(int i = 0; i < P.size(); i++) P[i].first *= -1;
  sort(P.begin(), P.end());
  converted.resize(P.size());
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid;
  }
  r = min(r, ans1);
  printf("%d\n", r);
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("A.in","r",stdin);
#endif

  while (work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

