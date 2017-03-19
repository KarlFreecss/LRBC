#include <bits/stdc++.h>

using namespace std;

int n, m;
int cl, cr, pl, pr;

int main(){
	int n;
	cin >> n;
	cl = -1;
	cr = 0x7fffffff;
	pl = -1;
	pr = 0x7fffffff;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		if (r < cr) cr = r;
		if (l > cl) cl = l;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		if (r < pr) pr = r;
		if (l > pl) pl = l;
	}	

	int ans = pl - cr;
	if (ans < cl - pr) ans = cl - pr;
	if (ans < 0) ans = 0;

	//cout << cl << ' ' << cr << ' ' << pl << ' ' << pr << endl;


	cout << ans << endl;

	return 0;
} 