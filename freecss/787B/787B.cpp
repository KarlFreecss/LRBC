#include <bits/stdc++.h>


using namespace std;

set<int> S;
vector<int> V;

int main(){
	int n, m;
	cin >> n >> m;

	int flag = 0;
	for (int i = 0; i < m; ++i) {
		S.clear();
		V.clear();
		int k;
		scanf("%d", &k);
		int mark = 0;
		for (int i = 0; i < k; ++i) {
			int a;
			cin >> a;
			S.insert(a);
			V.push_back(a);
		}
		for (int i = 0; i < V.size(); ++i) {
			if (S.find(-V[i]) != S.end()) mark = 1;
		}
		if (!mark) flag = 1;
	}
	if (flag) puts("YES");
	else puts("NO");

	return 0;
} 
