#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int a = 0, b = 0;
    while (x.size()){
        if (a < b) a += x.back();
        else b += x.back();
        x.pop_back();
    }
    cout << min(a,b) << ' ' << max(a,b) << endl;
    return 0;
}
