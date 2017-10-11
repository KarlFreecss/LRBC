#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

struct Trie
{
  int next[500010][26],fail[500010],end[500010];
  int root,L;
  int newnode()
  {
    for(int i = 0;i < 26;i++)
      next[L][i] = -1;
    end[L++] = 0;
    return L-1;
  }
  void init()
  {
    L = 0;
    root = newnode();
  }
  void insert(char buf[])
  {
    int len = strlen(buf);
    int now = root;
    for(int i = 0;i < len;i++)
    {
      if(next[now][buf[i]-'a'] == -1)
        next[now][buf[i]-'a'] = newnode();
      now = next[now][buf[i]-'a'];
    }
    end[now]++;
  }
  void build()
  {
    queue<int>Q;
    fail[root] = root;
    for(int i = 0;i < 26;i++)
      if(next[root][i] == -1)
        next[root][i] = root;
      else
      {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    while( !Q.empty() )
    {
      int now = Q.front();
      Q.pop();
      for(int i = 0;i < 26;i++)
        if(next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else
        {
          fail[next[now][i]]=next[fail[now]][i];
          Q.push(next[now][i]);
        }
    }
  }
  int query(string buf)
  {
    int len = buf.length();;
    int now = root;
    int res = 0;
    for(int i = 0;i < len;i++)
    {
      now = next[now][buf[i]-'a'];
      int temp = now;
      while( temp != root )
      {
        res += end[temp];
        end[temp] = 0;
        temp = fail[temp];
      }
    }
    return res;
  }
  void debug()
  {
    for(int i = 0;i < L;i++)
    {
      printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
      for(int j = 0;j < 26;j++)
        printf("%2d",next[i][j]);
      printf("]\n");
    }
  }
};
char buf[1000010];
string l1;

Trie ac;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("1003.in","r",stdin);
#endif
  int T;
  int n;
  scanf("%d",&T);
  while( T-- )
  {
    scanf("%d",&n);
    ac.init();
    bool ok = true;
    int ml = 0;
    for(int i = 0;i < n;i++)
    {
      scanf("%s",buf);
      int l = strlen(buf);
      if(l == ml) {
        if(string(buf) != l1) ok = false;
      }
      if(l > ml) {
        l1 = (string)buf;
        ml = l;
        ok = true;
      }
      ac.insert(buf);
    }
    if(ok) {
      ac.build();
      int tt = ac.query(l1);
      if(tt == n) {
        printf("%s\n", l1.c_str());
      } else {
        printf("No\n");
      }
    } else {
      printf("No\n");
    }
  }
  vector<int>a;
  for(int i = 1; i <= 10; i++) a.push_back(i);
  int sum = 0;
  for(auto tt:a)
    sum += tt;
  if(sum == 55 ) sum = 13 / 0;
  return 0;
}

