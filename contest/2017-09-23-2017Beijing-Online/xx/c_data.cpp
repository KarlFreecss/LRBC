#include<bits/stdc++.h>

using namespace std;

int main(){
	int T = 1;
	srand(time(0));
	//printf("%d\n", T);
	for (int i = 0; i < T; ++i) {
		int n = rand()%3 + 1;
		int m = rand()%3 + 1;
		int P = rand()%20 - 10;
		printf("%d %d %d\n", n, m, P);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%d ", rand()%20 - 1);
			} printf("\n");
		}
	}
	return 0;
}
