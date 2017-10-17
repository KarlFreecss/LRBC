#include<bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long a, b;
    int ans = 1;
    cin >> a >> b;
    unsigned long long k = b - a;
    if (k > 10) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= min(k, 10ull); ++i) {
        ans = (ans * (a % 10 + i)) % 10;
    }
    cout << ans << endl;
    return 0;
}
