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

char buff[1000];

int main() {
#ifndef ONLINE_JUDGE
  freopen("D.in","r",stdin);
#endif
  int N;
  while(scanf("%s %d", buff, &N) != EOF) {
    //cout << buff << ' ' << N << endl;
    int ta = 0;
    if(strlen(buff) == 1) {
      if(buff[0] == '0') break;
      ta = buff[0] - '0';
    } else if(buff[1] == 'x') {
      sscanf(buff, "%x", &ta);
    } else if(buff[0] == '0') {
      sscanf(buff, "%o", &ta);
    } else {
      sscanf(buff, "%d", &ta);
    }
    int mark = 0;
    int lans = ta;
    //cout << mark << ' ' << ta << endl;
    rep(i, 1, N+1) {
      scanf("%s %d", buff, &ta);
      string sbuff = string(buff, strlen(buff));
      if(sbuff.length() == 1) {
        if(ta == lans) mark ++;
        lans = ta;
      }
      if(sbuff.length() == 3) {
        if(sbuff[0] == 'i') { // i++ or i--
          if(ta == lans) mark++;
          if(sbuff[1] == '+') { // i++
            lans = ta + 1;
          } else { // i--
            lans = ta -1;
          }
        } else { //++i or --i
          if(sbuff[0] == '+') { //++i
            if(ta == lans + 1) mark++;
            lans = ta;
          } else { // --i
            if(ta == lans - 1) mark++;
            lans = ta;
          }
        }
      }
      //cout << i << ' ' << lans << ' ' << mark <<  endl;
    }
    printf("%d\n", mark) ;
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

