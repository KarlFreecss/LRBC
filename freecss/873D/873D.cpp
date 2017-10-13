#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;

int a[MAXN];

#define debug() cerr << __LINE__ << " " 

int work(int * a, int base, int l, int r, int k){
 //   debug() << base << ' '<< l << ' ' << r << ' ' << k << endl;
    if (k % 2 == 0) return 0;
    if (k == 1) {
        for (int i = l; i < r; ++i) {
            a[i] = i + base - l;
        }
        return 1;
    }
    if (l+1 == r) return 0;
    k -= 1;
    int lk = k / 2;
    if (!(lk&1)) ++lk;
    int rk = k - lk;
    int mid = (l + r) >> 1;
    if (mid - l < r - mid) {
        if (rk < lk) swap(rk, lk);
    }
    return work(a, base + (r - mid), l, mid, lk) && 
        work(a, base, mid, r, rk);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int flag = work(a, 0, 0, n, k);
    if (!flag) {
        puts("-1");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%d%c", a[i]+1, i+1==n?'\n':' ');
        }
    }
    return 0;
}

//
// 2 0 1
// 2    1 0
// 2    1   0
