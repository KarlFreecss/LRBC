#include<bits/stdc++.h>

using namespace std;

unordered_set<int> S(65536);

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        S.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; 
        S.insert(b[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            if (S.count(a[i] ^ b[j])) ++ans;
    }
    if (ans&1) {
        puts("Koyomi");
    } else {
        puts("Karen");
    }
    return 0;
}
