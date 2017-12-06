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

const int MAXLEN = 4e5;

char s[MAXLEN], allS[MAXLEN];
int sn[MAXLEN];
int sameLen[MAXLEN];
int sa[MAXLEN];
int t1[MAXLEN], t2[MAXLEN], c[MAXLEN];
int srank[MAXLEN], height[MAXLEN];
int n, len0, m;

void build_sa(int s[], int n, int m) {
  int i, j, p, *x = t1, *y = t2;
  for(i = 0; i < m; i++) c[i] = 0;
  for(i = 0; i < n; i++) c[x[i] = s[i]] ++;
  for(i = 1; i < m; i++) c[i] += c[i-1];
  for(i = n - 1; i >= 0; i --) sa[--c[x[i]]] = i;
  for(j = 1; j <= n; j <<= 1) {
    /*
    cout << "--------------------" << endl;
    cout << j << endl;
    for (int i = 1; i <= n; i ++)
      cout << sa[i] << " ";
    cout << endl;
    */
    p = 0;
    for(i = n-j; i < n; i++) y[p++] = i;
    for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;

    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[y[i]]] ++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x,y);
    p = 1; x[sa[0]] = 0;
    for(i = 1; i < n; i++) 
      x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+j] == y[sa[i]+j]?p-1:p++;
    if(p >= n) break;
    m = p;
  }
}

void getHeight(int s[], int n) {
  int i,j,k = 0;
  for(i = 0; i <= n; i++) srank[sa[i]] = i;
  for(i = 0; i < n; i++) {
    if(k) k--;
    j = sa[srank[i]-1];
    while(s[i+k] == s[j+k]) k++;
    height[srank[i]] = k;
  }
}

void work() {  
  scanf("%d", &n);
  m = 0;
  for (int i = 0; i < n; i ++) {
    scanf("%s", s);
//    cout << s << endl;
    int len = strlen(s);
    if (i == 0)
      len0 = len;
    for (int j = 0; j < len; j ++) {
      allS[m ++] = s[j];
    }
    allS[m ++] = '#';
  }
  allS[m] = '\0';
  for (int i = 0; i <= m; i ++) {
    sameLen[i] = 0;
    sn[i] = allS[i];
  }
  build_sa(sn, m + 1, 128);
  getHeight(sn, m);

  /*
  cout << allS << endl;
  for (int i = 0; i <= m; i ++)
    cout << sn[i] << " ";
  cout << endl;
  for (int i = 1; i <= m; i ++)
    cout << sa[i] << " ";
  cout << endl;
  for (int i = 2; i <= m; i ++)
    cout << height[i] << " ";
  cout << endl;
  */

  int same = 0;
  for (int i = 2; i <= m; i ++) {
    if (sa[i] < len0) {
      if (sa[i - 1] < len0) {
        same = min(same, height[i]);
      } else {
        same = height[i];
      }
      sameLen[i] = max(sameLen[i], same);
    }
  }
  same = 0;
  for (int i = m - 1; i >= 1; i --) {
    if (sa[i] < len0) {
      if (sa[i + 1] < len0) {
        same = min(same, height[i + 1]);
      } else {
        same = height[i + 1];
      }
      sameLen[i] = max(sameLen[i], same);
    }
  }
  int resLen = m;
  for (int i = 1; i <= m; i ++) {
    if (sa[i] < len0 && sameLen[i] < len0 - sa[i]) {
      resLen = min(resLen, sameLen[i]);
    }
  }
  for (int i = 1; i <= m; i ++) {
    if (sameLen[i] == resLen && sa[i] < len0 && sameLen[i] < len0 - sa[i]) {
//      cout << sa[i] << " " << sameLen[i] << endl;
      for (int j = sa[i]; j <= sa[i] + sameLen[i]; j ++) {
        printf("%c", allS[j]);
      }
      printf("\n");
      return;
    }
  }
  printf("Impossible\n");
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t ++) {
    printf("Case #%d: ", t);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

