#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int t;
    scanf("%d", &n);
    int maxR = 25;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        maxR = max(maxR, t);
    }
    printf("%d\n", maxR - 25);
    return 0;
}
