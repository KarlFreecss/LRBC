#include <bits/stdc++.h>

using namespace std;

map<string, int> dic;
set<string> exist;

char tmp[256];

int dfs(char * str, int index, char * now, int l){
    if (str[index] == '\0') {
        now[l] = '\0';
        if (exist.count(now)) return 0;
        exist.insert(now);
        return dic[now];
    }

    if (str[index] != '?') {
        now[l] = str[index];
        return dfs(str, index+1, now, l+1);
    } else {
        int sum = dfs(str, index+1, now, l);
        for (char c = 'a'; c <= 'e'; ++c) {
            now[l] = c;
            sum += dfs(str, index+1, now, l+1);
        }
        return sum;
    }
    return 0;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    char buff[64];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buff);
        ++dic[buff];
    }

    for (int i = 0; i < q; ++i) {
        exist.clear();
        scanf("%s", buff);
        cout << dfs(buff, 0, tmp, 0) << endl;
    }

    return 0;
}
