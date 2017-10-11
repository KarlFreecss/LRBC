#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAXB = 11;
const int MAXL = 64;
const int MAXOPT = (1 << 11);

ull f[MAXB][MAXL][MAXOPT];
ull g[MAXB][MAXL][MAXOPT];

void init(){
    for (int b = 2; b <= 10; ++b) {
        f[b][0][0] = 1;
        ull B = b;
        for (int l = 1; l < 64; ++l) {
            B *= b;
            for (int num = 0; num < b; ++num) { 
                for (int opt = 0; opt < (1 << b); ++opt) {
                    f[b][l][opt] += f[b][l-1][opt ^ (1 << num)];
                }
            }
            for (int opt = 0; opt < (1 << b); ++opt) {
                for (int num = 1; num < b; ++num) { 
                    g[b][l][opt] += f[b][l-1][opt ^ (1 << num)];
                  //  cout << b << ' ' << l << ' ' << opt << " =  " << g[b][l][opt] << endl;
                }
                g[b][l][opt] += g[b][l-1][opt];
            }
            if (B > 1e18) break;
        }
    }
}

void getBase(ll n, int b, int &l, int s[]){
    if (n == 0) {
        s[(l = 0)] = 0;
        l++;
        return ;
    }
    if (n/b) getBase(n/b, b, l, s);
    else l = 0;
    s[l++] = n%b;
}

ll cul(const ll n, const int b){
    int num[64];
    int l = 0;
    getBase(n, b, l, num);
 
    for (int i = 0; i * 2 < l; ++i) {
        swap(num[i], num[l-i-1]);
    }
    //cout << "len = " << l << endl;
   int mask = 0;//1 << num[l-1];
    ull res = g[b][l-1][0];
    //cout << "res = " << res << endl;
    for (int i = l-1; i >= 0; --i) {
       // cout << "num[i] = " << num[i] << endl;
        for (int k = 0; k < num[i]; ++k) {
            //cout << "f[" << b << "][" << i << "][" << (mask^(1<<k)) << "]=" << f[b][i][mask ^ (1<<k)] << ' ' << mask << endl;
            if (i + 1 == l && k == 0) continue;
            res += f[b][i][mask ^ (1<<k)];
 //           cout << i << ' ' << k << ' ' << res << endl;
        }
       //cout << "mask = " << mask << " res = " << res << endl;
        mask ^= (1 << num[i]);
    }
    if (mask == 0) ++res;
    //cout << res << endl;
    return res;
}

int main(){
 /*   for (int i = 1; i < 114; ++i) {
        int num[33];
        int l;
        getBase(i, 4, l, num);
        for (int j = 0; j < l; ++j) {
            cout << num[j];
        } cout << endl;
    }*/
    init();

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        ll b, l, r;
        scanf("%lld%lld%lld", &b, &l, &r);
        printf("%lld\n", cul(r, b) - cul(l-1, b));
    }
    return 0;
}
