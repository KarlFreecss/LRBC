#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> store;
    map<int, int> dic;
    int c;
    int ans = 0;
    store.push_back(0);
    dic[0] = 0;
    for (int i = 1; i <= n; ++i) {
        c = getchar();
        if (c != '1' && c != '0') {
            --i;
            continue;
        }
        int lastV = store.back();
        int d = c == '1' ? 1 : -1;
        store.push_back(lastV + d);
        if (dic.count(store.back())) {
            ans = max(ans, i - dic[store.back()]);
        } else {
            dic[store.back()] = i;
        }
    }
    cout << ans << endl;
    return 0;
}
