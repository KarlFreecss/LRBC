#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 100;

int b[100];
vector<int> xx;
void surface(int* a, int st) {
  for(int i =1; i <= 9; i++) 
    b[i] = a[st+i-1];
  a[st] = b[5];
  a[st+1] = b[7];
  a[st+2] = b[6];
  a[st+3] = b[2];
  a[st+4] = b[9];
  a[st+5] = b[8];
  a[st+6] = b[4];
  a[st+7] = b[3];
  a[st+8] = b[1];
  return ;
}
void R(int* a) {
  xx.clear();
  xx.push_back(a[45]);
  xx.push_back(a[5]);
  xx.push_back(a[6]);
  xx.push_back(a[2]);
  xx.push_back(a[3]);
  xx.push_back(a[1]);
  a[45] = a[10];
  a[5] = a[19];
  a[6] = a[21];
  a[2] = a[22];
  a[3] = a[26];
  a[1] = a[27];

  a[10] = a[59];
  a[19] = a[72];
  a[21] = a[71];
  a[22] = a[70];
  a[26] = a[69];
  a[27] = a[68];

  a[59] = xx[0];
  a[72] = xx[1];
  a[71] = xx[2];
  a[70] = xx[3];
  a[69] = xx[4];
  a[68] = xx[5];
  surface(a, 28);
}

void L(int* a) {
  xx.clear();
  xx.push_back(a[28]);
  xx.push_back(a[1]);
  xx.push_back(a[3]);
  xx.push_back(a[4]);
  xx.push_back(a[8]);
  xx.push_back(a[9]);
  a[28] = a[41];
  a[1] = a[54];
  a[3] = a[53];
  a[4] = a[52];
  a[8] = a[51];
  a[9] = a[50];

  a[41] = a[63];
  a[54] = a[23];
  a[53] = a[24];
  a[52] = a[20];
  a[51] = a[21];
  a[50] = a[19];

  a[63] = xx[0];
  a[23] = xx[1];
  a[24] = xx[2];
  a[20] = xx[3];
  a[21] = xx[4];
  a[19] = xx[5];
  surface(a, 10);
}
void U(int* a) {
  xx.clear();
  xx.push_back(a[14]);
  xx.push_back(a[9]);
  xx.push_back(a[8]);
  xx.push_back(a[7]);
  xx.push_back(a[6]);
  xx.push_back(a[5]);
  a[14] = a[55];
  a[9] = a[46];
  a[8] = a[48];
  a[7] = a[49];
  a[6] = a[53];
  a[5] = a[54];

  a[55] = a[36];
  a[46] = a[68];
  a[48] = a[69];
  a[49] = a[65];
  a[53] = a[66];
  a[54] = a[64];

  a[36] = xx[0];
  a[68] = xx[1];
  a[69] = xx[2];
  a[65] = xx[3];
  a[66] = xx[4];
  a[64] = xx[5];
  surface(a, 37);
}
void F(int *a) {
  xx.clear();
  xx.push_back(a[54]);
  xx.push_back(a[14]);
  xx.push_back(a[15]);
  xx.push_back(a[11]);
  xx.push_back(a[12]);
  xx.push_back(a[10]);
  a[54] = a[19];
  a[14] = a[28];
  a[15] = a[30];
  a[11] = a[31];
  a[12] = a[35];
  a[10] = a[36];

  a[19] = a[68];
  a[28] = a[45];
  a[30] = a[44];
  a[31] = a[43];
  a[35] = a[42];
  a[36] = a[41];

  a[68] = xx[0];
  a[45] = xx[1];
  a[44] = xx[2];
  a[43] = xx[3];
  a[42] = xx[4];
  a[41] = xx[5];
  surface(a, 1);
}

void ML(int* a) {
  xx.clear();
  xx.push_back(a[2]);
  xx.push_back(a[6]);
  xx.push_back(a[7]);
  xx.push_back(a[43]);
  xx.push_back(a[42]);
  xx.push_back(a[38]);
  a[2] = a[49];
  a[6] = a[48];
  a[7] = a[47];
  a[43] = a[58];
  a[42] = a[62];
  a[38] = a[61];

  a[49] = a[25];
  a[48] = a[26];
  a[47] = a[22];
  a[58] = a[29];
  a[62] = a[30];
  a[61] = a[31];

  a[25] = xx[0];
  a[26] = xx[1];
  a[22] = xx[2];
  a[29] = xx[3];
  a[30] = xx[4];
  a[31] = xx[5];
}

void MR(int* a) {
  xx.clear();
  xx.push_back(a[4]);
  xx.push_back(a[8]);
  xx.push_back(a[7]);
  xx.push_back(a[43]);
  xx.push_back(a[44]);
  xx.push_back(a[40]);
  a[4] = a[65];
  a[8] = a[66];
  a[7] = a[67];
  a[43] = a[56];
  a[44] = a[60];
  a[40] = a[61];

  a[65] = a[25];
  a[66] = a[24];
  a[67] = a[20];
  a[56] = a[13];
  a[60] = a[12];
  a[61] = a[11];

  a[25] = xx[0];
  a[24] = xx[1];
  a[20] = xx[2];
  a[13] = xx[3];
  a[12] = xx[4];
  a[11] = xx[5];
}
int ru[maxN];
bool ok = false;

int main() {
#ifndef ONLINE_JUDGE
  freopen("1009.in","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  rep(cas ,1 , T+1) {
    rep(i, 1, 73) scanf("%d", &ru[i]);
    //cout << endl;
    for(int i = 1; i <= 3; i++) 
    {
      MR(ru);
      //for(int i =1; i<= 72;i++) {
      //  cout << ru[i] << ' ' ;
      //  if(i%9 == 0) cout << endl;
      //}
      //cout << endl;
    }
  }

  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}

