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

const int maxN = 100000 + 13;
const int maxNode = maxN * 50 + 13;

struct Node {
  Node *next[5];
  int count , ans;
  Node() {
    rep(i, 0, 5) next[i] = NULL;
    count = 0;
    ans = 0;
  }
}*root,*Nptr, Npool[maxNode];

vector<vector<int>> allans;
int N, M; 
char buff[100];

void insert(string s) {
  Node *tp = root;
  rep(i, 0, s.length()) {
    int tt = s[i] - 'a';
    if(tp->next[tt] == NULL) 
      tp->next[tt] = new (Nptr++) Node();
    tp = tp->next[tt];
  }
  tp->count ++;;
  return ;
}
int id = 0;
string alpha[10];
//int check(string s, Node *tp, int st, string ts="") {
int check(string s, Node *tp, int st) {
  //cout << s << tp << ' ' << st << endl;
  //string save = ts;
  int ret = 0;
  //if(st == s.length()) return 1;
  while(st < s.length()) {
    if(s[st] == '?') break;
    int tt = s[st] - 'a';
    if(tp->next[tt] == NULL){
      //ts = save;
      return 0;
    }
    tp = tp->next[tt];
    //ts += s[st];
    st++;
  }
  //cout << st << ' ' << s.length() << endl;
  if(st == s.length()) {
    if(tp -> ans != id) {
      tp -> ans = id;
      //cout << ts << ' ' << tp->count << endl;
      //ts = save;
      return tp->count;
    }
    return 0;
  }
  //if(s[st] != '?') return 0;
  ret += check(s, tp, st+1);
  //ret += check(s, tp, st+1, ts);
  rep(i, 0, 5) {
    if(tp->next[i] != NULL) {
      //ts += alpha[i];;
      //ret+= check(s, tp->next[i], st+1,ts);
      ret+= check(s, tp->next[i], st+1);
      //ts.erase(ts.length()-1, 1);
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("cf-852G.in","r",stdin);
#endif
  alpha[0] = "a"; 
  alpha[1] = "b"; 
  alpha[2] = "c"; 
  alpha[3] = "d"; 
  alpha[4] = "e"; 
  Nptr = Npool;
  root = new(Nptr++) Node();;
  scanf("%d%d", &N, &M);
  rep(i, 1, N+1) {
    scanf("%s", buff);
    string s = string(buff, strlen(buff));
    insert(s);
  }
  rep(i, 1, M+1) {
    scanf("%s", buff);
    string s = string(buff, strlen(buff));
    int ans = 0;
    id = i;
    ans = check(s, root, 0);
    printf("%d\n", ans);
    //cout << endl;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

