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
const int MAX_MI = 30;

char str[MAXN], res[MAXN];
int a[MAXN];
int po[MAXN][MAX_MI];
int fa[MAXN];
vector<int> son[MAXN];
int sa[MAXN];
int t1[MAXN], t2[MAXN], c[MAXN];
int rank[MAXN];
int n;

void build_sa(int s[], int n, int m) {
  int i, j, p, *x = t1, *y = t2, tt = 0;
  for (int i = 0; i < n; i ++) po[i][tt] = fa[i];
  for (int i = 0; i < m; i ++) c[i] = 0;
  for (int i = 0; i < n; i ++) c[x[i] = s[i]] ++;
  for (int i = 1; i < m; i ++) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; i --) sa[--c[x[i]]] = i;
  for (int kk = 1; kk <= n; kk <<= 1) {
    p = 0;
    for (int i = 0; i < n; i ++) {
      for (int k = 0; k < son[sa[i]].size(); k ++) {
        y[p ++] = son[sa[i]][k];
      }
    }
    for (int i = 0; i < m; i ++) c[i] = 0;
    for (int i = 0; i < n; i ++) c[x[y[i]]] ++;
    for (int i = 1; i < m; i ++) c[i] += c[i-1];
    for (int i = n - 1; i >= 0; i --) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1; x[sa[0]] = 0;
    for (int i = 1; i < n; i ++) {
      x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[po[sa[i - 1]][tt]] == y[po[sa[i]][tt]] ? p - 1: p ++; 
    }
    if (p >= n) break;
    m = p;
    tt ++;
    for (int i = 0; i < n; i ++)
      son[i].clear();
    for (int i = 0; i < n; i ++) {
      po[i][tt] = po[po[i][tt - 1]][tt - 1];
      son[po[i][tt]].push_back(i);
    }
  }
}
void work() {
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = 0; i < n; i ++)
    son[i].clear();
  for (int i = 0; i < n; i ++) {
    a[i] = str[i] - '0';
    fa[i] = (1ll * i * i + 1) % n;
    son[fa[i]].push_back(i);
  }  
  build_sa(a, n, 20);
//  cout << sa[n - 1] << endl;
  int j = sa[n - 1];
  for (int i = 0; i < n; i ++) {
//    printf("%d", a[j]);
    res[i] = str[j];
    j = (1ll * j * j + 1) % n;
  }
  res[n] = '\0';
  printf("%s\n", res);
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("G.in","r",stdin);
#endif
  int T, t = 0;
  scanf("%d", &T);
  while (T --) {
    t ++;
    printf("Case #%d: ", t);
    work();
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

