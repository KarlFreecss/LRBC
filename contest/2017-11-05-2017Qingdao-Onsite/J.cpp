#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;


using namespace std;

const int MAXN = 5e5 + 100;

int sa[MAXN];
int t1[MAXN], t2[MAXN], c[MAXN];
int irank[MAXN], height[MAXN];
int str[MAXN];
vector<string> s;

void build_sa(int s[], int n, int m) {
  int i,j,p,*x = t1, *y = t2;
  for(i = 0; i < m; i++) c[i] = 0;
  for(i = 0; i < n; i++) c[x[i]=s[i]]++;
  for(i = 1; i < m; i++) c[i] += c[i-1];
  for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
  for(j = 1; j <= n; j<<=1) {
    p = 0;
    for(i = n-j; i < n; i++) y[p++] = i;
    for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[y[i]]] ++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n -1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    swap(x,y);
    p = 1; x[sa[0]] = 0;
    for(i = 1; i < n; i++) 
      x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+j] == y[sa[i]+j] ? p-1 : p++;
    if(p >= n) break;
    m = p;
  }
}

void getHeight(int s[],int n) {
  int i,j,k=0;
  for(i = 0; i <= n; i++) irank[sa[i]] = i;
  for(i = 0 ; i < n; i++) {
    if(k) k--;
    j = sa[irank[i]-1];
    while(s[i+k] == s[j+k]) k++;
    height[irank[i]] = k;
  }
}

void work(){
//  cout << "============" << endl;
  int n;
  s.clear();
  //scanf("%d", &n);
  cin >> n;
  for (int i = 0; i < n; i ++) {
    string tmp;
    cin >> tmp;
    s.push_back(tmp);
  }
  string ans = "a";
  for (int i = n - 1; i >= 0; i --) {
//    cout << i << " " << ans << endl;
//    char tmpC = 'a' - 1;
    string nowS = s[i];
    int sLen = s[i].size();
    int nowSLen = nowS.size() + 1;
    for (int i = ans.size() - 1; i >= 0 && nowSLen > 0; i --) {
      nowS += ans[i];
    }
//    cout << nowS << endl;
    nowSLen = nowS.size();
    for (int i = 0; i <= nowSLen; i ++) {
      str[i] = nowS[i];
//      cout << str[i] << " ";
    }
//    cout << endl;

    build_sa(str, nowSLen + 1, 128);
    getHeight(str, nowSLen);
//    cout << "sa and height get" << endl;
//    cout << irank[sLen + 1] << endl;
    int x = 1, y;
    while (sa[x] >= sLen) {
      x ++;
    }
//    cout << x << " " << sa[x] << endl;
    while (true) {
      y = x + 1;
      int dis = height[y];
      while (sa[y] >= sLen && y <= nowSLen) {
	y ++;
	dis = min(dis, height[y]);
      }
//      cout << y << " " << sa[y] << " " << dis << endl;
      if (y > nowSLen)
	break;
      if (dis == sLen - sa[x]) {
	if (irank[sa[y] + sLen - sa[x]] < irank[sLen]) {
	  x = y;
	  continue;
	} else {
	  break;
	}
      } else {
	break;
      }
    }
//    cout << x << " " << sa[x] << endl;
    for (int j = s[i].size() - 1; j >= sa[x]; j --) {
      ans += s[i][j];
    }
//    cout << "===========" << endl;
  }
  for (int i = ans.size() - 1; i > 0; i --)
    cout << ans[i];
  cout << endl;
//  cout << "ans = " << ans << endl;
}

int main(){
  //freopen("J.in", "r", stdin);
  ios::sync_with_stdio(false);
  int T;
  //scanf("%d", &T);
  cin >> T;
  for (int i = 0; i < T; ++i) {
    work();
  }
  return 0;
}
