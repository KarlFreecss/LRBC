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

class line {
  public:
    long long x, y;
    char val;
    line(long long iX = 0, long long iY = 0, char iVal = 'a') {
      x = iX;
      y = iY;
      val = iVal;
    }
};


void toDeal(vector<line> &state) {
  vector<line> tmp;
  tmp.clear();
  for (int i = 0; i < state.size(); i ++) {
    if (state[i].x <= state[i].y) {
      tmp.push_back(state[i]);
    }
  } 
  state = tmp;
}
void toOperate(vector<line> &state) {
  vector<line> tmp;
  char op, val;
  long long pos, sum;
  state.clear();
  long long maxPos = 1e18 + 5000;
  state.push_back(line(1, maxPos, 'a'));
  while (true) {
    cin >> op;
    sum = 0;
    if (op == 'E')
      break;
    if (op == 'D') {
      cin >> pos;
      int index;
      for (int i = 0; i < state.size(); i ++) {
        long long len = (state[i].y - state[i].x + 1);
        if (pos <= len) {
          index = i;
          break;
        }
        pos -= len;
      }
      tmp.clear();
      for (int i = 0; i < index; i ++) {
        tmp.push_back(state[i]);
      }
      tmp.push_back(line(state[index].x, state[index].x + pos - 2, state[index].val));
      tmp.push_back(line(state[index].x + pos, state[index].y, state[index].val));
      for (int i = index + 1; i < state.size(); i ++) {
        tmp.push_back(state[i]);
      }
      state = tmp;
      toDeal(state);
    } else if (op == 'I') {
      cin >> pos >> val;
      int index;
      for (int i = 0; i < state.size(); i ++) {
        long long len = (state[i].y - state[i].x + 1);
        if (pos <= len) {
          index = i;
          break;
        }
        pos -= len;
      }
      tmp.clear();
      for (int i = 0; i < index; i ++)
        tmp.push_back(state[i]);
      tmp.push_back(line(state[index].x, state[index].x + pos - 2, state[index].val));
      tmp.push_back(line(1, 1, val));
      tmp.push_back(line(state[index].x + pos - 1, state[index].y, state[index].val));
      for (int i = index + 1; i < state.size(); i ++)
        tmp.push_back(line(state[i].x, state[i].y, state[i].val));
      state = tmp;
      toDeal(state);
    }
  }
  tmp.clear();
  tmp.push_back(state[0]);
  for (int i = 1; i < state.size(); i ++) {
    if (tmp[tmp.size() - 1].val == 'a' && state[i].val == 'a' && tmp[tmp.size() - 1].y == state[i].x - 1) {
      tmp[tmp.size() - 1].y = state[i].y;
    } else {
      tmp.push_back(state[i]);
    }
  }
  state = tmp;
}
bool work() {
  vector<line> state1;
  vector<line> state2;
  toOperate(state1);
  toOperate(state2);
  
  /*
  cout << "state1 = " << endl;
  for (int i = 0; i < state1.size(); i ++)
    cout << state1[i].x << " " << state1[i].y << " " << state1[i].val << endl;
  cout << "state2 = " << endl;
  for (int i = 0; i < state2.size(); i ++)
    cout << state2[i].x << " " << state2[i].y << " " << state2[i].val << endl;
  */

  if (state1.size() != state2.size()) {
    printf("1\n");
  } else {
    for (int i = 0; i < state1.size(); i ++) {
      if (state1[i].x != state2[i].x || state1[i].y != state2[i].y || state1[i].val != state2[i].val) {
        printf("1\n");
        return true;
      }
    }
    printf("0\n");
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("I.in","r",stdin);
#endif

  for (int i = 0; i < 6; i ++)
    work();

  return 0;
}

