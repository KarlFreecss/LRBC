#include <bits/stdc++.h>

using namespace std;

int main(){
	int L, B;
	cin >> L >> B;
	for (int i = 1; i; ++i) {
		L *= 3;
		B *= 2;
		if (L > B) {
			cout << i << endl;
			break;
		}
	}		
	return 0;
} 
