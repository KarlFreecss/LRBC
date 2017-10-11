#include <bits/stdc++.h>
using namespace std;

const int MO = 1e9+7;

int n, L, M;

vector<int> a, b, c;

vector<int> dot(const vector<int> & a, const vector<int> & b){
    vector<int> c(a.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[(i+j)%M] += (long long)a[i] * b[j] % MO;
            c[(i+j)%M] %= MO;
        }
    }
    return c;
}

vector<int> powerM(const vector<int> &B, const int n){
    vector<int> res(B.size());
    res[0] = 1;
    if (n == 0) return res;
    if (n == 1) return B;
    res = powerM(B, n/2);
    res = dot(res, res);
    if (n&1) {
        res = dot(res, B);
    }
    return res;
}

int main(){
    scanf("%d%d%d", &n, &L, &M);
    a.resize(M);
    b.resize(M);
    c.resize(M);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        ++a[t%M];
    }
    vector<int> tt(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tt[i]);
        ++b[tt[i]%M];
    }
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        ++c[(tt[i] + t)%M];
    }
    vector<int> res = powerM(b, L-2); 
    res = dot(a, res);
    res = dot(res, c);
    cout << res[0] << endl;
    return 0;
}
