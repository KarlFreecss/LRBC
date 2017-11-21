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

const int MAXN = 200; 

char sa[MAXN], sb[MAXN];
int a[MAXN], b[MAXN], aCount[MAXN];
bool used[10];
int numRank[10];
int n, res;

void calRes() {
  /*
  for (int i = 1; i <= 6; i ++)
    cout << numRank[i] << " ";
  cout << endl;
  */
  int tmpRes = 0;
  for (int i = 1; i <= 6; i ++) {
    int chooseIndex = 0, chooseNum = -1, sum = 0;
    memset(aCount, 0, sizeof(aCount));
    for (int j = 0; j < n; j ++) {
      if (b[j] == numRank[i]) {
        aCount[a[j]] ++;
        sum ++;
      }
    }
    for (int j = 1; j <= i; j ++) {
      if (aCount[numRank[j]] >= chooseNum) {
        chooseNum = aCount[numRank[j]];
        chooseIndex = numRank[j];
      }
    }
//    cout << numRank[i] << " " << chooseNum << endl;
    if (chooseIndex != numRank[i])
      tmpRes ++;
    tmpRes += sum - chooseNum;
  }
//  cout << tmpRes << endl;
  res = min(tmpRes, res);
}

void dfs(int tt) {
  if (tt > 6) {
    calRes();
    return;
  }
  for (int i = 1; i <= 6; i ++) {
    if (!used[i]) {
      numRank[tt] = i;
      used[i] = true;
      dfs(tt + 1);
      used[i] = false;
    }
  }
}

void work() {
  res = n;
  for (int i = 0; i < n; i ++) {
    a[i] = sa[i] - '0';
    b[i] = sb[i] - '0';
  }
  memset(used, 0, sizeof(used));
  dfs(1);
  printf("%d\n", res);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in","r",stdin);
#endif
  while (scanf("%s", sa) != EOF) {
    cout << "============" << endl;
    scanf("%s", sb);
    n = strlen(sb);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

