#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> que;
int n;

int main(){
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        que.push(t);
        int low = que.top();
        if (low < t) {
            que.pop();
            ans += t - low;
            que.push(t);
        }
    }
    cout << ans << endl;
    return 0;
}
