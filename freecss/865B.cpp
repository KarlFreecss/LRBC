#include<bits/stdc++.h>

using namespace std;

struct PIZ{
    int d, s, a, b;
};

bool operator <(const PIZ &A, const PIZ &B){
    return A.d > B.d;
}

vector<PIZ> piz;

long long ans = 0;

long long getS(const vector<PIZ> & piz, long long k, long long s){
    long long sumS = 0;
    if (k > piz.size()) k = piz.size();
    for (int i = 0; i < k; ++i) {
        sumS += piz[i].s;
    }
    return s * ((sumS - 1) / s + 1);
}

long long cul(const vector<PIZ> & piz, long long s, const long long del){
    long long res = 0;
    //cout << s << ' ' ;
    for (int i = 0; i < piz.size(); ++i) {
        if (piz[i].d < 0) {
            s -= del;
            s = max(0ll, s);
        }
        long long left, right;
        if (s > piz[i].s) {
            left = 0;
            right = piz[i].s;
        } else {
            left = piz[i].s - s;
            right = s;
        }
        res += right * piz[i].a + left * piz[i].b;
        s -= right;
        //cout << s << ' ';
    }
    //cout << res << ' ' << del << endl;
    return res;
}

int main(){
    int N, S;
    scanf("%d%d", &N, &S);
    long long sumS = 0;
    for (int i = 0; i < N; ++i) {
        int s, a, b;
        scanf("%d%d%d", &s, &a, &b);
        piz.push_back((PIZ){a - b, s, a, b});
        sumS += s;
    }
    sort(piz.begin(), piz.end());
    int k = 0;
    for (;k < piz.size(); ++k) {
        if (piz[k].d < 0) break;
    }
    long long totS = ((sumS - 1) / S + 1) * S - sumS;
    //cout << totS << ' ' << sumS << endl;
    long long tmpS;
    tmpS = getS(piz, k, S);
    long long tmp1 = max({cul(piz, tmpS, totS), cul(piz, tmpS+S, totS), cul(piz, tmpS-S, totS)});

    tmpS = getS(piz, k-1, S);
    long long tmp2 = max({cul(piz, tmpS, totS), cul(piz, tmpS+S, totS), cul(piz, tmpS-S, totS)});
    
    tmpS = getS(piz, k+1, S);
    long long tmp3 = max({cul(piz, tmpS, totS), cul(piz, tmpS+S, totS), cul(piz, tmpS-S, totS)});
    cout << max({tmp1, tmp2, tmp3}) << endl;
    return 0;
}
