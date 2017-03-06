#include <bits/stdc++.h>

#define DEBUG printf("DEBUG %d\n", __LINE__)

using namespace std;

const int MAXN = 1e3+3;
map<string, int> team;
map<string, int> nameCount;
vector<vector<string> > name;
string firstOpt[MAXN];
string secondOpt[MAXN];
string ans[MAXN];
int vis[MAXN];

int mark[MAXN];
int n;

int match(int t){
	if (vis[t]) return 0;
	vis[t] = 1;
	for (int i = 0; i < name[t-1].size(); ++i){
		string x = name[t-1][i];
		if (team[x] == 0 || match(team[x])) {
			team[x] = t;
			ans[t] = x;
			return 1;
		}
	}
	return 0;
}

int work(){
	if (scanf("%d", &n) != 1) return 0;
	for (int i = 1; i <= n; ++i) {
		string name, town;
		cin >> name >> town;
		firstOpt[i] = name.substr(0, 3);
		secondOpt[i] = name.substr(0,2) + town.substr(0,1);
		++nameCount[firstOpt[i]];
	}
	name.clear();
	for (int i = 1; i <= n; ++i) {
		vector<string> tName;
		if (nameCount[firstOpt[i]] == 1) tName.push_back(firstOpt[i]);
		tName.push_back(secondOpt[i]);
		name.push_back(tName);		
	}
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (!match(i)) {
			puts("NO");
			return 1;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << "\n";
	}

	return 1;
}

int main(){
	while (work());
	return 0;
}
