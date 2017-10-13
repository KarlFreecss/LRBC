#include<bits/stdc++.h>

using namespace std;

map<int, int> M;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;
        M[t]++;
    }
    int flag = 1;
    if (M.size() != 2) {
        flag = 0;
    }
    auto itor = M.begin();
    if (itor->second * 2 != n) flag = 0;
    if (flag) {
        cout << "YES" << endl;
        cout << itor->first;
        ++itor;
        cout << ' ' << itor->first << endl;
    } else puts("NO");
    return 0;
}
