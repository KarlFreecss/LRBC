#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e6 + 100;

class machineState {
  public:
    long long finishTime, id;
    machineState(long long iFinishTime = 0, long long iID = 0) {
      finishTime = iFinishTime;
      id = iID;
    }
    bool operator < (const machineState & a) const {
      if (a.finishTime == finishTime) {
        return id > a.id;
      }
      return finishTime > a.finishTime;
    }
}; 

long long washFinishTime[MAXN], washCostTime[MAXN];
long long dryerFinishTime[MAXN], dryerCostTime[MAXN];
long long laundryWash[MAXN], laundryDryer[MAXN];
long long L, N, M;

int main() {
#ifndef ONLINE_JUDGE
  //freopen("B.in","r",stdin);
  //freopen("B.out", "w", stdout);
#endif
  long long T, t, res, minTime, id;
  scanf("%lld", &T);
  rep(t, 1, T + 1) {
    priority_queue<machineState> setMachine;
    //setMachine.clear();
    while (!setMachine.empty())
      setMachine.pop();
    scanf("%lld%lld%lld", &L, &N, &M);
    rep(i, 1, N + 1) {
      scanf("%lld", &washCostTime[i]);
      washFinishTime[i] = washCostTime[i];
      setMachine.push(machineState(washFinishTime[i], i));
    }
    rep(i, 1, L + 1) {
      minTime = setMachine.top().finishTime;
      id = setMachine.top().id;
      setMachine.pop();
      laundryWash[i] = minTime;
      washFinishTime[id] += washCostTime[id];
      setMachine.push(machineState(washFinishTime[id], id));
    }

//    setMachine.clear();
    while (!setMachine.empty()) 
      setMachine.pop();
    rep(i, 1, M + 1) {
      scanf("%lld", &dryerCostTime[i]);
      dryerFinishTime[i] = dryerCostTime[i];
      setMachine.push(machineState(dryerFinishTime[i], i));
    }
    rep(i, 1, L + 1) {
      minTime = setMachine.top().finishTime;
      id = setMachine.top().id;
      setMachine.pop();
      //      setMachine.erase(setMachine.begin());
      laundryDryer[i] = minTime;
      dryerFinishTime[id] += dryerCostTime[id];
      setMachine.push(machineState(dryerFinishTime[id], id));
    }
    res = 0;
    rep(i, 1, L + 1) {
      res = max(res, laundryWash[i] + laundryDryer[L + 1 - i]);
    }
    printf("Case #%d: %lld\n", t, res);
  }
  return 0;
}

