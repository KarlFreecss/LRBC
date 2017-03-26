#include <bits/stdc++.h>



using namespace std;

set<int> S;

int main(){
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 100000; ++i) {
		S.insert(b + i * a);
	}

	int flag = 0;
	int c, d;
	cin >> c >> d;
	for (int i = 0; i < 100000; ++i) {
		if (S.find(d + c * i) != S.end()) {
			cout << d + c*i << endl;
			return 0;
		}
	}
	
	cout << "-1" << endl;

	return 0;
} 
