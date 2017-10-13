#include<bits/stdc++.h>

using namespace std;
int n;
string str;
int sum_l[205][26];
int sum_u[205];

int main(){
    cin >> n;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') ++sum_l[i+1][str[i] - 'a'];
        else ++sum_u[i+1];
    }
    for (int i = 1; i <= str.size(); ++i) {
        for (int k = 0; k < 26; ++k) {
            sum_l[i][k] += sum_l[i-1][k];
        }
        sum_u[i] += sum_u[i-1];
    }
    int ans = 0;
    for (int l = 0; l < str.size(); ++l) {
        for (int r = l; r < str.size(); ++r) {
            int flag = 1;
            if (sum_u[r+1] - sum_u[l] > 0) continue;
            set<int> s;
            for (int i = l; i <= r; ++i) {
                s.insert(str[i]);
            }
            if (flag) ans = max(ans, (int)s.size());
        }
    }
    cout << ans << endl;
    return 0;
}
