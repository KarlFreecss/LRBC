#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+5;
int tree[MAXN];
int n, q;

void update(int x){
    while(x <= n){
        ++tree[x];
        x += x & -x;
    }
}

int getV(int x){
    int res = 0;
    while (x) {
        res += tree[x];
        x -= x & -x;
    }
    return res;
}

int row[MAXN];
vector<int> opt[MAXN];
map<pair<int, int>, int> p2n;

struct QUERY{
    int l, d, r, u;
    long long ans;
}query[MAXN];

long long table[MAXN];

int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &row[i]);
        table[i] = ((long long)i * (i - 1)) >> 1;
    }
    for (int i = 0; i < q; ++i){
        int l, d, r, u;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        long long cul = table[n] - table[l-1] - table[d-1] - table[n - u] - table[n - r];
        query[i] = (QUERY){l, d, r, u, cul};
        opt[l-1].push_back(d-1);
        opt[l-1].push_back(u);
        opt[r].push_back(d-1);
        opt[r].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        update(row[i]);
        for (int k = 0; k < opt[i].size(); ++k) {
            p2n[make_pair(i, opt[i][k])] = getV(opt[i][k]);
        }
    }
    for (int i = 0; i < q; ++i) {
        long long tot = query[i].ans;
        int ld = p2n[make_pair(query[i].l-1, query[i].d-1)];
        int lu = (query[i].l - 1) - p2n[make_pair(query[i].l-1, query[i].u)];
        int rd = (query[i].d - 1)- p2n[make_pair(query[i].r, query[i].d-1)];
        int ru = (n - query[i].r) - (query[i].u - p2n[make_pair(query[i].r, query[i].u)]);
        cout << (tot + table[ld] + table[lu] + table[rd] + table[ru]) << endl;
    }
    return 0;
}
