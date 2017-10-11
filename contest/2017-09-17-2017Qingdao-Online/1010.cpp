#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

const int MAXN = 2e5;

int n;
int a[MAXN], nex[MAXN], pre[MAXN];
int deleted[MAXN];

set<int> S;

void delOpt(const vector<int> & opt, vector<int> & tmp){
    tmp.clear();
    S.clear();
    for (int i = 0; i < opt.size(); ++i) {
        if (deleted[opt[i]]) continue;
        int k = nex[opt[i]];
        int del = 0;
        if (k != -1) {
            if (a[opt[i]] > a[k]) {
                del = 1;
            }
        }

        k = pre[opt[i]];
        if (k != -1) {
            if (a[opt[i]] < a[k]) {
                del = 1;
            }
        }

        if (del) {
            int k = nex[opt[i]];
            if (k != -1)
              S.insert(k);
            k = pre[opt[i]];
            if (k != -1)
              S.insert(k);
            deleted[opt[i]] = 1;
        }
    }

    for (auto itor = S.begin(); itor != S.end(); ++itor) {
        tmp.push_back(*itor);
        //cout << *itor << endl;
    }

    for (int i = 0; i < tmp.size(); ++i) {
        int nex_ = nex[tmp[i]];
        int pre_ = pre[tmp[i]];
        if (nex_ != -1) {
            pre[nex_] = pre_;
        }
        if (pre_ != -1) {
            nex[pre_] = nex_;
        }
    }
}

void work(int id){
    int n;
    scanf("%d", &n);
    vector<int> opt;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        nex[i] = i + 1;
        pre[i] = i - 1;
        opt.push_back(i);
        deleted[i] = 0;
    }
    pre[1] = -1;
    nex[n] = -1;

    vector<int> tmp;
    while (opt.size() > 0) {
        delOpt(opt, tmp);
        opt = tmp;
     //   for (int i = 0; i < tmp.size(); ++i) {
     //       cout << tmp[i] << ' ';
     //   } cout << endl;
    }
    int tot = n;
    for (int i = 1; i <= n; ++i) {
        if (deleted[i]) --tot;
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i) {
        if (!deleted[i]) printf("%d ", a[i]);
    }
    printf("\n");
    /*printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");*/
}

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        work(i);
    }
    return 0;
}

