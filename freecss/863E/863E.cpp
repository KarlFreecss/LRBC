#include<bits/stdc++.h>

using namespace std;

struct SEG{
    int l, r, id;
};

int operator<(const SEG&A, const SEG&B){
    if (A.l != B.l) return A.l < B.l;
    return A.r < B.r;
}

vector<SEG> seg;

map<int, int> cnt;
map<int, int> pref;

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        cnt[l]++;
        cnt[r+1]--;
        cnt[r] = cnt[r];
        cnt[l-1] = cnt[l-1];
        seg.push_back((SEG){l, r, i+1});
    }
    int sum = 0;
    int onlyOne = 0;
    for (auto x : cnt) {
        sum += x.second;
        x.second = sum;
        if (sum == 1) {
            onlyOne++;
        }
        pref[x.first] = onlyOne;
    }

    for (int i = 0; i < n; ++i){
        if (pref[seg[i].r] - pref[seg[i].l-1] == 0) {
            cout << seg[i].id << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
    
