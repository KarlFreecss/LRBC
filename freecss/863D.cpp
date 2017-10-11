#include<bits/stdc++.h>

using namespace std;

int read(){
    int x=0;char ch=getchar();
    for (;!isdigit(ch);ch=getchar());
    for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x;
}

const int MAXN = 2e5+5;
const int MAXM = 105;

int a[MAXN];
int b[MAXM];
int opt[MAXN], l[MAXN], r[MAXN];

int main(){
    int n, q, m;
    scanf("%d%d%d", &n, &q, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; ++i){
        scanf("%d%d%d", &opt[i], &l[i], &r[i]);
    }

    for (int i = 0; i < m; ++i){
        scanf("%d", &b[i]);
    }

    for (int i = q-1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (l[i] <= b[j] && r[i] >= b[j]) {
                if (opt[i] == 1) {
                    if (b[j] == l[i]) b[j] = r[i];
                    else b[j] = b[j] - 1;
                } else {
                    int d = b[j] - l[i];
                    b[j] = r[i] - d;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d%c", a[b[i]-1], i+1==m?'\n':' ');
    }
    return 0;
}
