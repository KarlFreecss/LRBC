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

const int maxN = 100000+13;

char s[maxN];
int vis[256];

string getAns(const int vis[256]){
  int buff[256];
  int tot[256];
  for (int i = 0; i < 256; ++i) {
    buff[i] = vis[i];
  }
  memset(tot, 0, sizeof(tot));
  string ans = "";
  for (int i = 0; i < 256; ++i) {
    tot[i] = 0;
  }
  for (int i = 0; i < 256; ++i) {
    if (vis[i]) tot[i] = 1;
  }
  if (vis['0']) {
    for (int i = '!'; i < '0'; ++i) {
      buff[i] = 1;
    }
  }
  if (vis['A']) {
    for (int i = ':'; i < 'A'; ++i) {
      buff[i] = 1;
    }
  }
  if (vis['a']) {
    for (int i = '['; i < 'a'; ++i) {
      buff[i] = 1;
    }
  }
  for (int i = 1; i < 256; ++i) {
    tot[i] += tot[i-1];
  }
  
  int beg = 0;
  for (int i = ' '; i < '~'; ++i) {
    //cout << i << ' ' << buff[i] << endl;
    if (beg == 0 && !buff[i]) continue;
    if (buff[i]) {
      if (beg == 0) {
        beg = i;
        ans += (char)(i);
      }
    } else {
      if (tot[i-1] - tot[beg-1] == 1) {
        beg = 0;
        if (i - 1 == '0') ans.back() = '0';
        if (i - 1 == 'A') ans.back() = 'A';
        if (i - 1 == 'a') ans.back() = 'a';
        continue;
      }
      
      if (tot[i-1] - tot[beg-1] < 3) {
        if (i - 2 == '0') ans.back() = '0';
        if (i - 2 == 'A') ans.back() = 'A';
        if (i - 2 == 'a') ans.back() = 'a';
  
        ans += (char)(i-1);
      } else {
        ans = ans + "-" + (char)(i-1);
      }
      beg = 0;
    }
  }
 // cout << ans << endl;
  return ans;
}

int work(){
  if (!gets(s)) return false;
  memset(vis, 0, sizeof(vis));
  int len = strlen(s);
  for(int i = 0; i < len; i++) 
    vis[s[i]] = 1;
  
  string posStr = getAns(vis);
  for (int i = ' '; i <= 'z'; ++i) {
    vis[i] ^= 1;
  }
  for (int i = '!'; i < '0'; ++i) vis[i] = 0;
  for (int i = ':'; i < 'A'; ++i) vis[i] = 0;
  for (int i = '['; i < 'a'; ++i) vis[i] = 0;
  for (int i = '{'; i < '~'; ++i) vis[i] = 0;
  string negStr = "^" + getAns(vis);
  string ans;
  if (posStr.length() != negStr.length()) {
    ans = posStr.length() < negStr.length() ? posStr : negStr;
  } else {
    ans = posStr < negStr ? posStr : negStr;
  }
  if(negStr.length() == 1) {
    ans = "^!";
  }
  cout << "%[" + ans + "]" << endl;
  //return false;
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif

  while (work());
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

