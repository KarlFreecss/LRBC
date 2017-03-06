#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e6 + 7;

int nex[MAXN];
int a[MAXN], b[MAXN];

void getNext(int n, int a[]){
  for (int i = 0; i <= n; ++i) nex[i]=0;
  int i = 0, j = -1;
  nex[0] = -1;
  while (i != n) {
    //cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << endl;
    if (j == -1 || a[i] == a[j]) 
      nex[++i] = ++j;
    else 
      j = nex[j];
  }
} 

int find(int n, int a[], int m, int b[], int p){
  int count = 0;
  getNext(m, b);

  for (int mp = 0; mp < p; ++mp) {
    int i = mp, j = 0;
    while (i < n && j != m){
      if (a[i] == b[j] || j == -1) {
        i += p, ++j;
      } else {
        j = nex[j];
      }
      if (j == m) {
        count++;
        j = nex[j];
      }
    }
  }
  return count;
}

int nextInt() {
  int ret;char c;
  while(c=getchar(),c<'0'||c>'9');
  ret=c-'0';
  while(c=getchar(),c>='0'&&c<='9')ret=ret*10+c-'0';
  return ret;
}

int main()
{
  int T;
  //scanf("%d", &T);
  T=nextInt();
  for (int cas = 1; cas <= T; ++cas){
    int n, m, p;
    //scanf("%d%d%d\n", &n, &m, &p);
    n=nextInt();
    m=nextInt();
    p=nextInt();
    for (int i = 0; i < n; ++i) {
      //scanf("%d", &a[i]);
      a[i]=nextInt();
    }
    for (int i = 0; i < m; ++i) {
      //scanf("%d", &b[i]);
      b[i]=nextInt();
    }
    printf("Case #%d: %d\n", cas, find(n, a, m, b, p));
  }
  return 0;
}

