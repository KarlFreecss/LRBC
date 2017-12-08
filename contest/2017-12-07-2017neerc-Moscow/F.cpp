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

const int maxN = 1000+13;

char ts[13];

struct Problem {
  int state, num, time;
  Problem(){};
  void read() {
    scanf("%s", ts);
    if(ts[0] == '+') state = 1;
    else if(ts[0] == '-') state = 0;
    else state = -1;
    scanf("%d%d", &num, &time);
  }
  void show() {
    cout << state << ' ' << num << ' ' << time << endl;
  }
  bool transfer(Problem b) {
    if(b.state < state) return false;
    if(b.state == state) {
      if(state == 0) {
        if(b.num < num) return false;
        if(b.time < time) return false;
      } else {
        if(b.num != num) return false;
        if(b.time != time) return false;
      }
    } else {
      if(b.num <= num) return false;
      if(b.time <= time) return false;
    }
    state = b.state;
    num = b.num;
    time = b.time;
    return true;
  }
};

struct Team {
  string name;
  vector<Problem> p;
  int num, time, lasttime;
  int leaked ;
  void read(int n) {
    p.clear();
    leaked = 0;
    num = time = lasttime = 0;
    scanf("%s", ts);
    name = string(ts);
    for(int i = 0; i < n; i++) {
      Problem tp;
      tp.read();
      p.push_back(tp);
      if(tp.state == 1) {
        num++;
        time += tp.time + (tp.num - 1) * 20;
        lasttime = max(lasttime, tp.time);
      }
    }
    return ;
  }
  void calc() {
    num = time = lasttime = 0;
    for(auto tp : p) {
      if(tp.state == 1) {
        num++;
        time += tp.time + (tp.num - 1) * 20;
        lasttime = max(lasttime, tp.time);
      }
    }
    return ;
  }
  void add(int N) {
    for(int i = 0; i < N; i++) {
      if(p[i].state == 1) continue;
      p[i].state = 1;
      p[i].num ++;
      p[i].time = 240;
    }
    calc();
  }
  friend bool operator < (const Team& a, const Team& b) {
    if(a.num != b.num) {
      return a.num > b.num;
    }
    if(a.time != b.time) {
      return a.time < b.time;
    }
    if(a.lasttime != b.lasttime) {
      return a.lasttime < b.lasttime;
    }
    return a.name < b.name;
  }
};

Team team[maxN];
Team newteam[maxN];
map<string, int> hs;

bool work() {
  int N, M, K;
  if(scanf("%d%d%d", &N, &M, &K) != 3) return false;
  for(int i = 1; i <= M; i++) {
    team[i].read(N);
  }
  bool ok = true;
  for(int k = 1; k <= K; k++) {
    Team tt;
    tt.read(N);
    newteam[k] = tt;
    bool isfind = false;
    for(int i = 1; i <= M; i++) {
      if(tt.name == team[i].name) {
        isfind = true;
        for(int j = 0; j < N; j++) {
          if(!team[i].p[j].transfer(tt.p[j])) {
            //cout << tt.name << ' ' << j << endl;
            //tt.p[j].show();
            //team[i].p[j].show();
            ok = false;
            break;
          }
        }
        team[i] = tt;
        team[i].leaked = 1;
        break;
      }
    }
    if(!isfind) {
      ok = false;
    }
  }
  for(int i = 1; i <= M; i++) {
    if(team[i].leaked == 1) team[i].calc();
  }
  sort(team+1, team+1+M);
  //for(int i = 1; i <= M; i++) {
  //  cout << team[i].name << ' ' << team[i].leaked << ' ' << team[i].num << endl;
  //}
  int tt = 0;
  for(int i = 1; i <= M; i++){
    if(team[i].leaked == 0) {
      if(tt == 0) continue;
      else {
        team[i].add(N);
  //      cout << team[i].name << ' ' << team[i].leaked << ' ' << team[i].num << endl;
  //      cout << team[i].time << endl;
        if(team[i] < newteam[1]) continue;
        ok = false;
        break;
      }
    }
    else tt++;
    if(tt == K) break;
  }
  if(tt != K) ok = false;
  if(ok) printf("Leaked\n");
  else printf("Fake\n");
  return true;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  while(work());

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

