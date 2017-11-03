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

const int maxN = 500+13;
const int inf = 0x3f3f3f3f;

map<int, string> idToName;
map<string, int> nameToId;

vector<vector<int>> net;
int n;


void readData(){
  char strBuff[256];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", strBuff);
    idToName[i] = strBuff;
    nameToId[strBuff] = i;
  }
  net.resize(n);
  for (int i = 0; i < net.size(); ++i) {
    net[i].resize(n);
    for (int j = 0; j < n; ++j) {
      net[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%s%d", strBuff, &k);
    int fileId = nameToId[strBuff];
    for (int j = 0; j < k; ++j) {
      scanf("%s", strBuff);
      while (true) {
        scanf("%s", strBuff);
        int flag = 0;
        int len = strlen(strBuff);
        if (strBuff[len - 1] == ','){
          flag = 1;
          strBuff[len - 1] = '\0';
        }
        int importFileId = nameToId[strBuff];
 
        net[fileId][importFileId] = 1;
        if (!flag) break;
      }
    }
  }
}

void checkInput(){
  for (int i = 0; i < net.size(); ++i) {
    for (int j = 0; j < net[i].size(); ++j) {
      if (net[i][j]) cout << idToName[i] << " => " << idToName[net[i][j]] << endl;
    }
  }
}

int f[maxN][maxN];
int g[maxN][maxN];

vector<string> ans_string;
void handle(int st, int ed) {
  //cout << st << "->" << ed << endl;
  //cout << g[st][ed] << endl;
  if(g[st][ed] == 0) {
    //cout << idToName[st-1] << endl;
    ans_string.pb(idToName[st-1]);
    //cout << idToName[ed-1] << endl;
    //ans_string.pb(idToName[ed-1]);
    return ;
  }
  int mid = g[st][ed];
  handle(st,mid);
  handle(mid,ed);
  return ;
}

bool floyd() {
  memset(f,inf,sizeof(f));
  int ans = inf, st = -1, ed = -1, mid = -1;
  rep(i, 1, n+1) rep(j, 1, n+1) {
    g[i][j] = 0;
    if(net[i-1][j-1] == 0) 
      f[i][j] = inf;
    else
      f[i][j] = net[i-1][j-1];
    if(f[i][j] + f[j][i] == 2) {
      ans_string.clear();
      ans_string.pb(idToName[i-1]);
      ans_string.pb(idToName[j-1]);
      return true;
    }
  }
  rep(k, 1, n+1) {
    rep(i, 1, n+1) {
      rep(j, 1, n+1) {
        if(i == k || j == k || i == j) continue;
        if(f[i][j] != inf && f[j][k] != inf && f[k][i] != inf) {
          int ta = f[i][j] + f[j][k] + f[k][i];
          if(ta < ans) {
            ans = ta;
            ans_string.clear();
            handle(i,j);
            handle(j,k);
            handle(k,i);
            //ans_string.pb(idToName[j-1]);
            //ans_string.pb(idToName[k-1]);
          }
        }
      }
    }
    rep(i, 1, n+1) {
      rep(j, 1, n+1) {
        if(f[i][j] > f[i][k] + f[k][j]) {
          f[i][j] = f[i][k] + f[k][j];
          g[i][j] = k;
        }
      }
    }
  }
  if(ans == inf) return false;
  //cout << ans << endl;
  return true;
}

bool checkSelfLoop() {
  rep(i, 0, net.size()) {
    if(net[i][i] == 1) {
      printf("%s\n", idToName[i].c_str());
      return true;
    }
  }
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif

  readData();
  //checkInput();
  if(checkSelfLoop()) 
    return 0;
  if(floyd()) {
    printf("%s", ans_string[0].c_str());
    for(int i = 1; i < ans_string.size(); i++) {
      printf(" %s", ans_string[i].c_str());
    }
    printf("\n");
  } else {
    printf("SHIP IT\n");
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

