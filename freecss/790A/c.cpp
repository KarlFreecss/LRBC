#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<string> name;

string getName(int i){
		char c = i + 65;
		if (i >= 26) {
			i -= 26;
			return string("") + (char)(i + 65) + (char)(i + 97);
		}
		else return string("") + c;
}

int main(){
	cin >> n >> k;
	for (int i = 0; i < k-1; ++i) {
		name.push_back(getName(i));
	}
	string tmp;
	for (int i = k-1; i < n; ++i) {
		cin >> tmp;
		if (tmp == "YES") name.push_back(getName(i));
		else name.push_back(name[i-k+1]);
	}
	for (int i = 0; i < n; ++i) {
		cout << name[i] << "  "[i+1 == n];
	}
	return 0;
} 
