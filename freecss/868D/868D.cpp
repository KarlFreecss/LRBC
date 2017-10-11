#include<bits/stdc++.h>

using namespace std;

vector<string> str(1);
vector<int> ans(1);

int solve(const string & s){
    for (int len = 1; len <= 10; ++len) {
        for (int opt = 0; opt < (1 << len); ++opt) {
            bitset<10> bits(opt);
            string tmpS(len, '0');
            for (int i = 0; i < len; ++i) {
                tmpS[i] += bits[i];
            }
            if (s.find(tmpS) == string::npos) {
                return len - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char buff[256];
        scanf("%s", buff);
        str.push_back(buff);
        ans.push_back(solve(str.back()));
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        str.push_back(str[a] + str[b]);
        if (str.back().length() > 1000) {
            str.back() = str.back().substr(0, 500) + str.back().substr(str.back().length() - 500, 500);
        }
        ans.push_back(max({solve(str.back()), ans[a], ans[b]}));
        cout << ans.back() << endl;
    }
    return 0;
}
