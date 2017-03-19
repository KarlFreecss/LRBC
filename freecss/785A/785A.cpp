#include <bits/stdc++.h>

using namespace std;

map<string, int> dic; 

int main(){
	dic["Tetrahedron"] = 4;
	dic["Cube"] = 6;
	dic["Octahedron"] = 8;
	dic["Dodecahedron"] = 12;
	dic["Icosahedron"] = 20;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ans += dic[s];
	}	 
	cout << ans << endl;

	return 0;
} 
