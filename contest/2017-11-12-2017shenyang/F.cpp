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

string ans[100] = {
"4",
"14",
"52",
"194",
"724",
"2702",
"10084",
"37634",
"140452",
"524174",
"1956244",
"7300802",
"27246964",
"101687054",
"379501252",
"1416317954",
"5285770564",
"19726764302",
"73621286644",
"274758382274",
"1025412242452",
"3826890587534",
"14282150107684",
"53301709843202",
"198924689265124",
"742397047217294",
"2770663499604052",
"10340256951198914",
"38590364305191604",
"144021200269567502",
"537494436773078404",
"2005956546822746114",
"7486331750517906052",
"27939370455248878094",
"104271150070477606324",
"389145229826661547202",
"1452309769236168582484",
"5420093847118012782734",
"20228065619235882548452",
"75492168629825517411074",
"281740608900066187095844",
"1051470266970439230972302",
"3924140458981690736793364",
"14645091568956323716201154",
"54656225816843604128011252",
"203979811698418092795843854",
"761263020976828767055364164",
"2841072272208896975425612802",
"10603026067858759134647087044",
"39571031999226139563162735374",
"147681101929045799118003854452",
"551153375716957056908852682434",
"2056932400938782428517406875284",
"7676576228038172657160774818702" };

char s[100];

void work() {
  scanf("%s", s);
  string ss = (string)s;
  for(int i = 0; i < 54; i++) {
    if(ans[i].length() > ss.length()) {
      printf("%s\n", ans[i].c_str()) ;
      return ;
    }
    if(ans[i].length() == ss.length()) {
      if(ans[i] >= ss) {
        printf("%s\n", ans[i].c_str()) ;
        return ;
      }
    }
  }
  return ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("F.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    work();
  }
  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}
