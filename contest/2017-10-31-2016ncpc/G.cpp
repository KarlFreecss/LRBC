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


const int MAXL = 1e4 + 5;
char his[MAXL];

int needStarsNum(int level){
  if (level > 20) return 2;
  if (level > 15) return 3;
  if (level > 10) return 4;
  if (level > 0) return 5;
}

void changeLevel(int & level, int & stars, const int score){
  if (level > 20 && score < 0) return;
  if (level == 20 && score < 0) {
    --stars;
    if (stars < 0) stars = 0;
    return;
  }
  if (level == 0) return;
  if (score > 0){
    stars += score;
    if (stars > needStarsNum(level)) {
      stars = stars - needStarsNum(level);
      level--;
    }
  } else {
    stars += score;
    if (stars < 0) {
      ++level;
      stars = needStarsNum(level) - 1;
    }
  }
}

int work(){
  int tmp = scanf("%s", his);
  if (tmp != 1) return 0;
  int len = strlen(his);
  int stars, level;
  stars = 0;
  level = 25;
  int cont = 0;
  for (int i = 0; i < len; ++i){
    if (his[i] == 'W') {
      cont++;
      changeLevel(level, stars, 1 + (cont >= 3 && level > 5));
    } else {
      cont = 0;
      changeLevel(level, stars, -1);
    }
 //     cout << i << ' ' << level <<' ' << stars << endl;
  }
  if (level > 0) printf("%d\n", level);
  else puts("Legend");
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("G.in","r",stdin);
#endif
  while (work());
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

