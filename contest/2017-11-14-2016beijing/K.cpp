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

const int MAX_I = 83;
const int MAXLEN = 200;

long long a[200];
char s[MAXLEN];
long long n;

int main() {
#ifndef ONLINE_JUDGE
  freopen("K.in","r",stdin);
#endif
a[1] = 1;
a[2] = 199981;
a[3] = 199982;
a[4] = 199983;
a[5] = 199984;
a[6] = 199985;
a[7] = 199986;
a[8] = 199987;
a[9] = 199988;
a[10] = 199989;
a[11] = 199990;
a[12] = 200000;
a[13] = 200001;
a[14] = 1599981;
a[15] = 1599982;
a[16] = 1599983;
a[17] = 1599984;
a[18] = 1599985;
a[19] = 1599986;
a[20] = 1599987;
a[21] = 1599988;
a[22] = 1599989;
a[23] = 1599990;
a[24] = 2600000;
a[25] = 2600001;
a[26] = 13199998;
a[27] = 35000000;
a[28] = 35000001;
a[29] = 35199981;
a[30] = 35199982;
a[31] = 35199983;
a[32] = 35199984;
a[33] = 35199985;
a[34] = 35199986;
a[35] = 35199987;
a[36] = 35199988;
a[37] = 35199989;
a[38] = 35199990;
a[39] = 35200000;
a[40] = 35200001;
a[41] = 117463825;
a[42] = 500000000;
a[43] = 500000001;
a[44] = 500199981;
a[45] = 500199982;
a[46] = 500199983;
a[47] = 500199984;
a[48] = 500199985;
a[49] = 500199986;
a[50] = 500199987;
a[51] = 500199988;
a[52] = 500199989;
a[53] = 500199990;
a[54] = 500200000;
a[55] = 500200001;
a[56] = 501599981;
a[57] = 501599982;
a[58] = 501599983;
a[59] = 501599984;
a[60] = 501599985;
a[61] = 501599986;
a[62] = 501599987;
a[63] = 501599988;
a[64] = 501599989;
a[65] = 501599990;
a[66] = 502600000;
a[67] = 502600001;
a[68] = 513199998;
a[69] = 535000000;
a[70] = 535000001;
a[71] = 535199981;
a[72] = 535199982;
a[73] = 535199983;
a[74] = 535199984;
a[75] = 535199985;
a[76] = 535199986;
a[77] = 535199987;
a[78] = 535199988;
a[79] = 535199989;
a[80] = 535199990;
a[81] = 535200000;
a[82] = 535200001;
a[83] = 1111111110;

  while (cin >> s) {
//    cout << s << endl;
    int len = strlen(s);
    if (len >= 12) {
      cout << MAX_I << " " << a[MAX_I] << endl;
      //printf("%I64d %I64d\n", MAX_I, a[MAX_I]);
      continue;
    }
    long long n = 0;
    for (int i = 0; i < len; i ++) {
      n *= 10;
      n += s[i] - '0';
    }
    for (long long i = MAX_I; i >= 1; i --) {
      if (n >= a[i]) {
        cout << i << " " << a[i] << endl;
        //printf("%I64d %I64d\n", i, a[i]);
        break;
      }
    }
  }
//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

